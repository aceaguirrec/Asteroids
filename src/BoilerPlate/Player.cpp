#include "Vector3.hpp"
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>
#include "Player.hpp"
#include "Palette.h"

//initial player position
Player::Player(){

	position.x = 0;
	position.y = 0;
}

void Player::Update(){


}

<<<<<<< HEAD
//fwd movement function
void Player::moveForward(Vector2 & newPosition){

	position += newPosition;
}
=======
>>>>>>> 7468a11406112f23826e09f73f5710e4d62b1aae

void Player::rotateLeft() {
										//rotation to the left function
	glRotatef(1.0f, 1.0f, 1.0f, 1.0f);
}

void Player::rotateRight() {
										//rotation to the right function
	glRotatef(1.0, -1.0f, -1.0f, -1.0f);
}

void Player::thruster() {

	glBegin(GL_LINE_LOOP);
	glVertex2f(-6.0f, -7.0f);
	glVertex2f(6.0f, -7.0f);
	glVertex2f(0.0f, -15.0f);
	glEnd();
}

//player render function
void Player::Render(){

	Palette colors = Palette();
	Color bgColor = colors.getPurple();
	glClearColor(bgColor.getRed(), bgColor.getGreen(), bgColor.getBlue(), bgColor.getAlpha());
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_LINE_LOOP);
	glVertex2f(0.0 + position.x, 20.0 + position.y);
	glVertex2f(12.0 + position.x, -10.0 + position.y);
	glVertex2f(6.0 + position.x, -4.0 + position.y);
	glVertex2f(-6.0 + position.x, -4.0 + position.y);
	glVertex2f(-12.0 + position.x, -10.0 + position.y);
	glEnd();
<<<<<<< HEAD

	if (activateThruster == true) thruster();		//checks if thruster is active and draws it if true
}
=======
}

//player movement function
void Player::moveForward(Vector2& newPos){

	position += newPos;
}

//player rotation function (to the left from the ship's POV)
void Player::rotateLeft() {

	glRotatef(10.0f, 0.0f, 0.0f, 1.0f);
}

//player rotation function (to the right from the ship's POV)
void Player::rotateRight() {

	glRotatef(10.0f, 0.0f, 0.0f, 1.0f);
}
>>>>>>> 7468a11406112f23826e09f73f5710e4d62b1aae
