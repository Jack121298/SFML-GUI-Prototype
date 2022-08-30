#pragma once
#include <SFML/Graphics.hpp>

class Window
{
public:

	Window(sf::RenderWindow*, int , int);
	~Window();
	

	void setPosition(int, int);
	void setSize(int, int);
	void addButton();
	void drawUI();

private:

	sf::Shape* panel;
	sf::RenderWindow* renderWindow;


};

