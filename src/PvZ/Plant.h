#pragma once
#include "Entity.h"

class Plant : public Entity
{
private:

	int m_Life = 2;
	int damage = 1;
	int m_MaxAmmo = 5;
	int m_Ammo = m_MaxAmmo;

	float m_DelayToShooting = 1.f;
	float m_DelayToReloading = 2.f;

	bool b_Shooting = false;
	bool b_Reloading = false;

public:

	void Shoot();
	void Realoading();

};

