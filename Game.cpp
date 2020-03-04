#include "Game.hpp"

void Game::InitVariables()
{
	this->window = nullptr;
	this->bFullscreen = false;
	this->fDt = 0.f;
}

void Game::InitWindow()
{
	std::ifstream ifs("Config/window.ini");
	this->videoModes = sf::VideoMode::getFullscreenModes();

	std::string title("Window");
	sf::VideoMode window_bounds(sf::VideoMode(720 * 16 / 9, 720));
	window_bounds.bitsPerPixel = 32;
	bFullscreen = false;
	unsigned framerate_limit = 60;
	bool vsync_enabled = false;
	uint8_t aa_level = 0;

	if (ifs.is_open())
	{
		std::getline(ifs, title);
		ifs >> window_bounds.width >> window_bounds.height;
		ifs >> bFullscreen;
		ifs >> framerate_limit;
		ifs >> vsync_enabled;
		ifs >> aa_level;
	}

	ifs.close();

	this->windowSettings.antialiasingLevel = aa_level;
	this->bFullscreen = bFullscreen;
	if (this->bFullscreen)
		this->window = new sf::RenderWindow(window_bounds, title, sf::Style::Fullscreen, this->windowSettings);
	else
		this->window = new sf::RenderWindow(window_bounds, title, sf::Style::Titlebar | sf::Style::Close, this->windowSettings);
	this->window->setFramerateLimit(framerate_limit);
	this->window->setVerticalSyncEnabled(vsync_enabled);
}

void Game::InitStates()
{
	this->states.push(new MainMenuState(this->window, &this->states));
}

Game::Game()
{
	this->InitWindow();
	this->InitStates();
}

Game::~Game()
{
	delete this->window;
	while (!this->states.empty())
	{
		delete this->states.top();
		this->states.pop();
	}
}

void Game::QuitApplication(sf::RenderWindow* window)
{
	window->close();
}

void Game::UpdateDt()
{
	this->fDt = dtClock.restart().asSeconds();
}

void Game::UpdateSFMLEvents()
{
	if (this->window->pollEvent(this->sfEvent))
	{
		switch (this->sfEvent.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		}
	}
}

void Game::Update()
{
	this->UpdateDt();
	this->UpdateSFMLEvents();
	if (!this->states.empty())
	{
		this->states.top()->Update(this->fDt);

		if (this->states.top()->cbGetQuit())
		{
			this->states.top()->EndState();
			delete this->states.top();
			this->states.pop();
		}
	}
	else
		this->QuitApplication(this->window);
}

void Game::Render()
{
	this->window->clear();

	// Render items
	if (!this->states.empty())
		this->states.top()->Render();

	this->window->display();
}

void Game::Run()
{
	while (this->window->isOpen())
	{
		this->Update();
		this->Render();
	}
}
