#include "Bullet.hpp"
#include "MathUtilities.h"


Bullet::Bullet(float bWidth, float bHeight){

	remainingBulletLifeSpan = 50;
	entityRadius = 3.0f;
	entityMass = 1.0f;
	SetBulletPoints();
}

bool Bullet::isInFlight(void){

	if(remainingBulletLifeSpan >= maxBulletLifeSpan)
		return true;
}

void Bullet::SetBulletPoints(void){

	bulletPts.push_back(Vector2(0.0f, 1.0f));
	bulletPts.push_back(Vector2(1.0f, 1.0f));
	bulletPts.push_back(Vector2(1.0f, 0.0f));
	bulletPts.push_back(Vector2(1.0f, -1.0f));
	bulletPts.push_back(Vector2(0.0f, -1.0f));
	bulletPts.push_back(Vector2(-1.0f, -1.0f));
	bulletPts.push_back(Vector2(-1.0f, 0.0f));
	bulletPts.push_back(Vector2(-1.0f, 1.0f));

}

void Bullet::DrawBullet(void){

	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < bulletPts.size(); i++) {

		glVertex2f(bulletPts[i].x, bulletPts[i].y);
	}
	glEnd();
}

void Bullet::Update(float deltaTime){

	remainingBulletLifeSpan--;
	Entity::Update(deltaTime);
}

void Bullet::Render(void){

	glLoadIdentity();
	glTranslatef(entityPosition.x, entityPosition.y, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);

	DrawBullet();

}

void Bullet::ShotStatus(Vector2 impulse, Vector2 bulletPosition, int bulletAngle){
	
	MathUtilities bulletMaths;

	entityOrientationAngle = bulletAngle;
	entityPosition = bulletPosition;

	float velocityInX = impulse.x * cosf(bulletMaths.degsToRads(entityOrientationAngle));
	float velocityInY = impulse.y * sinf(bulletMaths.degsToRads(entityOrientationAngle));

	entityVelocity.x = (velocityInX / entityMass);
	entityVelocity.y = (velocityInY / entityMass);
}
