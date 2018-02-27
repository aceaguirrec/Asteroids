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
	bool IsThrusterActive;
	vector <Vector2> shipPts;
	vector <Vector2> thrusterBoostPts;

public:
	Player(float pWidth, float pHeight);

	void Update(float deltaTime);
	void Render(void) override;

	float Warp(float shipPosition, float borderMinValue, float borderMaxValue);
	void MoveForward(void) override;
	void RotateLeft(void);
	void RotateRight(void);

	void IgniteThruster(bool);
	void DrawThruster(void);

	void SetShipPoints(void);
	void DrawShip(void);
	void SetThrusterPoints(void);

	float GetOrientationAngle();
	float GetMass();

	void applyAcceleration(Vector2 impulse);
};
#endif // !_PLAYER_H_