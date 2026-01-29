#pragma once
#include "Entity.h"

class Zombie : public Entity
{
private:

	int m_Life = 3;
	int damage = 2;

	float m_DelayToEating = 2.5f;
	bool b_Eating = false;

public:

	/*void Move();*/
	void Eat();

};

