#include "Plant.h"
#include "Debug.h"
#include "PvZScene.h"
#include "Projectile.h"
#include "Zombie.h"

#include <string>

void Plant::Shoot()
{
	if (m_bullet <= 0)
		return;
	if (m_powerShoot == true)
	{
		
		float projectileRadius = GetRadius() * 0.3f;
		sf::Vector2f projectilePos = GetPosition();

		Projectile* p = CreateEntity<Projectile>(projectileRadius, sf::Color::Magenta);
		p->SetPosition(projectilePos.x, projectilePos.y);

		--m_bullet;
		m_powerShoot = false;
		return;
	}

	float projectileRadius = GetRadius() * 0.1f;
	sf::Vector2f projectilePos = GetPosition();

	Projectile* p = CreateEntity<Projectile>(projectileRadius, sf::Color::Cyan);
	p->SetPosition(projectilePos.x, projectilePos.y);

	--m_bullet;
}

void Plant::Reload()
{
	m_bullet = m_capacity;
}

void Plant::OnInitialize()
{
	m_bullet = m_capacity = 6;
	m_PStimer = 3.f;
	m_powerShoot = false;
	m_ZoneDZombie = false;

	SetTag((int)PvZScene::Tag::Plant);

	m_stateMachine.AddState(new IdlePLantState());
	m_stateMachine.AddState(new ShootingPLantState());
	m_stateMachine.AddState(new ReloadingPLantState());
}

void Plant::OnUpdate()
{
	std::string text = std::to_string(m_bullet) + "/" + std::to_string(m_capacity);

	sf::Vector2f pos = GetPosition();

	Debug::DrawText(pos.x, pos.y, text, 0.5f, 0.5f, sf::Color::Blue);
	Debug::DrawText(pos.x, pos.y - 50, StateToStr(), 0.5f, 0.5f, sf::Color::Blue);

	if (m_powerShoot == false)
	{
		m_PStimer -= GetDeltaTime();
	}
	m_stateMachine.Update(this, GetDeltaTime());
}


const char* Plant::StateToStr() const 
{
	switch ((State)m_stateMachine.GetState()) 
	{
	case State::Idle:
		return "Idle";
	case State::Shooting:
		return "Shooting";
	case State::Reloading:
		return "Reloading";
	}
}

void IdlePLantState::Start(Plant* type)
{

}

void IdlePLantState::Update(Plant* type, float dt)
{
	//Transition -> Reloading
	if (type->m_bullet <= 0)
	{
		type->m_stateMachine.TryTransitionTo(type, (int)Plant::State::Reloading);
		return;
	}

	//Transition -> Shooting
	PvZScene* scene = type->GetScene<PvZScene>();

	int laneIndex = scene->GetLaneIndex(type->GetPosition().y);

	bool isZombieOnLane = scene->IsZombieOnLane(laneIndex);
	type->m_ZoneDZombie = scene->GetPosZombieOnLane(laneIndex, 666);

	if (isZombieOnLane) 
	{
		if (type->m_PStimer <= 0 && type->m_ZoneDZombie == true)
		{
			type->m_powerShoot = true;
			type->m_PStimer = 3.f;
		}
		type->m_stateMachine.TryTransitionTo(type, (int)Plant::State::Shooting);
		return;
	}
	
	//Transition -> Reloading
	if (type->m_bullet < type->m_capacity)
	{
		type->m_stateMachine.TryTransitionTo(type, (int)Plant::State::Reloading);
		return;
	}
}

void IdlePLantState::End(Plant* type)
{
}

void ShootingPLantState::Start(Plant* type)
{
	type->Shoot();
	m_timer = 0.5f;
}

void ShootingPLantState::Update(Plant* type, float dt)
{
	m_timer -= dt;
	if (m_timer > 0)
		return;

	type->m_stateMachine.TryTransitionTo(type, (int)Plant::State::Idle);
}

void ShootingPLantState::End(Plant* type)
{
}

void ReloadingPLantState::Start(Plant* type)
{
	m_timer = 1.f;
}

void ReloadingPLantState::Update(Plant* type, float dt)
{
	m_timer -= dt;
	if (m_timer > 0)
		return;

	type->Reload();
	type->m_stateMachine.TryTransitionTo(type, (int)Plant::State::Idle);
}

void ReloadingPLantState::End(Plant* type)
{
}
