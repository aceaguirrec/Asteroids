#pragma once
#include "Vector2.hpp"


/*=================
* Player 
*declaration
=================*/
class Player {
					
private:
	Vector2 position;

public:
	Player();
	void Update();
	void Render();
	void move(Vector2& newPosition);
	void moveForward(Vector2& newPos);
	void rotateLeft(void);
	void rotateRight(void);
};