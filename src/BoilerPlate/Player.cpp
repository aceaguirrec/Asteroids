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

//player movement function
void Player::Move(Vector2 & newPosition){

	position += newPosition;
}

//player render function
void Player::Render(){

	Palette colors = Palette();
	Color bgColor = colors.getPurple();
	glClearColor(bgColor.getRed(), bgColor.getGreen(), bgColor.getBlue(), bgColor.getAlpha());
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_LINE_LOOP);
	glVertex2f(50.0 + position.x, 50.0 + position.y);
	glVertex2f(50.0 + position.x, -50.0 + position.y);
	glVertex2f(-50.0 + position.x, -50.0 + position.y);
	glVertex2f(-50.0 + position.x, 50.0 + position.y);
	glEnd();
}