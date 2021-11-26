#include "Game.h"

//private functions
void Game::initVariables()
{
	this->window = nullptr;

	//Game logic
	this->menuOpen = true;
	this->menuOpen2 = true;
	this->endMenuScreen = false;
	this->endGame = false;
	this->points = 0;
	this->health = 10;
	this->enemySpawnTimerMax = 15.f;
	this->enemySpawnTimer = this->enemySpawnTimerMax;
	this->maxEnemies = 5;
	this->mouseHeld = false;
}

void Game::initWindow()
{
	this->videomode.height = 600;
	this->videomode.width = 800;

	this->window = new sf::RenderWindow(sf::VideoMode(1280, 720), "First Game", sf::Style::Titlebar | sf::Style::Close );
	
	this->window->setFramerateLimit(60);

	//sf::Texture texture;
	//texture.loadFromFile("Textures/sara.png");
	//sf::Sprite sprite(texture);
	//window->draw(sprite);
	
	
}

void Game::initFonts()
{
	this->font.loadFromFile("Fonts/NewFont.otf");
}

void Game::initTexture()
{
	//this->texture.loadFromFile("Textures/sara.png");
}

void Game::initText()
{
	this->uiText.setFont(this->font);
	this->uiText.setCharacterSize(35);
	this->uiText.setFillColor(sf::Color::White);
	this->uiText.setString("");
}

void Game::initStartText()
{
	this->menuText.setFont(this->font);
	this->menuText.setCharacterSize(55);
	this->menuText.setFillColor(sf::Color::White);
	this->menuText.setString("NONE");
}

void Game::initEndText()
{
	this->endScreenText.setFont(this->font);
	this->endScreenText.setCharacterSize(60);
	this->endScreenText.setFillColor(sf::Color::White);
	this->endScreenText.setString("");
}

void Game::initEnemies()
{
	this->enemy.setPosition(10.f, 10.f);
	this->enemy.setSize(sf::Vector2f(100.f, 100.f));
	this->enemy.setFillColor(sf::Color::Cyan);
	//this->enemy.setOutlineColor(sf::Color::Green);
	//this->enemy.setOutlineThickness(1.f);
}

//Constructors / Destructors
Game::Game()
{
	this->initVariables();
	this->initWindow(); 
	this->initFonts();
	//this->initTexture();
	this->initText();
	this->initStartText();
	this->initEndText();
	this->initEnemies();
}

Game::~Game()
{
	delete this->window;
}

//Accessors
const bool Game::running() const
{
	return this->window->isOpen();
}

const bool Game::getEndGame() const
{
	return this->endGame;
	//sdsd
}

void Game::spawnEnemy()
{
	/*
		return void

		Spawn enemies and sets their types and colors. Spawn them at random positions.
		-Sets a random type (diff).
		-Sets a random position.
		-Sets a random color.
		-Adds enemy to vector.
	*/

	//this->sprite.setTexture();

	this->enemy.setPosition(
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),0.f
		//static_cast<float>(rand() % static_cast<int>(this->window->getSize().y - this->enemy.getSize().y))
	);

	//Randomize enemy type
	int type = rand() % 9;

	switch (type)
	{
	case 0:
		this->enemy.setSize(sf::Vector2f(70.f, 70.f));
		this->enemy.setFillColor(sf::Color::Magenta);
		break;
	case 1:
		this->enemy.setSize(sf::Vector2f(75.f, 75.f));
		this->enemy.setFillColor(sf::Color::Blue);
		break;
	case 2:
		this->enemy.setSize(sf::Vector2f(80.f, 80.f));
		this->enemy.setFillColor(sf::Color::Cyan);
		break;
	case 3:
		this->enemy.setSize(sf::Vector2f(70.f, 70.f));
		this->enemy.setFillColor(sf::Color::Red);
		break;
	case 4:
		this->enemy.setSize(sf::Vector2f(100.f, 100.f));
		this->enemy.setFillColor(sf::Color::Green);
		break;
	case 5:
		this->enemy.setSize(sf::Vector2f(100.f, 100.f));
		this->enemy.setFillColor(sf::Color::Magenta);
		break;
	case 6:
		this->enemy.setSize(sf::Vector2f(100.f, 100.f));
		this->enemy.setFillColor(sf::Color::Yellow);
		break;
	case 7:
		this->enemy.setSize(sf::Vector2f(100.f, 100.f));
		this->enemy.setFillColor(sf::Color::White);
		break;
	case 8:
		this->enemy.setSize(sf::Vector2f(100.f, 100.f));
		this->enemy.setFillColor(sf::Color::Yellow);
		break;
	default:
		this->enemy.setSize(sf::Vector2f(100.f, 100.f));
		this->enemy.setFillColor(sf::Color::Yellow);
		break;
	}

	//Spawn the enemy
	this->enemies.push_back(this->enemy);
}

//Functions
void Game::pollEvents()
{
	//Event polling
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
				this->window->close();
				break;

		case sf::Event::KeyPressed:
				if (ev.key.code == sf::Keyboard::Enter)
					this->menuOpen = false;
				if (ev.key.code == sf::Keyboard::Escape)
					this->window->close();
				break;
		}
	}
}

void Game::updateMousePositions()
{
	/*
		return void
		updates the mouse positions
		mouse position relative to window(vector2i)
	*/

	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::updateText()
{
	if (!menuOpen && !endMenuScreen)
	{
		std::stringstream ss;

		ss << "Points   " << this->points << "\n"
			<< "Health   " << this->health << "\n";

		this->uiText.setString(ss.str());
	}


	if (menuOpen2)
	{
		std::stringstream texts;
		texts << "     Hurry Up Click On Tiles\nBefore Your Health Drains Out !\n\n     Press Enter to start...";
		this->menuText.setString(texts.str());
		menuText.setPosition(450.f, 230.f);
		menuOpen2 = false;
		
	}

	if (endMenuScreen)
	{
		std::stringstream endtext;
		endtext << "\t YOU LOST!\nPress Esc to quit.";
		this->endScreenText.setString(endtext.str());
		endScreenText.setPosition(480.f, 280.f);
		//endMenuScreen = false;
	}

}

void Game::updateEnemies()
{
	/*
		return void

		Updates the enemy spawn timer and spawns enemies
		when the total amount of enemies is smaller than the maximum.
		Moves the enemies downwards.
		Removes the enemies at the edge of the screen.
	*/

	//Updating the timer for enemy spawning
	if (this->enemies.size() < this->maxEnemies)
	{

		if (this->enemySpawnTimer >= this->enemySpawnTimerMax && !menuOpen)//checking menuOpen bool and starting the game
		{
			//Spawn the enemy and reset the timer
			this->spawnEnemy();
			this->enemySpawnTimer = 0.f;

			//remove the startup text
			menuText.setCharacterSize(0.f);
			menuText.setFillColor(sf::Color::Transparent);
		}
		else
		{
			this->enemySpawnTimer += 1.f;
		}
	}

	//Moving and updating enemies
	for (int i = 0; i < this->enemies.size(); i++)
	{
		bool deleted = false;

		this->enemies[i].move(0.f, 5.f);

		if (this->enemies[i].getPosition().y > this->window->getSize().y)
		{
			this->enemies.erase(this->enemies.begin() + i);
			this->health -= 1;
			std::cout << "Health : " << this->health << "\n";
		}
	}
	//Check if clicked upon
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (this->mouseHeld == false)
		{
			this->mouseHeld = true;
			bool deleted = false;
			for (size_t i = 0; i < this->enemies.size() && deleted == false; i++)
			{
				if (this->enemies[i].getGlobalBounds().contains(this->mousePosView))
				{
					//Gain points
					if (!endMenuScreen)
					{
						if (this->enemies[i].getFillColor() == sf::Color::Magenta)
							this->points += 10;
						else if (this->enemies[i].getFillColor() == sf::Color::Blue)
							this->points += 7;
						else if (this->enemies[i].getFillColor() == sf::Color::Cyan)
							this->points += 5;
						else if (this->enemies[i].getFillColor() == sf::Color::Red)
							this->points += 7;
						else if (this->enemies[i].getFillColor() == sf::Color::Green)
							this->points += 5;

						std::cout << "Points : " << this->points << "\n";
					}

					//Delete the enemy
					deleted = true;
					this->enemies.erase(this->enemies.begin() + i);
				}
			}
		}
	}
	else
	{
		this->mouseHeld = false;
	}
}

//Functions
void Game::update()
{
	this->pollEvents();

	if (this->endGame == false)
	{
		this->updateMousePositions();

		this->updateText();

		this->updateEnemies();
	}

	//End game condition
	if (this->health < 0)
		endMenuScreen = true;
		//this->endGame = true;//End game use this line to display end game text
}

void Game::renderText(sf::RenderTarget& target)
{
	target.draw(this->uiText);
	target.draw(this->endScreenText);
	target.draw(this->menuText);


}
void Game::renderTextures(sf::RenderTarget& target)
{
	//target.draw(this->sprite);
}

void Game::renderEnemies(sf::RenderTarget& target)
{
	//Rendering all the enemies
	if(!endMenuScreen)//to stop rendering enemies after losing
	for (auto& e : this->enemies)
	{
		target.draw(e);
	}


}

void Game::render()
{
	this->window->clear(sf::Color());

	//Draw game objects
	this->renderEnemies(*this->window);

	//this->menu.render(this->window);

	this->renderText(*this->window);

	this->renderTextures(*this->window);

	this->window->display();
}
