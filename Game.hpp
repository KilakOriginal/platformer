#pragma once

#include "MainMenuState.hpp"

class Game
{
private:
	std::stack<State*> states;

	sf::RenderWindow* window;
	sf::Event sfEvent;
	std::vector<sf::VideoMode> videoModes;
	sf::ContextSettings windowSettings;
	bool bFullscreen;

	sf::Clock dtClock;
	float fDt;

	void InitVariables();
	void InitWindow();
	void InitStates();

public:
	Game();
	virtual ~Game();

	void QuitApplication(sf::RenderWindow* window);
	void UpdateDt();
	void UpdateSFMLEvents();
	void Update();
	void Render();
	void Run();
};
