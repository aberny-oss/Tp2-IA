#pragma once

class Condition
{
public:

	virtual bool CheckConditions(void* context) const = 0;
};