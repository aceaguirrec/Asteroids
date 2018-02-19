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
	vector <Vector2> thrusterBoostPts;

public:
	Player();

	void Update(void) override;
	void Render(void) override;

	float Warp(float shipPosition, float borderMinValue, float borderMaxValue);
	void MoveForward(void) override;
	void RotateLeft(void);
	void RotateRight(void);
	void IgniteThruster(bool);
	bool IsThrusterActive = false;
	void DrawThruster(void);
	void SetEntityPoints(void) override;
	void SetThrusterPoints(void);
};
#endif // !_PLAYER_H_