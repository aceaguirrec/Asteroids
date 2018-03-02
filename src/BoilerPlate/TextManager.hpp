#pragma once

#ifndef TEXT_MANAGER_H
#define TEXTMANAGER_H

#include "IncludeSDL.hpp"
#include <string>
#include <iostream>

class TextManager {

public:
	TextManager();
	TTF_Font * m_font;
	int width;
	int height;
	bool Init();
	TextManager(int tWidth, int tHeight);
	void RenderText(std::string message, SDL_Color color, float x, float y);
	unsigned int power_two_floor(unsigned int val);

};
#endif // !TEXT_MANAGER_H