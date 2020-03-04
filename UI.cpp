#include "UI.hpp"

UI::UI()
	: player(nullptr)
{
}

UI::UI(Player* player)
	: player(player)
{
	this->font.loadFromFile("./font/OdibeeSans-Regular.ttf");
	this->amountMoney.setCharacterSize(60);
	this->amountMoney.setString("Coins: " + std::to_string(this->player->getMoney()));
	this->amountMoney.setFont(this->font);
	this->amountMoney.setPosition({ 10.f, 10.f });

	this->amountHealth.setCharacterSize(60);
	this->amountHealth.setString("HP: " + std::to_string(this->player->getHP()));
	this->amountHealth.setFont(this->font);
	this->amountHealth.setPosition({ this->amountMoney.getPosition().x + this->amountMoney.getGlobalBounds().width + 500.f, 10.f });
}

UI::~UI()
{
}

void UI::Update(sf::RenderWindow& window)
{
	this->amountMoney.setString("Coins: " + std::to_string(this->player->getMoney()));

	this->amountHealth.setString("HP: " + std::to_string(this->player->getHP()));
	this->amountHealth.setPosition({ window.getSize().x - 10.f - this->amountHealth.getGlobalBounds().width, 10.f });

	window.draw(this->amountMoney);
	window.draw(this->amountHealth);
}

void UI::SetPlayer(Player* player)
{
	this->player = player;
}
