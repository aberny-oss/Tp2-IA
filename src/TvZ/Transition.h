#pragma once
#include <vector>
#include "Condition.h"

class Transition : public Condition
{

private:

	std::vector<Condition*> m_conditions;


public:
	
	void AddCondition();

	bool CheckConditions(void* context) const override;


};