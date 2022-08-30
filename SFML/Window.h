#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"

class Window
{
public:

	Window(sf::RenderWindow*, int , int);
	~Window();
	

	void setPosition(int, int);
	void setSize(int, int);
	void addButton(float, float);
	void addButton(float, float, std::string);
	void drawUI();

private:


	void drawButtons();

	sf::Shape* panel;
	sf::RenderWindow* renderWindow;
	std::vector<sf::Shape> shapeElements;
	std::vector<Button*> buttons;

};

