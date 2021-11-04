#include "Menu.h"
#include "Game.h"

void Menu::initShape()
{
	this->shape.setFillColor(sf::Color::Green);
	this->shape.setSize(sf::Vector2f(100.f, 100.f));
}

void Menu::initfont()
{
	this->fonts.loadFromFile("Fonts/Plaguard.otf");
}

void Menu::initTexts()
{
	this->uiTexts.setFont(this->fonts);
	this->uiTexts.setCharacterSize(24);
	this->uiTexts.setFillColor(sf::Color::White);
	this->uiTexts.setString("NONE");
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

	//this->renderText(*this->game.);
}

void Menu::updateText()
{
}

void Menu::renderText(sf::RenderTarget& target)
{
	target.draw(this->uiTexts);
}
