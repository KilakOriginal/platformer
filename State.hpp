#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <stack>
#include <fstream>

#include "Player.hpp"
#include "Collider.hpp"
#include "UI.hpp"
#include "Button.hpp"

class State
{
private:
	// Variables
	sf::RenderWindow* window;
	bool bRequestsQuit;

	// Initialisation

protected:
	// Ressources
	std::map<std::string, sf::Texture> mtTextures;

	// Functions
	sf::Vector2i mouseWindowPos;
	sf::Vector2i mouseScreenPos;
	sf::Vector2f mouseViewPos;
	std::stack<State*>* states;

public:
	// Con-/Destructors
	State(sf::RenderWindow* window, std::stack<State*>* states);
	virtual ~State();

	// Functions
	sf::RenderWindow* getWindow();
	void SetWindow(sf::RenderWindow* window);

	const bool& cbGetQuit() const;
	void EndState();
	virtual void UpdateMousePositions();
	virtual void UpdateInput(const float& dt) = 0;
	virtual void Update(const float& dt) = 0;
	virtual void Render(sf::RenderWindow* window = nullptr) = 0;
};

