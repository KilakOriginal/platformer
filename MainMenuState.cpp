#include "MainMenuState.hpp"

void MainMenuState::InitVariables()
{
	//...
}

void MainMenuState::InitBackgroud()
{
	this->background.setSize(static_cast<sf::Vector2f> (this->getWindow()->getSize()));
	if (!this->backgroundTexture.loadFromFile("image/bg7.jpg"))
	{
		/*std::cerr << "ERROR::NON_CRITICAL::MainMenuState::BACKGROUND_TEXTURE_NOT_FOUND" << std::endl;
		this->background.setFillColor(sf::Color::Black);*/
	}
	else
	{
		this->background.setTexture(&this->backgroundTexture);
	}
}

void MainMenuState::InitFonts()
{
	if (!font.loadFromFile("font/OdibeeSans-Regular.ttf"))
		throw("ERROR::NON_CRITICAL::MainMenuState::COULD_NOT_LOAD_FONT");

}

// Functions
void MainMenuState::InitButtons()
{
	this->mbButtons["GAME_STATE"] = new Button(100, 300, 150, 50, this->font, "New Game", 26, sf::Color(255, 255, 255, 200), sf::Color::White, sf::Color(200, 200, 200, 200), sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));
	this->mbButtons["LOAD_GAME"] = new Button(100, 405, 150, 50, this->font, "Load Game", 26, sf::Color(255, 255, 255, 200), sf::Color::White, sf::Color(200, 200, 200, 200), sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));
	this->mbButtons["SETTINGS"] = new Button(100, 510, 150, 50, this->font, "Settings", 26, sf::Color(255, 255, 255, 200), sf::Color::White, sf::Color(200, 200, 200, 200), sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));
	this->mbButtons["EXIT"] = new Button(100, 820, 150, 50, this->font, "Exit Game", 26, sf::Color(255, 255, 255, 200), sf::Color::White, sf::Color(200, 200, 200, 200), sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));
}

// Con-/Destructors
MainMenuState::MainMenuState(sf::RenderWindow* window, std::stack<State*>* states)
	: State(window, states)
{
	this->InitVariables();
	this->InitBackgroud();
	this->InitFonts();
	this->InitButtons();
}

MainMenuState::~MainMenuState()
{
	if (!this->mbButtons.empty())
		for (auto i : this->mbButtons)
			delete i.second;
}

// Functions
void MainMenuState::UpdateInput(const float& dt)
{
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MENU_SCROLL_UP"))))
	//	scroll(up);
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MENU_SCROLL_DOWN"))))
	//	scroll(down);
}

void MainMenuState::UpdateButtons()
{
	for (auto& i : this->mbButtons)
		i.second->Update(this->mouseViewPos);

	// New Game
	if (this->mbButtons["GAME_STATE"]->bIsPressed())
		this->states->push(new GameState(this->getWindow(), this->states));

	// Load Game

	// Settings

	// Quit
	if (this->mbButtons["EXIT"]->bIsPressed())
		this->EndState();
}

void MainMenuState::Update(const float& dt)
{
	this->UpdateMousePositions();
	this->UpdateInput(dt);
	this->UpdateButtons();
}

void MainMenuState::RenderButtons(sf::RenderWindow& window)
{
	for (auto i : this->mbButtons)
		i.second->Render(window);
	//std::cout << i.first << " " << i.second << std::endl;
}

void MainMenuState::Render(sf::RenderWindow* window)
{
	if (!window)
		window = this->getWindow();

	window->draw(this->background);

	this->RenderButtons(*window);
}
