#pragma once

#include "GameState.hpp"

class MainMenuState
	: public State
{
private:
	// Variables
	sf::Texture backgroundTexture;
	sf::RectangleShape background;
	sf::Font font;

	std::map<std::string, Button*> mbButtons;

	// Initialisation
	void InitVariables();
	void InitBackgroud();
	void InitFonts();
	void InitButtons();

	// Functions

public:
	// Con-/Destructors
	MainMenuState(sf::RenderWindow* window, std::stack<State*>* states);
	virtual ~MainMenuState();

	// Functions
	void UpdateInput(const float& dt) override;
	void UpdateButtons();
	void Update(const float& dt) override;

	void RenderButtons(sf::RenderWindow& window);
	void Render(sf::RenderWindow* window = nullptr) override;
};
