#include "Color.h"

Color::Color(){
	setRed(0.0f);
	setGreen(0.0f);
	setBlue(0.0f);
	setAlpha(0.0f);

}

Color::Color(float redColor, float greenColor, float blueColor, float alphaColor){
	setRed(redColor);
	setGreen(greenColor);
	setBlue(blueColor);
	setAlpha(alphaColor);

}

Color::~Color(){

}

float Color::getRed()
{
	return redColor;
}

float Color::getGreen(){
	return greenColor;
}

float Color::getBlue(){
	return blueColor;
}

float Color::getAlpha(){
	return alphaColor;
}

void Color::setRed(float r){
	redColor = r;
}

void Color::setGreen(float g){
	greenColor = g;
}

void Color::setBlue(float b){
	blueColor = b;
}

void Color::setAlpha(float a){
	alphaColor = a;
}
