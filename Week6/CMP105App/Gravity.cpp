#include "Gravity.h"
Gravity::Gravity()
{
	scale = 200.0f;
	gravity = sf::Vector2f(0, 9.8f) * scale;
	jumpVector = sf::Vector2f(0, -4.0f) * scale;
	isJumping = false;
}

void Gravity::update(float dt)
{
	//Apply gravity force, increasing velocity
	//Move shape by new velocity

	stepVelocity += gravity * dt;
	sf::Vector2f pos = stepVelocity * dt + 0.5f * gravity * dt * dt;
	setPosition(getPosition() + pos);

	if (getPosition().y >= 500)
	{
		isJumping = false;
		setPosition(getPosition().x, 500);
		stepVelocity = sf::Vector2f(0, 0);

	}
}

void Gravity::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Space))
	{
		if (!isJumping)
		{
			stepVelocity = jumpVector;
			isJumping = true;
		}
	}



	if (input->isKeyDown(sf::Keyboard::Left))
	{
		setPosition(input->getMouseX(),input->getMouseY());
	}




}