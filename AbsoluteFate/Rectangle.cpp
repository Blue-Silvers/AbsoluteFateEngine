#include "Rectangle.h"

const Rectangle Rectangle::NullRect({ 0.0f,0.0f }, { 0.0f,0.0f });

Rectangle::Rectangle(Vector2 pPosition, Vector2 pDimensions)
{
	position = pPosition;
	dimensions = pDimensions;
}

bool Rectangle::operator==(const Rectangle& other) const
{
	return position.x == other.position.x &&
		   position.y == other.position.y &&
		   dimensions.x == other.dimensions.x &&
		   dimensions.y == other.dimensions.y;
}

bool Rectangle::operator!=(const Rectangle& other) const
{
	return !(*this == other);
}