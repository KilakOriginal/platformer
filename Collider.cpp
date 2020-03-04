#include "Collider.hpp"

Collider::Collider()
	:player(nullptr)
{
}

Collider::Collider(Player* player)
	: player(player)
{
}

Collider::~Collider()
{
}

void Collider::Update(sf::RectangleShape& object, float fForce)
{
	bool top = this->player->getPosition().y + this->player->getGloabalbounds().height >= object.getPosition().y/* && !this->player.getPosition().y <= object.getPosition().y*/ ? true : false;
	//bool bottom = this->player.getPosition().y > object.getPosition().y + object.getGlobalBounds().height ? true : false;
	bool left = this->player->getPosition().x + this->player->getGloabalbounds().width < object.getPosition().x ? true : false;
	bool right = this->player->getPosition().x > object.getPosition().x + object.getGlobalBounds().width ? true : false;
	//bool ycontain = this->player.getPosition().y > object.getPosition().y&& this->player.getPosition().y + this->player.getGloabalbounds().height < object.getPosition().y + object.getGlobalBounds().height ? true : false;

	if (top && !left && !right)
	{
		this->player->SetPosition({ this->player->getPosition().x, object.getPosition().y - this->player->getSize().y });
		this->player->SetJump(false);
	}
}

void Collider::Update(std::vector<sf::RectangleShape*> objects, float fForce)
{
}

void Collider::SetPlayer(Player* player)
{
	this->player = player;
}
