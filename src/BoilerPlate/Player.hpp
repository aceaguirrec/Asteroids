#pragma once

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Entity.hpp"

using namespace std;

/*=================
* Player 
*declaration
=================*/
class Player: public Entity {
					
private:
	Vector2* shipPosition;
	float shipOrientationAngle;
	float shipMass;
	float shipFrictionFactor;
	vector <Vector2> shipPts;
	vector <Vector2> thrusterBoostPts;

public:
	Player(float entityWidth, float entityHeight);

	void Update(void) override;
	void Render(void) override;

	float Warp(float shipPosition, float borderMinValue, float borderMaxValue);
	void MoveForward(void) override;
	void RotateLeft(void);
	void RotateRight(void);
	void IgniteThruster(bool);
	bool IsThrusterActive;
	bool IsMoving;
	void DrawThruster(void);
	void SetShipPoints(void);
	void DrawShip(void);
	void SetThrusterPoints(void);
};
#endif // !_PLAYER_H_