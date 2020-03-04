#include "Button.hpp"

Button::Button(float fX, float fY, float fWidth, float fHeight, sf::Font font, std::string sText, unsigned uCharacter_size, sf::Color text_idle_colour, sf::Color text_hover_colour, sf::Color text_active_colour, sf::Color idle_colour, sf::Color hover_colour, sf::Color active_colour)
	: font(font), idleColour(idle_colour), hoverColour(hover_colour), activeColour(active_colour), textIdleColour(text_idle_colour), textHoverColour(text_hover_colour), textActiveColour(text_active_colour), buttonState(BTN_IDLE)
{
	this->shape.setPosition(fX, fY);
	this->shape.setSize(sf::Vector2f(fWidth, fHeight));

	this->text.setFont(this->font);
	this->text.setString(sText);
	this->text.setFillColor(text_idle_colour);
	this->text.setCharacterSize(uCharacter_size);
	this->text.setPosition(this->shape.getPosition().x + (this->shape.getGlobalBounds().width - this->text.getGlobalBounds().width) / 2, this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2) - this->text.getGlobalBounds().height);
}

Button::~Button()
{
}

const bool Button::bIsPressed() const
{
	return this->buttonState == BTN_ACTIVE ? true : false;
}

void Button::Update(const sf::Vector2f mousePosition)
{
	this->buttonState = BTN_IDLE;

	if (this->shape.getGlobalBounds().contains(mousePosition)) // Hover
	{
		this->buttonState = BTN_HOVER;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) // Click
			this->buttonState = BTN_ACTIVE;
	}

	switch (this->buttonState)
	{
	case BTN_IDLE:
		this->shape.setFillColor(this->idleColour);
		this->text.setFillColor(this->textIdleColour);
		break;
	case BTN_HOVER:
		this->shape.setFillColor(this->hoverColour);
		this->text.setFillColor(this->textHoverColour);
		break;
	case BTN_ACTIVE:
		this->shape.setFillColor(this->activeColour);
		this->text.setFillColor(this->textActiveColour);
		break;
	default:
		break;
	}
}

void Button::Render(sf::RenderWindow& window)
{
	window.draw(this->shape);
	window.draw(this->text);
}
