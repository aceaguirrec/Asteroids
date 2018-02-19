#include "Player.hpp"
#include "Palette.h"


//define window border constant values
const int windowBottom = -380.0f;
const int windowCeiling = 380.0f;
const int windowLeftBorder = -600.0f;
const int windowRightBorder = 600.0f;

//define rotation speed value
float rotationSpeed = 4.5f;

//define movement speed constant value
const float movementSpeed = 8.0f;

MathUtilities maths;

using namespace std;

Player::Player(){

	SetEntityPoints();
	SetThrusterPoints();
}

void Player::Update(){


}

void Player::SetEntityPoints() {

	entityPoints.push_back(Vector2(0.0f, 20.0f));
	entityPoints.push_back(Vector2(12.0f, -10.0f));
	entityPoints.push_back(Vector2(6.0f, -4.0f));
	entityPoints.push_back(Vector2(-6.0f, -4.0f));
	entityPoints.push_back(Vector2(-12.0f, -10.0f));

}

void Player::SetThrusterPoints() {

	thrusterBoostPts.push_back((Vector2(6.0f, -4.0f)));
	thrusterBoostPts.push_back(Vector2(-6.0f, -4.0f));
	thrusterBoostPts.push_back(Vector2(0.0f, -14.0f));


}
//fwd movement function, continuosly warping
void Player::MoveForward(){

	entityPosition->x -= movementSpeed * sinf(maths.degsToRads(entityOrientationAngle));
	entityPosition->y += (movementSpeed * cosf(maths.degsToRads(entityOrientationAngle)));
	

	entityPosition->x = Warp(entityPosition->x, windowLeftBorder, windowRightBorder);
	entityPosition->y = Warp(entityPosition->y, windowBottom, windowCeiling);
}

void Player::RotateLeft() {
										//rotation to the left function
	entityOrientationAngle += rotationSpeed;
	
}

void Player::RotateRight() {
										//rotation to the right function
	entityOrientationAngle -= rotationSpeed;
}

void Player::IgniteThruster(bool thrustStatus){

	IsThrusterActive = thrustStatus;
}

void Player::DrawThruster() {

	if (IsThrusterActive) {

		glBegin(GL_LINE_LOOP);
		for (int i = 0; i < thrusterBoostPts.size(); i++) {

			glVertex2f(thrusterBoostPts[i].x, thrusterBoostPts[i].y);
		}
		glEnd();
	
	}

}

//player render function
void Player::Render() {

	glLoadIdentity();
	glTranslatef(entityPosition->x, entityPosition->y, 0.0f);
	glRotatef(entityOrientationAngle, 0.0f, 0.0f, 1.0f);
	

	Palette colors = Palette();
	Color bgColor = colors.getPurple();
	glClearColor(bgColor.getRed(), bgColor.getGreen(), bgColor.getBlue(), bgColor.getAlpha());
	glClear(GL_COLOR_BUFFER_BIT);
	
	//draws ship
	DrawEntity();

	//draws thruster booster
	DrawThruster();

}

//player screen warping function
float Player::Warp(float shipPosition, float borderMinValue, float borderMaxValue) {
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

