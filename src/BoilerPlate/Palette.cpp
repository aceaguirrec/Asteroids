#include "Palette.h"

Palette::Palette(){
	yellow = Color(1.000f, 1.000f, 0.000f, 1.0f);
	white = Color(1.0, 1.0, 1.0, 1.0);
	purple = Color(0.502f, 0.000f, 0.502f, 1.0f);
	red = Color(1.0, 0.0, 0.0, 1.0);
	orange = Color(1.000f, 0.647f, 0.000f, 1.0f);

}

Palette::~Palette(){

}

Color Palette::getYellow(){
	return yellow;
}

Color Palette::getWhite(){
	return white;
}

Color Palette::getPurple(){
	return purple;
}

Color Palette::getRed(){
	return red;
}

Color Palette::getOrange(){
	return orange;
}
