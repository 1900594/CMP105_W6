#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	gravityBall = new Gravity();

	ballTexture.loadFromFile("gfx/Beach_Ball.png");
	gravityBall->setTexture(&ballTexture);
	gravityBall->setInput(input);
	gravityBall->setSize(sf::Vector2f(100, 100));
	gravityBall->setPosition(100, 100);
	gravityBall->setVelocity(10, 10);


}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	gravityBall->handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	gravityBall->update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(*gravityBall);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}