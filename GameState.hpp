#pragma once

#include "State.hpp"

class GameState
	: public State
{
private:
	// Variables
	Player* player;
	Collider playerCollider;
	UI playerUI;

	sf::RectangleShape groundRect;
	sf::RectangleShape groundRect2;

	// Initialisation
	void InitTextures();
	void InitPlayers();

public:
	// Con-/Destructors
	GameState(sf::RenderWindow* window, std::stack<State*>* states);
	virtual ~GameState();

	// Functions
	void UpdateInput(const float& dt) override;
	void Update(const float& dt) override;
	void Render(sf::RenderWindow* window = nullptr) override;
};

