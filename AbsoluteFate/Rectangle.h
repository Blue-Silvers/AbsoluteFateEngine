#pragma once
#include <SDL_rect.h>
#include "Vector2D.h"

//Enum of rectangle face
enum FaceHit 
{
    UP,
    DOWN,
    RIGHT,
    LEFT,
    NONE
};

struct Rectangle
{
    Rectangle(Vector2D pPosition = Vector2D::Zero, Vector2D pDimensions = Vector2D::One);

    Vector2D position;
    Vector2D dimensions;


    //Operators
    bool operator==(const Rectangle& other) const;
    bool operator!=(const Rectangle& other) const;

    static const Rectangle NullRect;

    //Draw rectangle
    SDL_Rect ToSdlRect() const
    {
        return SDL_Rect{
            static_cast<int>(position.x),
            static_cast<int>(position.y),
            static_cast<int>(dimensions.x),
            static_cast<int>(dimensions.y) };
    }

    //Check if this rectangle hit another rectangle
    bool RectCollide(Rectangle& other) const 
    {
        if (position.y < other.position.y + other.dimensions.y && position.y + dimensions.y > other.position.y
            && position.x < other.position.x + other.dimensions.x && position.x + dimensions.x > other.position.x) 
        {
            return true;
        }
        
        return false;
    };

    //Check face of this rectangle hit another rectangle
    FaceHit RectCollideFace(Rectangle& other) const
    {
        if (position.y < other.position.y + other.dimensions.y && position.y + dimensions.y > other.position.y
            && position.x < other.position.x + other.dimensions.x && position.x + dimensions.x > other.position.x)
        {
            float upCollide = position.y - other.position.y + other.dimensions.y; //verify distance between top of this rectangle and bottom of other rectangle
            float downCollide = position.y + dimensions.y - other.position.y; //verify distance between bottom this rectangle and top of other rectangle
            float rightCollide = position.x + dimensions.x - other.position.x; //verify distance between right side of this rectangle and left side of other rectangle
            float leftCollide = position.x - other.position.x + other.dimensions.x; //verify distance between left side of this rectangle and right side of other rectangle

            if (upCollide >= downCollide && upCollide >= rightCollide && upCollide >= leftCollide)
            {
                return UP;
            }
            else if (downCollide >= upCollide && downCollide >= rightCollide && downCollide >= leftCollide)
            {
                return DOWN;
            }
            else if (rightCollide >= upCollide && rightCollide >= downCollide && rightCollide >= leftCollide)
            {
                return RIGHT;
            }
            else if (leftCollide >= upCollide && leftCollide >= rightCollide && downCollide >= rightCollide)
            {
                return LEFT;
            }
        }
        
        return NONE;

    };
};
