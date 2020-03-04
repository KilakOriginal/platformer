#pragma once

#include "Player.hpp"

class UI
{
private:
	Player* player;
	sf::Font font;
	sf::Text amountMoney;
	sf::Text amountHealth;

public:
	UI();
	UI(Player* player);
	~UI();

	void Update(sf::RenderWindow& window);
	void SetPlayer(Player* player);
};

