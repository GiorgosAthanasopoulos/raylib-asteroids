#pragma once

#include <raylib.h>
#include <string>

Vector2 GetRandomSpawnCoordinates(Vector2 winSize);

int AssertTextFitsInViewport(std::string text, int fontSize,
                             Vector2 constraints);
