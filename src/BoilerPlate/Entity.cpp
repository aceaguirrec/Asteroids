#include "Entity.hpp"

//define window border constant values

Entity::Entity(float entityWidth, float entityHeight) {

	entityPosition = new Vector2();
	entityOrientationAngle = 0.0f;
	ScreenCalculations(entityWidth, entityHeight);
}

void Entity::Render(void) {

}

void Entity::Update(float deltaTime) {

	entityPosition->x += entityVelocity->x * deltaTime;
	entityPosition->y += entityVelocity->y * deltaTime;

	entityPosition->x = Warp(entityPosition->x, entityMinWidth, entityMaxWidth);
	entityPosition->y = Warp(entityPosition->y, entityMinHeight, entityMaxHeight);

}

void Entity::MoveForward(void){

}

void Entity::SetEntityPoints(void){

}

void Entity::ScreenCalculations(float entityWidth, float entityHeight){

	float halfEntityWidth = (entityWidth / 2.0f);
	float halfEntityHeight = (entityHeight / 2.0f);

	entityMaxWidth = halfEntityWidth;
	entityMinWidth = (halfEntityWidth * (-1.0f));
	entityMaxHeight = halfEntityHeight;
	entityMinHeight = (halfEntityHeight * (-1.0f));

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

