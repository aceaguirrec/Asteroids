#pragma once

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Entity.hpp"
#include "Asteroid.hpp"
#include "Bullet.hpp"

using namespace std;

class Player: public Entity {
					
private:
	float shipFrictionFactor;
	bool HasCrashed;
	bool IsThrusterActive;
	bool IsPlayerAlive;
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
	void StopThruster(void);

	void SetShipPoints(void);
	void DrawShip(void);
	void SetThrusterPoints(void);

	Vector2 GetShipPosition(void);
	void SetNewPosition(Vector2 position);
	float GetOrientationAngle(void);
	float GetMass(void);

	void ApplyAcceleration(Vector2 impulse);

	void DistanceLines(Asteroid* asteroid);

	Bullet* FireLasers(void);

	void Collision(Asteroid asteroid);

	bool GetCanPlayerShoot(void);
};
#endif // !_PLAYER_H_