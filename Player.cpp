#include "Player.hpp"

Player::~Player()
{
}

void Player::setMoney(int iMoney)
{
	this->iMoney = iMoney;
}

void Player::addMoney(int iMoney)
{
	this->iMoney += iMoney;
}
