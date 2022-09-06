#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Button
{
public:

	Button(sf::Vector2f*);
	Button(sf::Vector2f*, std::string);
	~Button();


	void draw(sf::RenderWindow*);
	bool isMouseInBounds(sf::Vector2i);
	sf::Vector2f* getSize();
	void colourButton(sf::Color, sf::RenderWindow*);

private:

	sf::Vector2f* sizeVector;
	sf::RectangleShape* box;
	std::string text;

};

