#include "Player.hpp"
#include "Palette.h"


//define rotation speed value
float rotationSpeed = 4.5f;

//define speed constant values
const float movementSpeed = 8.0f;
const float maxMovementSpeed = 350.0f;

MathUtilities shipMaths;

using namespace std;

Player::Player(float pWidth, float pHeight){

	
	entityPosition = Vector2();
	entityOrientationAngle = 0.0f;
	entityMass = 5.0f;
	shipFrictionFactor = 0.999f;
	entityRadius = 24.0f;
	IsThrusterActive = false;
	HasCrashed = false;
	SetShipPoints();
	SetThrusterPoints();
}

void Player::Update(float deltaTime){

	entitySpd = entityVelocity.vLength();


	if (!IsThrusterActive) {
		entityVelocity.x = ((entityVelocity.x / entitySpd) * shipFrictionFactor);
		entityVelocity.y = ((entityVelocity.y / entitySpd) * shipFrictionFactor);
	}
	

	if (entitySpd > maxMovementSpeed) {

		entityVelocity.x = ((entityVelocity.x / entitySpd) * maxMovementSpeed);
		entityVelocity.y = ((entityVelocity.y / entitySpd) * maxMovementSpeed);
	
	}

	Entity::Update(deltaTime);
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

Vector2 Player::GetShipPosition(void){

	return entityPosition;
}

void Player::SetNewPosition(Vector2 newPosition){

	entityPosition = newPosition;
}

float Player::GetOrientationAngle(){

	return entityOrientationAngle;
}

float Player::GetMass(){

	return entityMass;
}

void Player::ApplyAcceleration(Vector2 impulse){

	entityVelocity.x += (impulse.x / entityMass) * cosf(shipMaths.degsToRads(entityOrientationAngle + 45));
	entityVelocity.y += (impulse.y / entityMass) * sinf(shipMaths.degsToRads(entityOrientationAngle + 45));
}

void Player::DistanceLines(Asteroid * asteroid){

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, 0.0f);
	glRotatef(0.0, 0.0, 0.0, 1.0);

	float distanceToAsteroid = sqrt(((entityPosition.x - asteroid->GetAsteroidPosition().x)*(entityPosition.x - asteroid->GetAsteroidPosition().x)) 
		+ ((entityPosition.y - asteroid->GetAsteroidPosition().y)*(entityPosition.y - asteroid->GetAsteroidPosition().y)));

	if (distanceToAsteroid < 480) {

		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_LINE_STRIP);
		glVertex2f(entityPosition.x, entityPosition.y);
		glVertex2f(asteroid->GetAsteroidPosition().x, asteroid->GetAsteroidPosition().y);
		glEnd();
	}
}

Bullet * Player::FireLasers(void){

	Bullet* laserShot = new Bullet(entityWidth, entityHeight);

	laserShot->ShotStatus(Vector2(500.0f, 500.0f), entityPosition, (entityOrientationAngle + 45));

	return laserShot;
}

void Player::Collision(Asteroid asteroid){

	float distanceToAsteroid = GetDistanceBtwn2Entities((asteroid.GetEntityPosition));

	if (distanceToAsteroid <= (entityRadius + asteroid.GetEntityRadius)) {
		
		isColliding = true;
		asteroid.SetCollidingStatus(true);
	}
}
bool Player::GetCanPlayerShoot(void){

	if (IsPlayerAlive) return true;
}
//fwd movement function, continuosly warping
void Player::MoveForward(){

	ApplyAcceleration(Vector2(movementSpeed, movementSpeed));
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

void Player::StopThruster(void){

	IsThrusterActive = false;
}

//player render function
void Player::Render() {

	glLoadIdentity();
	glTranslatef(entityPosition.x, entityPosition.y, 0.0f);
	glRotatef(entityOrientationAngle, 0.0f, 0.0f, 1.0f);
	

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

