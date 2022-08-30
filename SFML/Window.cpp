#include "Window.h"
#include <iostream>

Window::Window(sf::RenderWindow* renderWindow, int x, int y)
{
	panel = new sf::RectangleShape(sf::Vector2f(x, y));
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
	panel->setOutlineColor(sf::Color(0, 0, 0));
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