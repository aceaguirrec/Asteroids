#include "Entity.hpp"

//define window border constant values

Entity::Entity() {

}

Entity::Entity(float eWidth, float eHeight){

	entityWidth = eWidth;
	entityHeight = eHeight;
	entityOrientationAngle = 0.0f;
}

Vector2 Entity::GetEntityPosition(void){

	return entityPosition;
}


float Entity::GetEntityRadius(){

	return entityRadius;
}

float Entity::GetDistanceBtwn2Entities(Vector2 position){

	return sqrt(pow(2, (entityPosition.x - position.x)) + pow(2, (entityPosition.y - position.y)));
}

void Entity::Render(void) {

}

void Entity::Update(float deltaTime) {

	entityPosition.x += (entityVelocity.x * deltaTime);
	entityPosition.y += (entityVelocity.y * deltaTime);

	entityPosition.x = Warp(entityPosition.x, (entityWidth / 2.0f), ((-1.0f * entityWidth) / 2.0f));
	entityPosition.y = Warp(entityPosition.y, (entityHeight / 2.0f), ((-1.0f * entityHeight) / 2.0f));

}

void Entity::MoveForward(void){

}

void Entity::SetEntityPoints(void){

}


void Entity::DrawEntity(void){

	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < entityPoints.size(); i++) {

		glVertex2f(entityPoints[i].x, entityPoints[i].y);
	}
	glEnd();
}

float Entity::Warp(float entityCoordinate, float borderMinValue, float borderMaxValue) {
	
	if (entityCoordinate < borderMinValue) {

		entityCoordinate = borderMaxValue - (borderMinValue - entityCoordinate);
		return entityCoordinate;
	}
	
	if (entityCoordinate > borderMaxValue) {

		entityCoordinate = borderMinValue + (entityCoordinate - borderMaxValue);
		return entityCoordinate;
	}

	return entityCoordinate;
}

void Entity::DrawDebuggingCircle(void){

	int circleLines = 100;

	float piTwice = 2.0f * 3.14159f;

	glLoadIdentity();
	glColor3f(1.0, 0.0, 0.0);

	glBegin(GL_LINE_LOOP);
	for (int i = 0; i <= circleLines; i++) {


		glVertex2f(

			entityPosition.x + (entityRadius * cosf(i *  piTwice / circleLines)),
			entityPosition.y + (entityRadius * sinf(i * piTwice / circleLines))

		);
	}
	glEnd();
}

void Entity::SetCollidingStatus(bool collidingStatus){

	isColliding = collidingStatus;
}

void Entity::SetDebuggingStatus(bool debuggingStatus){

	isDebugging = debuggingStatus;
}

