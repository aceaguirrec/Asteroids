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

	shipPosition = new Vector2();
	shipOrientationAngle = 0.0f;
	shipMass = 5.0f;
	shipFrictionFactor = 2.5f;
	SetShipPoints();
	SetThrusterPoints();
}

void Player::Update(){


}

void Player::SetShipPoints() {

	shipPts.push_back(Vector2(0.0f, 20.0f));
	shipPts.push_back(Vector2(12.0f, -10.0f));
	shipPts.push_back(Vector2(6.0f, -4.0f));
	shipPts.push_back(Vector2(-6.0f, -4.0f));
	shipPts.push_back(Vector2(-12.0f, -10.0f));

}

void Player::SetThrusterPoints() {

	thrusterBoostPts.push_back((Vector2(6.0f, -4.0f)));
	thrusterBoostPts.push_back(Vector2(-6.0f, -4.0f));
	thrusterBoostPts.push_back(Vector2(0.0f, -14.0f));


}
//fwd movement function, continuosly warping
void Player::MoveForward(){

	shipPosition->x -= ((movementSpeed * 0.999) * sinf(maths.degsToRads(shipOrientationAngle)));
	shipPosition->y += ((movementSpeed * 0.999) * cosf(maths.degsToRads(shipOrientationAngle)));
	

	shipPosition->x = Warp(shipPosition->x, windowLeftBorder, windowRightBorder);
	shipPosition->y = Warp(shipPosition->y, windowBottom, windowCeiling);
}

void Player::RotateLeft() {
										//rotation to the left function
	shipOrientationAngle += rotationSpeed;
	
}

void Player::RotateRight() {
										//rotation to the right function
	shipOrientationAngle -= rotationSpeed;
}

void Player::IgniteThruster(bool thrustStatus){

	IsThrusterActive = thrustStatus;
}

void Player::DrawShip() {

	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < shipPts.size(); i++) {

		glVertex2f(shipPts[i].x, shipPts[i].y);
	}
	glEnd();

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
	glTranslatef(shipPosition->x, shipPosition->y, 0.0f);
	glRotatef(shipOrientationAngle, 0.0f, 0.0f, 1.0f);
	

	Palette colors = Palette();
	Color bgColor = colors.getPurple();
	glClearColor(bgColor.getRed(), bgColor.getGreen(), bgColor.getBlue(), bgColor.getAlpha());
	glClear(GL_COLOR_BUFFER_BIT);
	
	//draws ship
	DrawShip();

	//draws thruster booster
	DrawThruster();

}

//player screen warping function
float Player::Warp(float shipCoordinate, float borderMinValue, float borderMaxValue) {
	/*
	** if player exits screen from (bottom)/(left) of screen
	** player reappears same (x)/(y) position 
	** from (top)/(right) of screen
	*/
	if (shipCoordinate < borderMinValue) {

		shipCoordinate = borderMaxValue - (borderMinValue - shipCoordinate);  
		return shipCoordinate;
	}
	/*
	** if player exits screen from (top)/(right)
	** player reappears same (x)/(y) position
	** from (bottom)/(left) of screen
	*/
	if (shipCoordinate > borderMaxValue) {
	
		shipCoordinate = borderMinValue + (shipCoordinate - borderMaxValue);
		return shipCoordinate;
	}

	return shipCoordinate;
}

