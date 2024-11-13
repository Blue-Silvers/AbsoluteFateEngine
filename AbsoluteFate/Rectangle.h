#pragma once
#include <SDL_rect.h>
#include "Vector2D.h"

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
    Vector2D position;
    Vector2D dimensions;

    SDL_Rect ToSdlRect() const
    {
        return SDL_Rect{
            static_cast<int>(position.x),
            static_cast<int>(position.y),
            static_cast<int>(dimensions.x),
            static_cast<int>(dimensions.y) };
    }

    bool RectCollide(Rectangle& other) const 
    {
        if (position.y < other.position.y + other.dimensions.y && position.y + dimensions.y > other.position.y
            && position.x < other.position.x + other.dimensions.x && position.x + dimensions.x > other.position.x) 
        {
            return true;
        }
        else 
        {
            return false;
        }

    };
    FaceHit RectCollideFace(Rectangle& other) const
    {
        if (position.y < other.position.y + other.dimensions.y && position.y + dimensions.y > other.position.y
            && position.x < other.position.x + other.dimensions.x && position.x + dimensions.x > other.position.x)
        {
            float upCollide = position.y - other.position.y + other.dimensions.y;
            float downCollide = position.y + dimensions.y - other.position.y;
            float rightCollide = position.x + dimensions.x - other.position.x;
            float leftCollide = position.x - other.position.x + other.dimensions.x;
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
        else
        {
            return NONE;
        }

    };
};
