#pragma once
class Color
{
public:
	//RGB value
	float r = 0;
	float g = 0;
	float b = 0;
	float a = 1;

	//Base color
	static const Color Black;
	static const Color Red;
	static const Color Blue;
	static const Color Green;
	static const Color Yellow;
	static const Color Orange;
	static const Color Purple;
	static const Color White;
	static const Color Gray;
	static const Color Pink;
	static const Color Cyan;
	//Base light color
	static const Color LightGray;
	static const Color LightRed;
	static const Color LightBlue;
	static const Color LightGreen;
	static const Color LightYellow;
	static const Color LightOrange;
	static const Color LightPurple;
	static const Color LightPink;
	static const Color LightCyan;
	//Base dark color
	static const Color DarkGray;
	static const Color DarkRed;
	static const Color DarkBlue;
	static const Color DarkGreen;
	static const Color DarkYellow;
	static const Color DarkOrange;
	static const Color DarkPurple;
	static const Color DarkPink;
	static const Color DarkCyan;

	//Set color
	Color() :r(0), g(0), b(0), a(1) {};
	Color(float pR, float pG, float pB, float pA) : r(pR), g(pG), b(pB), a(pA) {};
};

