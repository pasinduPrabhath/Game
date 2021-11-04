#pragma once

#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Menu.h"

/*
	class that acts as the game engine.
	Wrapper class.
*/

class Game
{
private:
	//Window
	sf::RenderWindow* window;
	sf::VideoMode videomode;
	sf::Event ev;

	//Mouse position
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	//Resources
	sf::Font font;

	//Text
	sf::Text uiText;
	sf::Text menuText;

	//Texture
	sf::Texture texture;

	//sprite
	//sf::Sprite sprite;

	//Game logic
	bool endGame;
	bool menuOpen;
	unsigned points;
	int health;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;
	bool mouseHeld;

	//Game objects
	std::vector<sf::RectangleShape> enemies;
	sf::RectangleShape enemy;

	//Menu menu;

	//Private functions
	void initVariables();
	void initWindow();
	void initFonts();
	void initTexture();
	void initText();
	void initStartText();
	void initEnemies();

public:
	//constructors / Destructors
	Game();
	virtual ~Game();

	//Accessors
	const bool running() const;
	const bool getEndGame() const;

	//Functions
	void spawnEnemy();

	void pollEvents();
	void updateMousePositions();
	void updateText();
	void updateEnemies();
	void update();

	void renderText(sf::RenderTarget& target);
	void renderTextures(sf::RenderTarget& target);
	void renderEnemies(sf::RenderTarget& target);
	void render();
};

