#pragma once
#include "Vector3.hpp"

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
	void Move(Vector2& newPosition);
	void Render();
	void moveForward(Vector2& newPos);
	void rotateLeft(void);
	void rotateRight(void);
};