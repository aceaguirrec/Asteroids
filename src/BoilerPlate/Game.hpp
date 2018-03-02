#pragma once
#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <vector>
#include "Vector2.hpp"
#include "Asteroid.hpp"
#include "Player.hpp"
#include "Bullet.hpp"
#include "InputManager.hpp"
#include "TextManager.hpp"
#include "Entity.hpp"
#include <ctime>
#include <irrKlang.h>
#include <ik_irrKlangTypes.h>



class Game {
private:
	// **********  MEMBERS *********
	Player*							spaceship;
	std::vector<Bullet*>			bullets;
	std::vector<Bullet*>			activeBullets;
	std::vector<Asteroid*>			asteroids;
	int								width;
	int								height;
	float							playerAliveTime;
	float							playerDeadTime;
	int								score;
	int                             lives;
	int								wave;
	int								oneUpCounter;
	TextManager                     feedBackMessages;
	bool                            isDebugMode;
	bool                            isPlayerAlive;
	irrklang::ISoundEngine          *SoundEngine;

public:
	//********* FUNCTIONS ************

	Game();
	Game(int width_, int height_);
	bool CheckCollisionsWithBullets(Asteroid*);
	void CheckAllCollisions(void);
	Player* GetPlayer(void);
	int GetScore(void);
	int	pointsTilOneUp;
	bool OneUp;


	int	GetPlayerStatus(void);
	void RestartGame(void);
	void DrawPlayerLives(void);
	void ShowPlayerLives(void);
	void SpawnAsteroids(void);
	void FireLaser(void);
	void AddAsteroid(void);
	void RemoveAsteroid(void);
	void DebuggingMode(void);
	void DrawDebuggingCircles(void);
	void ResizeWidthAndHeight(int entityWidth, int entityHeight);
	void DrawScore(void);
	void DrawGameOverMessage(void);

	void UpdateGame(float deltaTime);
	void RenderGame(void);

	InputManager inputManager;
	InputManager GetInputManager(void);
	void InputController(void);
	void ResetInputCounter(void);

};
#endif // !GAME_H_INCLUDED