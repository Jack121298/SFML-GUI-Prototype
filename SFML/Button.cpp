#include "Button.h"


Button::Button(sf::Vector2f* pos)
{
	sizeVector = pos;
	box = new sf::RectangleShape(*pos);
}

Button::Button(sf::Vector2f* pos, std::string text)
{
	box = new sf::RectangleShape(*pos);
	this->text = text;
}


sf::Vector2f* Button::getSize()
{
	return sizeVector;
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
	box->setFillColor(colour);
	draw(renderWindow);
}