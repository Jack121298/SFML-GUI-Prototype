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
}




void Window::addButton( )
{

}