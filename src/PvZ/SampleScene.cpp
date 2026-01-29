#include "SampleScene.h"

#include "DummyEntity.h"
#include "Plant.h"
#include "Zombie.h"
#include "Projectile.h"

#include "Debug.h"

void SampleScene::OnInitialize()
{
	pPlant1 = CreateEntity<Plant>(50, sf::Color::Green);
	pPlant1->SetPosition(100, Scene::GetWindowHeight() / 6);
	pPlant1->SetRigidBody(true);

	pPlant2 = CreateEntity<Plant>(50, sf::Color::Green);
	pPlant2->SetPosition(100, Scene::GetWindowHeight() /2);
	pPlant2->SetRigidBody(true);

	pPlant3 = CreateEntity<Plant>(50, sf::Color::Green);
	pPlant3->SetPosition(100, Scene::GetWindowHeight() / 1.20f);
	pPlant3->SetRigidBody(true);

	pPlantSelected = nullptr;
}

void SampleScene::OnEvent(const sf::Event& event)
{
	if (event.type != sf::Event::EventType::MouseButtonPressed)
		return;

	if (event.mouseButton.button == sf::Mouse::Button::Right)
	{
		
		pZombie = CreateEntity<Zombie>(80, sf::Color::Red);
		pZombie->SetPosition(event.mouseButton.x, event.mouseButton.y);
		pZombie->SetRigidBody(true);
		/*TrySetSelectedEntity(pEntity1, event.mouseButton.x, event.mouseButton.y);
		TrySetSelectedEntity(pEntity2, event.mouseButton.x, event.mouseButton.y);
		TrySetSelectedEntity(pEntity3, event.mouseButton.x, event.mouseButton.y);*/
	}

	if (event.mouseButton.button == sf::Mouse::Button::Left)
	{
		if (pPlantSelected != nullptr)
		{
			/*pEntitySelected->GoToPosition(event.mouseButton.x, event.mouseButton.y, 100.f);*/
			TrySetSelectedPlant(pPlant1, event.mouseButton.x, event.mouseButton.y);
			TrySetSelectedPlant(pPlant2, event.mouseButton.x, event.mouseButton.y);
			TrySetSelectedPlant(pPlant3, event.mouseButton.x, event.mouseButton.y);
			pPlantSelected->Shoot();
			pProjectile = CreateEntity<Projectile>(25, sf::Color::Blue);
			pProjectile->SetPosition(pPlantSelected->GetPosition().x, pPlantSelected->GetPosition().x);
			pProjectile->SetRigidBody(false);


		}
	}
}

void SampleScene::TrySetSelectedPlant(Plant* pEntity, int x, int y)
{
	if (pEntity->IsInside(x, y) == false)
	{
		return;
	}

	pPlantSelected = pEntity;
}

void SampleScene::OnUpdate()
{
	/*if (pPlantSelected != nullptr)
	{
		sf::Vector2f position = pPlantSelected->GetPosition();
		Debug::DrawCircle(position.x, position.y, 10, sf::Color::Blue);
	}*/
	for (Projectile& pjt : G)
	{
		pjt.GoToDirection(1, 0);
	}
	for (Zombie& zmb : Entity::Get)
	{
		zmb.GoToDirection(-1, 0);
	}
}