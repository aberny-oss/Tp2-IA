
#include <SFML/Graphics.hpp>
#include <iostream>

#include "GameManager.h"
//#include "SampleScene.h"

#include <cstdlib>
#include <crtdbg.h>

int main()
{
	GameManager* pInstance = GameManager::Get();

	std::cout << " jeux lancer " << std::endl;
	//pInstance->CreateWindow(1280, 720, "SampleScene", 60, sf::Color::Black);

	//pInstance->LaunchScene<SampleScene>();

	return 0;
}