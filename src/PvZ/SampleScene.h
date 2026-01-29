#pragma once

#include "Scene.h"

class DummyEntity;
class Plant;
class Zombie;
class Projectile;

class SampleScene : public Scene
{
	Plant* pPlant1;
	Plant* pPlant2;
	Plant* pPlant3;

	Zombie* pZombie;

	Projectile* pProjectile;

	Plant* pPlantSelected;


private:
	void TrySetSelectedPlant(Plant* pEntity, int x, int y);

public:
	void OnInitialize() override;
	void OnEvent(const sf::Event& event) override;
	void OnUpdate() override;
};


