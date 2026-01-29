#include "Plant.h"
#include <iostream>

void Plant::Shoot()
{
	if (m_Ammo <= 0)
	{
		return;
	}
	m_Ammo -= 1;
	std::cout << "Plante tire ! " << std::endl;
}

void Plant::Realoading()
{
	if (m_Ammo == m_MaxAmmo)
	{
		return;
	}
	m_Ammo = m_MaxAmmo;
	std::cout << "Plante Recharge ! " << std::endl;
}
