#include "Entity.hpp"

Entity::Entity(sf::Vector2f size, sf::Texture texture, float fSpeed, bool bIsJumping)
	: fSpeed(fSpeed), fJumpHeight(100.f), bIsJumping(bIsJumping), nHP(3)
{
	this->body.setSize(size);
	this->body.setFillColor(sf::Color::Red);
	this->body.setTexture(&texture);
}

Entity::~Entity()
{
}

void Entity::Draw(sf::RenderWindow& window)
{
	window.draw(this->body);
}

void Entity::Move(sf::Vector2f distance)
{
	this->body.move(distance);
}

void Entity::SetPosition(sf::Vector2f position)
{
	this->body.setPosition(position);
}

void Entity::PollMovement(float fDeltaTime)
{
	if (!this->bIsJumping)
		this->velocity.x *= 0.5f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !this->bIsJumping)
		this->velocity.x -= this->fSpeed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !this->bIsJumping)
		this->velocity.x += this->fSpeed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !this->bIsJumping)
	{
		this->bIsJumping = true;
		this->velocity.y = -sqrt(2.f * 981.f * this->fJumpHeight);
		this->velocity.x *= 0.9f;
	}

	velocity.y += 981.f * fDeltaTime;

	this->body.move(this->velocity * fDeltaTime);
}

void Entity::SetSpeed(float fSpeed)
{
	this->fSpeed = fSpeed;
}

void Entity::SetVelocity(sf::Vector2f velocity)
{
	this->velocity = velocity;
}

void Entity::SetJump(bool bState)
{
	this->bIsJumping = bState;
}

void Entity::AddItem(Item* item)
{
	this->inventory.push_back(item);
}

void Entity::setHP(short nHP)
{
	this->nHP = nHP;
}

void Entity::addHP(short nHP)
{
	this->nHP += nHP;
}
