#pragma once

#include <raylib.h>
#include <string>

Vector2 GetRandomSpawnCoordinates(Vector2 winSize);

int AssertTextFitsInViewport(std::string text, int fontSize,
                             Vector2 constraints);

bool OutOfBounds(Vector2 target, Vector2 dim, Vector2 winSize);

float GetDistancePoints(Vector2 from, Vector2 to);

typedef struct RotatedRectangle {
  Vector2 tl, tr, bl, br;
} RotatedRectangle;

RotatedRectangle GetRotatedRectangle(Rectangle rec, float rotation);

bool CheckRotatedRectangleCollision(Rectangle a, float rotA, Rectangle b,
                                    float rotB);
