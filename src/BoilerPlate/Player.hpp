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
<<<<<<< HEAD
	void moveForward(Vector2& newPosition);
	void rotateLeft(void); 
	void rotateRight(void);
	bool activateThruster;
	void thruster();


=======
	void moveForward(Vector2& newPos);
	void rotateLeft(void);
	void rotateRight(void);
>>>>>>> 7468a11406112f23826e09f73f5710e4d62b1aae
};