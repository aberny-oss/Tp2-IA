#include "Scene.h"

class Plant;
class Zombie;

class PvZScene : public Scene
{
public:
	enum class Tag
	{
		Plant,
		Zombie,
		Projectile,

		Count
	};

	float m_laneHeight;

	Plant* m_plants[3];

protected:
	void OnInitialize() override;
	void OnEvent(const sf::Event& event) override;
	void OnUpdate() override;

private:
	int GetLaneIndex(int y) const;
	Zombie* SpawnZombie(int laneIndex);

};