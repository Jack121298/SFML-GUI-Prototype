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
	void colourPanel(sf::Color colour);
	bool isMouseInBounds(sf::Vector2i);
	sf::Vector2f* getSize();

private:


	void drawButtons();


	sf::Vector2f* location;
	sf::Shape* panel;
	sf::RenderWindow* renderWindow;
	std::vector<sf::Shape> shapeElements;
	std::vector<Button*> buttons;
	
};

