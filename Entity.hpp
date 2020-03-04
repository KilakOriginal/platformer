#pragma once

#include <SFML/Graphics.hpp>

#include "Item.hpp"

class Entity
{
private:
	sf::RectangleShape body;

	bool bIsJumping;
	float fJumpHeight;
	float fSpeed;
	sf::Vector2f velocity;

	std::vector<Item*> inventory;
	short nHP;

public:
	Entity(sf::Vector2f size, sf::Texture texture, float fSpeed = 0, bool bIsJumping = false);
	~Entity();

	void Draw(sf::RenderWindow& window);
	void Move(sf::Vector2f distance);
	void SetPosition(sf::Vector2f position);
	void PollMovement(float fDeltaTime);
	void SetSpeed(float fSpeed);
	void SetVelocity(sf::Vector2f velocity);
	void SetJump(bool bState);
	void AddItem(Item* item);
	void setHP(short nHP);
	void addHP(short nHP = 1);

	bool bGetJumpState() { return this->bIsJumping; }
	sf::Vector2f getVelocity() { return this->velocity; }
	sf::Vector2f getPosition() { return this->body.getPosition(); }
	sf::Vector2f getSize() { return this->body.getSize(); }
	sf::FloatRect getGloabalbounds() { return this->body.getGlobalBounds(); }
	sf::RectangleShape getRect() { return this->body; }
	short getInventorySize() { return this->inventory.size(); }
	short getHP() { return this->nHP; }
};

