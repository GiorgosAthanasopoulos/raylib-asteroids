#pragma once

#include <raylib.h>
#include <string>

// w: window width, h: window height
Vector2 GetRandomSpawnCoordinates(float w, float h);

int AssertTextFitsInViewport(std::string text, int fontSize, float w, float h);
