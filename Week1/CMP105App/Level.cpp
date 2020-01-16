#include "Level.h"
#include <iostream>

Level::Level(sf::RenderWindow* hwnd)
{
	window = hwnd;

	// initialise game objects
	for (int i = 2; i >= 0; i--) {
		switch (i) {
			case 2:
				rect[i].setFillColor(sf::Color::Red);
				break;
			case 1:
				rect[i].setFillColor(sf::Color::Green);
				break;
			case 0:
				rect[i].setFillColor(sf::Color::Blue);
				break;
			default:
				break;
		}
		rect[i].setSize(sf::Vector2f(50 * (1 + i), 50 * (1 + i)));
		rect[i].setPosition(100 - (i * 25), 100 - (i * 25));
	}

	circle.setFillColor(sf::Color::Blue);
	circle.setOutlineColor(sf::Color::Red);
	circle.setRadius(50);
	circle.setPosition(window->getSize().x * .5, window->getSize().y * .5);
	
	if (!font.loadFromFile("font/arial.ttf")) {
		std::cout << "Error loading font!" << std::endl;
	}

	text.setFillColor(sf::Color::Red);
	text.setFont(font);
	text.setPosition(window->getSize().x * .5, 0);
	text.setString("Hello World");
}

Level::~Level()
{
}

// handle user input
void Level::handleInput()
{

}

// Update game objects
void Level::update()
{
	int offset = 100;
	for (int i = 2; i >= 0; i--) {
		rect[i].setPosition(window->getSize().x - (i * 25) - offset, window->getSize().y - (i * 25) - offset);
	}
}

// Render level
void Level::render()
{
	beginDraw();
	for (int i = 2; i >= 0; i--) {
		window->draw(rect[i]);
	}
	window->draw(circle);
	window->draw(text);
	endDraw();
}

void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}