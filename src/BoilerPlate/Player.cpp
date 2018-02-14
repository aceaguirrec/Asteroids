#include "Vector3.hpp"
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>
#include "Player.hpp"
#include "Palette.h"

//define window border constant values
const int windowBottom = -180;
const int windowCeiling = 180;
const int windowLeftBorder = -500;
const int windowRightBorder = 500;

//define rotation angle constant values
float clockwiseAngle = -1.0f;
float counterClockwiseAngle = 1.0f;

//initial player position
Player::Player(){

	position.x = 0;
	position.y = 0;
}

void Player::Update(){


}

//fwd movement function, continuosly warping
void Player::moveForward(Vector2 & newPosition){

	position += newPosition;

	position.x = Warp(position.x, windowLeftBorder, windowRightBorder);
	position.y = Warp(position.y, windowBottom, windowCeiling);
}

void Player::rotateLeft() {
										//rotation to the left function
	//glRotatef(counterClockwiseAngle, 0.0f, 0.0f, 1.0f);
	
}

void Player::rotateRight() {
										//rotation to the right function
	//glRotatef(clockwiseAngle, 0.0f, 0.0f, 1.0f);}
	

//player render function
void Player::Render(){

	glLoadIdentity();

	//glRotatef(clockwiseAngle, 0.0f, 0.0f, 1.0f);
	//glRotatef(counterClockwiseAngle, 0.0f, 0.0f, 1.0f);

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

}

//player screen warping function
float Player::Warp(float shipPosition, int borderMinValue, int borderMaxValue) {
	/*
	if player exits screen from (bottom)/(left) of screen
	player reappears same (x)/(y) position 
	from (top)/(right) of screen
	*/
	if (shipPosition < borderMinValue) {

		shipPosition = borderMaxValue + (borderMinValue - shipPosition);  
		return shipPosition;
	}
	/*
	if player exits screen from (top)/(right)
	player reappears same (x)/(y) position
	from (bottom)/(left) of screen
	*/
	if (shipPosition > borderMaxValue) {
	
		shipPosition = borderMinValue - (shipPosition - borderMaxValue);
		return shipPosition;
	}

	return shipPosition;
}

