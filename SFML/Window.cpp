#include "Window.h"
#include <iostream>

Window::Window(sf::RenderWindow* renderWindow, int x, int y)
{
	std::cout <<  x << std::endl;
	std::cout << y << std::endl;
	sizeVector = new sf::Vector2f(x, y);
	panel = new sf::RectangleShape(*sizeVector);
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

sf::Vector2f* Window::getSize()
{
	return sizeVector;
}


void Window::firstRender()
{
	panel->setFillColor(sf::Color(16, 27, 36));
	panel->setOutlineThickness(1);
	panel->setOutlineColor(sf::Color(150, 0, 0));
	renderWindow->draw(*panel);
	drawButtons();
}

void Window::drawUI()
{
	renderWindow->draw(*panel);
	measureCursorRelativeToButtons();
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
	panel->setOutlineColor(colour);
	drawUI();
}


void Window::addButton(float x, float y)
{
	Button* button = new Button(new sf::Vector2f(x, y));
	buttons.push_back(button);
}

void Window::addButton(float x, float y, std::string text)
{
	Button* button = new Button(new sf::Vector2f(x, y), text);
	buttons.push_back(button);
}





bool Window::isMouseInBounds(sf::Vector2i mouseLocation)
{
	return mouseLocation.x > panel->getPosition().x && mouseLocation.x < panel->getPosition().x + this->getSize()->x
		&& mouseLocation.y > panel->getPosition().y && mouseLocation.y < panel->getPosition().y + this->getSize()->y;
}





void Window::measureCursorRelativeToButtons(sf::Vector2i mouseLocation)
{
	for (int i = 0; i < buttons.size(); i++)
	{
		if (buttons.at(i)->isMouseInBounds(mouseLocation))
		{
			buttons.at(i)->colourButton(sf::Color::Green, renderWindow);
		}
		else
		{
			buttons.at(i)->colourButton(sf::Color::Black, renderWindow);
		}
	}
}