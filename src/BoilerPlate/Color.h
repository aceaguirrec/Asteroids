#pragma once
class Color {

private:
	float redColor;
	float greenColor;		//RGBA 
	float blueColor;
	float alphaColor;

public:
	Color();
	Color(float redColor, float greenColor, float blueColor, float alphaColor);
	~Color();


	float getRed();
	float getGreen();		//getters
	float getBlue();
	float getAlpha();

	void setRed(float r);
	void setGreen(float g);		//setters
	void setBlue(float b);
	void setAlpha(float a);

};