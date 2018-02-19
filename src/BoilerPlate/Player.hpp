#pragma once
#include "Vector2.hpp"
#include <vector>

using namespace std;

/*=================
* Player 
*declaration
=================*/
class Player {
					
private:
	Vector2 position;
	float mass;
	vector <Vector2> thrusterBoostPts;

public:
	Player();

	void Update();
	void Render();

	float Warp(float shipPosition, int borderMinValue, int borderMaxValue);
	void MoveForward(Vector2& newPosition);
	void RotateLeft(void);
	void RotateRight(void);
	bool isThrusterActive;
};