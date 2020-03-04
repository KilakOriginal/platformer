#include "State.hpp"

// Con-/Destructors
State::State(sf::RenderWindow* window, std::stack<State*>* states)
	: window(window), states(states), bRequestsQuit(false)
{
}

State::~State()
{
}

// Functions
sf::RenderWindow* State::getWindow()
{
	return this->window;
}

void State::SetWindow(sf::RenderWindow* window)
{
	this->window = window;
}

const bool& State::cbGetQuit() const
{
	return this->bRequestsQuit;
}

void State::EndState()
{
	this->bRequestsQuit = true;
}

void State::UpdateMousePositions()
{
	this->mouseScreenPos = sf::Mouse::getPosition();
	this->mouseWindowPos = sf::Mouse::getPosition(*this->window);
	this->mouseViewPos = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}
