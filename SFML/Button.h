#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Button
{
public:

	Button(sf::Vector2f);
	Button(sf::Vector2f, std::string);
	~Button();


	void draw(sf::RenderWindow*);


private:


	const sf::RectangleShape* box;
	std::string text;

};

