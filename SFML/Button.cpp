#include "Button.h"
#include <iostream>

Button::Button(sf::Vector2f* size)
{
	sizeVector = size;
	box = new sf::RectangleShape(*size);
}

Button::Button(sf::Vector2f* size, std::string text)
{
	box = new sf::RectangleShape(*size);
	this->text = text;
}


sf::Vector2f* Button::getSize()
{
	return sizeVector;
}


void Button::setPosition(int x, int y)
{
	box->setPosition(x, y);
}

void Button::draw(sf::RenderWindow* renderWindow)
{
	renderWindow->draw(*box);
}

bool Button::isMouseInBounds(sf::Vector2i mouseLocation)
{
	return mouseLocation.x > box->getPosition().x && mouseLocation.x < box->getPosition().x + this->getSize()->x
		&& mouseLocation.y > box->getPosition().y && mouseLocation.y < box->getPosition().y + this->getSize()->y;
}



void Button::colourButton(sf::Color colour, sf::RenderWindow* renderWindow)
{
	std::cout << "esjdnwdjnw" << std::endl;
	box->setFillColor(colour);
}