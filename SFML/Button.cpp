#include "Button.h"


Button::Button(sf::Vector2f pos)
{
	box = new sf::RectangleShape(pos);
}

Button::Button(sf::Vector2f pos, std::string text)
{
	box = new sf::RectangleShape(pos);
	this->text = text;
}




void Button::draw(sf::RenderWindow* renderWindow)
{
	renderWindow->draw(*box);
}