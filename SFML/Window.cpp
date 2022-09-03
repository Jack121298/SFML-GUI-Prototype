#include "Window.h"
#include <iostream>

Window::Window(sf::RenderWindow* renderWindow, int x, int y)
{
	location = new sf::Vector2f(x, y);
	panel = new sf::RectangleShape(*location);
	this->renderWindow = renderWindow;
}


void Window::setPosition(int x, int y)
{
	panel->setPosition(x, y);
}


void Window::setSize(int x, int y)
{
	panel->setScale(x, y);
}


void Window::drawUI()
{
	panel->setFillColor(sf::Color(0, 0, 0));
	panel->setOutlineThickness(1);
	panel->setOutlineColor(sf::Color(150, 0, 0));
	renderWindow->draw(*panel);
	drawButtons();

}

void Window::drawButtons()
{
	for (int i = 0; i < buttons.size(); i++)
	{
		buttons.at(i)->draw(renderWindow);
	}
}

void Window::colourPanel(sf::Color colour)
{
	panel->setFillColor(sf::Color::Green);
	renderWindow->draw(*panel);
	renderWindow->display();
}


void Window::addButton(float x, float y)
{
	Button* button = new Button(sf::Vector2f(x, y));
	buttons.push_back(button);
}

void Window::addButton(float x, float y, std::string text)
{
	Button* button = new Button(sf::Vector2f(x, y), text);
	buttons.push_back(button);
}





bool Window::isMouseInBounds(sf::Vector2i mouseLocation)
{
	return mouseLocation.x > panel->getOrigin().x && mouseLocation.x < panel->getLocalBounds().width
		&& mouseLocation.y > panel->getOrigin().y && mouseLocation.y < panel->getLocalBounds().height;
}