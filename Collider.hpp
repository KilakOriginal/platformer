#pragma once

#include <vector>

#include "Player.hpp"

class Collider
{
private:
	Player* player;

public:
	Collider();
	Collider(Player* player);
	~Collider();

	void Update(sf::RectangleShape& object, float fForce = 0);
	void Update(std::vector<sf::RectangleShape*> objects, float fForce = 0);
	void SetPlayer(Player* player);
};

