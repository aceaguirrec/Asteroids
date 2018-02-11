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

//fwd movement function
void Player::moveForward(Vector2 & newPosition){

	position += newPosition;
}

void Player::rotateLeft() {
										//rotation to the left function
	glRotatef(1.0f, 1.0f, 1.0f, 1.0f);
}

void Player::rotateRight() {
										//rotation to the right function
	glRotatef(1.0, -1.0f, -1.0f, -1.0f);
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
}