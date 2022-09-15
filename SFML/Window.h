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
	void addButton(Button* button);
	void addButton(Button* button, std::string);
	void firstRender();
	void drawUI();
	void colourPanel(sf::Color colour);
	bool isMouseInBounds(sf::Vector2i);
	void measureCursorRelativeToButtons(sf::Vector2i mouseLocation);
	void checkForButtonClick();
	void checkForMouseHover();
	sf::Vector2f* getSize();

private:





	void drawButtons();


	sf::Vector2f* sizeVector;
	sf::Shape* panel;
	sf::RenderWindow* renderWindow;
	std::vector<sf::Shape> shapeElements;
	std::vector<Button*>* buttons;
	
};

