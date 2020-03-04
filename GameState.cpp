#include "GameState.hpp"

void GameState::InitTextures()
{
	if (!this->mtTextures["PLAYER_SHEET"].loadFromFile("Sprites/Players/player_sheet.png"))
	{
		//std::cerr << "ERROR::NON_CRITICAL::GAMESTATE::COULD_NOT_LOAD_PLAYER_TEXTURE" << std::endl;
	}
	//Replace texture with white rectangle
}

void GameState::InitPlayers()
{
	//this->player = new Player(0, 0, this->mtTextures["PLAYER_SHEET"]);
	this->player = new Player({ 40.f, 40.f }, sf::Texture(), 100.f, false);
	this->player->SetPosition({ 0, this->getWindow()->getSize().y / 2.f - 20.f });
	this->playerCollider.SetPlayer(this->player);
	this->playerUI.SetPlayer(this->player);

	this->groundRect.setSize({ 720.f * 16.f / 9.f, 720.f / 2.f });
	this->groundRect.setPosition({0, 720.f / 2.f + 20.f});
	this->groundRect.setFillColor(sf::Color(31, 128, 37));

	this->groundRect2.setSize({ 720.f * 16.f / 9.f, 720.f / 2.f });
	this->groundRect2.setPosition({ 720.f * 16.f / 9.f / 2.f, 720.f / 2.f - 60.f });
	this->groundRect2.setFillColor(sf::Color(31, 128, 37));
}

// Con-/Destructors
GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states)
	: State(window, states)
{
	this->InitTextures();
	this->InitPlayers();
}

GameState::~GameState()
{
	delete this->player;
}

// Functions
void GameState::UpdateInput(const float& dt)
{
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->miKeyBinds.at("MOVE_LEFT"))))
		this->player->Move(-1.f, 0.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->miKeyBinds.at("MOVE_RIGHT"))))
		this->player->Move(1.f, 0.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->miKeyBinds.at("MOVE_UP"))))
		this->player->Move(0.f, -1.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->miKeyBinds.at("MOVE_DOWN"))))
		this->player->Move(0.f, 1.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->miKeyBinds.at("QUIT"))))
		this->EndState();*/
}

void GameState::Update(const float& dt)
{
	this->UpdateMousePositions();
	this->UpdateInput(dt);
	this->player->PollMovement(dt);
	this->playerCollider.Update(this->groundRect);
	this->playerCollider.Update(this->groundRect2);
}

void GameState::Render(sf::RenderWindow* window)
{
	if (!window)
		window = this->getWindow();
	this->getWindow()->clear(sf::Color(135, 206, 235));
	this->player->Draw(*this->getWindow());
	this->getWindow()->draw(this->groundRect);
	this->getWindow()->draw(this->groundRect2);
	this->playerUI.Update(*this->getWindow());
}
