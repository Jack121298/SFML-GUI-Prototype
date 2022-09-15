#include "Window.h"
#include <iostream>

Window::Window(sf::RenderWindow* renderWindow, int x, int y)
{
	std::cout <<  x << std::endl;
	std::cout << y << std::endl;
	sizeVector = new sf::Vector2f(x, y);
	panel = new sf::RectangleShape(*sizeVector);
	this->renderWindow = renderWindow;
	buttons = new std::vector<Button*>;
	std::cout << ("SIZE:" + buttons->size()) << std::endl;
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
	drawButtons();
}

void Window::drawButtons()
{
	for (int i = 0; i < buttons->size(); i++)
	{
		buttons->at(i)->draw(renderWindow);
	}
}

void Window::colourPanel(sf::Color colour)
{
	panel->setOutlineColor(colour);
	drawUI();
}


void Window::addButton(Button* button)
{
	buttons->push_back(button);
}

void Window::addButton(Button* button, std::string text)
{
	buttons->push_back(button);
}





bool Window::isMouseInBounds(sf::Vector2i mouseLocation)
{
	return mouseLocation.x > panel->getPosition().x && mouseLocation.x < panel->getPosition().x + this->getSize()->x
		&& mouseLocation.y > panel->getPosition().y && mouseLocation.y < panel->getPosition().y + this->getSize()->y;
}





void Window::measureCursorRelativeToButtons(sf::Vector2i mouseLocation)
{
	for (int i = 0; i < buttons->size(); i++)
	{
		if (buttons->at(i)->isMouseInBounds(mouseLocation))
		{
			buttons->at(i)->colourButton(sf::Color::Green, renderWindow);
		}
		else
		{
			buttons->at(i)->colourButton(sf::Color::White, renderWindow);
		}
	}
}


void Window::checkForMouseHover()
{
	measureCursorRelativeToButtons(sf::Mouse::getPosition());
	if (isMouseInBounds(sf::Mouse::getPosition()))
	{
		panel->setOutlineColor(sf::Color::Green);
	}
	else
	{
		panel->setOutlineColor(sf::Color::Red);
	}
}


void Window::checkForButtonClick()
{
	int index = 0;
	if (!buttons->empty())
	{
		while (index < buttons->size() && !buttons->at(index)->isMouseInBounds(sf::Mouse::getPosition()))
		{
			index++;
		}
		if (index < buttons->size())
		{
			buttons->at(index)->colourButton(sf::Color::Blue, renderWindow);
		}
	}
}