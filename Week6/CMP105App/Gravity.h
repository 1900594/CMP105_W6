#pragma once
#include"Framework/Vector.h"
#include"Framework/GameObject.h"
#include"Framework/Input.h"
class Gravity : public  Vector, public GameObject, public Input
{
private:
	float scale;
	bool isJumping;
	sf::Vector2f gravity; 
	sf::Vector2f stepVelocity;
	sf::Vector2f jumpVector;
public:

	Gravity();
	void update(float dt);
	void handleInput(float dt);
};

