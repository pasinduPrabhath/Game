#include "Menu.h"

void Menu::initShape()
{
	this->shape.setFillColor(sf::Color::Green);
	this->shape.setSize(sf::Vector2f(100.f, 100.f));
}

Menu::Menu()
{
	this->initShape();
}

Menu::~Menu()
{

}

void Menu::update()
{
}

void Menu::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
