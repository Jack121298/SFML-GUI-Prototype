#pragma once
#include <SFML/Graphics.hpp>

class Window
{
public:

	Window();
	~Window();

private:

	sf::RectangleShape* left;
	sf::RectangleShape* right;
	sf::RectangleShape* up;
	sf::RectangleShape* down;

};

