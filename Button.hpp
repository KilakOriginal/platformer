#pragma once

#include <SFML/Graphics.hpp>

enum button_states { BTN_IDLE, BTN_HOVER, BTN_ACTIVE };

class Button
{
private:
	// Variables
	uint8_t buttonState;

	sf::RectangleShape shape;
	sf::Font font;
	sf::Text text;

	sf::Color idleColour, hoverColour, activeColour;
	sf::Color textIdleColour, textHoverColour, textActiveColour;

	// Initialisation
public:
	// Con-/Destructors
	Button(float fX, float fY, float fWidth, float fHeight, sf::Font font, std::string sText, unsigned uCharacter_size, sf::Color text_idle_colour, sf::Color text_hover_colour, sf::Color text_active_colour, sf::Color idle_colour, sf::Color hover_colour, sf::Color active_colour);
	~Button();

	// Accessors
	const bool bIsPressed() const;

	// Functions
	void Update(const sf::Vector2f mousePosition);
	void Render(sf::RenderWindow& window);
};

