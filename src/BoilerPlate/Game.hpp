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
#include <ctime>
#include <irrKlang.h>
#include <ik_irrKlangTypes.h>



class Game {
private:
	// **********  MEMBERS *********
	Player*							p1;
	std::vector<Bullet*>			bullets;
	std::vector<Bullet*>			activeBullets;
	std::vector<Asteroid*>			asteroids;
	int								width;
	int								height;
	float							playerActiveTime;
	float							playerDeadTime;
	int								score;
	int                             lives;
	int								wave;
	int								getting2000MorePointsCounter;
	TextManager                 userFeedBackMessages;
	bool isDebugMode;
	bool isPlayerAlive;
	irrklang::ISoundEngine *SoundEngine;

public:
	//********* FUNCTIONS ************

	Game();
	Game(int width_, int height_);
	bool CheckCollisionsWithBullets(Asteroid*);
	void CheckAllCollisions();
	Player* getPlayer();
	int getScore();
	int	pointsTil1Up;
	bool addALife;


	int	getPlayerStatus();
	void RestartGame();
	void drawPlayerLives();
	void showPlayerLives();
	void SpawnAsteroids();
	void FireLaser();
	void AddAsteroid();
	void RemoveAsteroid();
	void DebuggingMode();
	void DrawDebuggingCircles();
	void ResizeWidthAndHeight(int entityWidth, int entityHeight);
	void drawScore();
	void drawGameOverMessage();

	void UpdateGame(float deltaTime);
	void RenderGame();

	InputManager iM;
	InputManager GetInputManager();
	void InputController();
	void ResetInputCounter();

};
#endif // !GAME_H_INCLUDED