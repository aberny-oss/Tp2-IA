#include "Plant.h"

#include "PvZScene.h"
#include "Projectile.h"

void Plant::Shoot()
{
	float projectileRadius = GetRadius() * 0.1f;
	sf::Vector2f projectilePos = GetPosition();

	Projectile* p = CreateEntity<Projectile>(projectileRadius, sf::Color::Cyan);
	p->SetPosition(projectilePos.x, projectilePos.y);
}

void Plant::OnInitialize()
{
	SetTag((int)PvZScene::Tag::Plant);
}