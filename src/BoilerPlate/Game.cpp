#include "Game.hpp"
#include "TextManager.hpp"

const int smallAsteroid = 1;
const int mediumAsteroid = 2;
const int bigAsteroid = 3;
const float timeUntilPlayerCanDieOrRespawn = 300;

Game::Game() {

}

Game::Game(int width_, int height_) {
	srand(time(NULL));
	spaceship = new Player(width_, height_);
	wave = 1;
	for (int i = 0; i < 4 + wave; i++) {
		asteroids.push_back(new Asteroid(width_, height_, 'l'));
	}
	feedBackMessages.Init();
	feedBackMessages = TextManager(width, height);
	isDebugMode = false;
	height = height_;
	width = width_;
	playerAliveTime = 0;
	playerDeadTime = 0;
	score = 0;
	lives = 3;
	OneUp = false;
	pointsTilOneUp = 3000;
	oneUpCounter = 0;

	SoundEngine = irrklang::createIrrKlangDevice();
	SoundEngine->setSoundVolume(1.0f);
}

bool Game::CheckCollisionsWithBullets(Asteroid* asteroid) {

	bool hasCollided = false;
	std::vector <Bullet*> remainingAsteroids;

	for (int i = 0; i < bullets.size(); i++) 
		if (asteroid->GetCollidingStatus(bullets[i])) {

			hasCollided = true;
			if (asteroid->GetAsteroidSize() == smallAsteroid) score += 100;
			else if (asteroid->GetAsteroidSize() == mediumAsteroid) score += 50;
			else if (asteroid->GetAsteroidSize() == smallAsteroid) score += 25;
		}
		else remainingAsteroids.push_back(bullets[i]);
	}
	
	bullets = remainingAsteroids;

	return hasCollided;
}


void Game::CheckAllCollisions() {
	if (!isDebugMode) {
		std::vector <Asteroid*> remainingAsteroids;
		for (int i = 0; i < asteroids.size(); i++) {
			if (CheckCollisionsWithBullets(asteroids[i])) {
				if (asteroids[i]->GetAsteroidSize() == bigAsteroid) {
					Asteroid * firstDivision = asteroids[i];
					score += 100;
					firstDivision->setSize(mediumAsteroid);

					Asteroid* secondDivision = new Asteroid(width, height, mediumAsteroid);
					Vector2 pos = firstDivision->getPosition();
					secondDivision->SetNewPosition(pos);

					remainingAsteroids.push_back(firstDivision);
					remainingAsteroids.push_back(secondDivision);
				}
				else if (asteroids[i]->GetAsteroidSize() == mediumAsteroid) {
					Asteroid* firstDivision = asteroids[i];
					firstDivision->setSize(smallAsteroid);
					score += 50;
					Asteroid* secondDivision = new Asteroid(width, height, smallAsteroid);
					Vector2 pos = firstDivision->GetEntityPosition();
					secondDivision->SetNewPosition(pos);

					remainingAsteroids.push_back(firstDivision);
					remainingAsteroids.push_back(secondDivision);
				}
			}
			else remainingAsteroids.push_back(asteroids[i]);

			if (asteroids[i]->Collision(spaceship) && playerAliveTime>timeTilPlayerCanDieOrRespawn) {
				isPlayerAlive = false;
				playerAliveTime = 0;
				lives -= 1;
			}
		}
		asteroids = remainingAsteroids;
	}

}


Player* Game::GetPlayer() {
	return spaceship;
}

int Game::GetPlayerStatus() {
	return lives;
}

void Game::RestartGame() {
	isPlayerAlive = true;
	bullets.clear();
	asteroids.clear();
	activeBullets.clear();
	lives = 3;
	score = 0;
	wave = 1;
	pointsTilOneUp = 1000;

}

int Game::GetScore() {
	return score;
}



void Game::DrawPlayerLives() {

	glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(0.0 * 10, -1.7 * 10);
	glVertex2f(1.0 * 10, -1.0 * 10);
	glVertex2f(1.8 * 10, 0.0 * 10);
	glVertex2f(2.0 * 10, 0.6 * 10);
	glVertex2f(1.5 * 10, 1.5 * 10);
	glVertex2f(1.0 * 10, 1.8 * 10);
	glVertex2f(0.5 * 10, 1.65 * 10);
	glVertex2f(0.0 * 10, 1.1 * 10);
	glVertex2f(-0.5 * 10, 1.65 * 10);
	glVertex2f(-1.0 * 10, 1.8 * 10);
	glVertex2f(-1.5 * 10, 1.5 * 10);
	glVertex2f(-2.0 * 10, 0.6 * 10);
	glVertex2f(-1.8 * 10, 0.0 * 10);
	glVertex2f(-1.0 * 10, -1.0 * 10);
	glVertex2f(0.0 * 10, -1.7 * 10);
	glEnd();
}

void Game::ShowPlayerLives() {
	int distance = 0;
	for (int i = 0; i < lives; i++) {
		glLoadIdentity();
		glTranslatef((width / 2) - 48 + distance, (height / 2) - 30, 0.0);
		drawPlayerLives();
		distance -= 50;
	}

}


void Game::FireLaser() {
	if (isPlayerAlive) {
		if (bullets.size() < 10) {
			bullets.push_back(spaceship->FireLasers());
			SoundEngine->play2D("Fire.wav");
		}
	}
}

void Game::AddAsteroid() {
	asteroids.push_back(new Asteroid(width, height, bigAsteroid));
}

void Game::SpawnAsteroids() {

	for (int i = 0; i < 4 + wave; i++) {
		asteroids.push_back(new Asteroid(width, height, bigAsteroid));
	}
}

void Game::RemoveAsteroid() {

	if (asteroids.size()>0) {

		asteroids.pop_back();
	}
}


void Game::DebuggingMode() {

	if (isDebugMode == false) isDebugMode = true;
	else if (isDebugMode == true) isDebugMode = false;
}


void Game::UpdateGame(float deltaTime) {
	if (isPlayerAlive) {
		spaceship->Update(deltaTime);
	}
	if (asteroids.size() == 0) {
		wave += 1;
		SpawnAsteroids();
	}

	for (int i = 0; i < asteroids.size(); i++) {
		asteroids[i]->Update(deltaTime);
	}

	std::vector <Bullet*> activeBullets;
	for (auto bullet : bullets) {
		bullet->Update(deltaTime);
		if (!bullet->IsInFlight()) activeBullets.push_back(bullet);
	}
	bullets = activeBullets;

	if (playerDeadTime > timeTilPlayerCanDieOrRespawn && lives >0) {

		spaceship->SetNewPosition(Vector2::Origin);
		isPlayerAlive = true;
		playerDeadTime = 0;
	}
	if (isPlayerAlive) {
		playerAliveTime++;
	}
	else {
		playerDeadTime++;
	}


	if (score > pointsTilOneUp + (oneUpCounter * 1000)) {
		oneUpCounter++;
		OneUp = true;
		if (OneUp = true) lives++;
		OneUp = false;
	}


}

void Game::DrawScore() {
	SDL_Color black;
	black.r = 0;
	black.g = 0;
	black.b = 0;
	black.a = 0;

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	userFeedBackMessages.RenderText(std::to_string(score), black, (width / 2) - 148, (height / 2) - 120);

}


void Game::DrawGameOverMessage() {
	SDL_Color black;
	black.r = 0;
	black.g = 0;
	black.b = 0;
	black.a = 0;

	userFeedBackMessages.RenderText("GAME OVER", black, -100.0, -25.0);
	userFeedBackMessages.RenderText("Press R to play again   -  Press ESC to exit", black, -420.0, -100.0);

}






void Game::RenderGame() {
	if (isPlayerAlive) {
		spaceship->Render();
	}
	showPlayerLives();
	for (int i = 0; i < asteroids.size(); i++) {
		asteroids[i]->Render();
	}
	for (auto bullet : bullets) bullet->Render();

}

InputManager Game::GetInputManager(){

	return inputManager;
}

void Game::InputController(){

	if (inputManager.GetW()) {

		player->moveForward();
		player->IgniteThruster(true);
		soundManager->play2D("sound/thrust.wav");
	}
	else {

		player->IgniteThruster(false);
	}

	if (inputManager.GetA()) {

		player->RotateLeft();
	}

	if (inputManager.GetD()) {

		player->RotateRight();
	}

	if (inputManager.GetL() && inputCounter == 0) {

		RemoveAsteroid();

		ResetInputCounter();
	}

	if (inputManager.GetM() && inputCounter == 0) {

		AddAsteroid();

		ResetInputCounter();
	}

	if (inputManager.GetG() && inputCounter == 0) {

		DebuggingMode();

		ResetInputCounter();
	}

	if (inputManager.GetF() && inputCounter == 0) {

		ToggleFramerate();

		ResetInputCounter();
	}

	if (inputManager.GetY()) {

		if (playerRemainingLives == 0) {

			ResetGame();
		}
	}

	if (inputManager.GetSpace() && inputCounter == 0) {

		if (Player->GetCanPlayerShoot() == true) {

			FireLaser();

			ResetInputCounter();
		}
	}

}

void Game::ResetInputCounter(){

	inputCounter = 10;
}

void Game::DrawDebuggingCircles() {
	if (isDebugMode == true) {
		spaceship->DrawDebuggingCircles();
		for (auto bullet : bullets) {
			bullet->DrawDebuggingCircles();
		}
		for (int i = 0; i < asteroids.size(); i++) {
			asteroids[i]->DrawDebuggingCircles();
			spaceship->DistanceLines(asteroids[i]);
		}
	}

}


void Game::ResizeWidthAndHeight(int width_, int height_) {
	height = height_;
	width = width_;
	spaceship->resizeWidthAndHeight(width_, height_);
	for (int i = 0; i < asteroids.size(); i++) {
		asteroids[i]->resizeWidthAndHeight(width_, height_);
	}

	for (int i = 0; i < bullets.size(); i++) {
		bullets[i]->resizeWidthAndHeight(width_, height_);
	}

}