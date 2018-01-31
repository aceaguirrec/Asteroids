#pragma once
#include "Color.h"

static class Palette {

public:
	Palette();
	~Palette();
	Color getYellow();
	Color getWhite();
	Color getPurple();
	Color getRed();
	Color getOrange();


private:
	Color yellow;
	Color white;
	Color purple;
	Color red;
	Color orange;

};
