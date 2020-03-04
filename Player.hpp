#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Entity.hpp"

class Player
	: public Entity
{
private:
	int iMoney = 0;

public:
	Player(sf::Vector2f size, sf::Texture texture, float fSpeed = 0, bool bIsJumping = false) : Entity(size, texture, fSpeed, bIsJumping) {}
	~Player();

	void setMoney(int iMoney);
	void addMoney(int iMoney = 1);

	int getMoney() { return this->iMoney; }
};
