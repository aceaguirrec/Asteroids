#include "Entity.hpp"

//define window border constant values
const int windowBottom = -280.0f;
const int windowCeiling = 280.0f;
const int windowLeftBorder = -500.0f;
const int windowRightBorder = 500.0f;

Entity::Entity() {

	entityPosition = new Vector2();
	entityOrientationAngle = 0.0f;
}

void Entity::Render(void) {

}

void Entity::Update(void) {

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

		entityCoordinate = borderMaxValue + (borderMinValue - entityCoordinate);
		return entityCoordinate;
	}
	
	if (entityCoordinate > borderMaxValue) {

		entityCoordinate = borderMinValue - (entityCoordinate - borderMaxValue);
		return entityCoordinate;
	}

	return entityCoordinate;
}

