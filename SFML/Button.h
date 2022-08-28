#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Button
{
public:

	Button();
	~Button();


private:


	const sf::RectangleShape box;
	const std::string text;

};

