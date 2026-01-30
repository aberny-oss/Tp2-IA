#include "Entity.h"

class Plant : public Entity
{
public:
	void Shoot();

protected:
	void OnInitialize() override;
};