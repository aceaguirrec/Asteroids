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
