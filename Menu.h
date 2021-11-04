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

#include "Game.h"

class Menu
{
private:
	sf::RectangleShape shape;

	sf::Font fonts;

	sf::Text uiTexts;
	
	void initShape();

	//Game game;

	void initfont();
	void initTexts();

public:
	Menu();
	virtual ~Menu();

	void update();
	void render(sf::RenderTarget* target);

	void updateText();
	void renderText(sf::RenderTarget& target);
};

