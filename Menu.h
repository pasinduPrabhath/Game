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

class Menu
{
private:
	sf::RectangleShape shape;
	
	void initShape();

public:
	Menu();
	virtual ~Menu();

	void update();
	void render(sf::RenderTarget* target);
};

