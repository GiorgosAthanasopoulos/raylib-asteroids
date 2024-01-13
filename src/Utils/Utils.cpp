#include <raylib.h>

#include "Utils.hpp"

Vector2 GetRandomSpawnCoordinates(Vector2 winSize) {
  switch (GetRandomValue(0, 3)) {
  case 0:
    // top
    return {(float)GetRandomValue(0, winSize.x), 0};
    break;
  case 1:
    // left
    return {0, (float)GetRandomValue(0, winSize.y)};
    break;
  case 2:
    // bottom
    return {(float)GetRandomValue(0, winSize.x), winSize.y};
    break;
  case 3:
    // right
    return {winSize.x, (float)GetRandomValue(0, winSize.y)};
    break;
  default:
    return {0, 0};
    break;
  }
}

int AssertTextFitsInViewport(std::string text, int fontSize,
                             Vector2 constraints) {
  int textW = MeasureText(text.c_str(), fontSize);
  while (textW > constraints.x || fontSize > constraints.y) {
    fontSize--;
    textW = MeasureText(text.c_str(), fontSize);
  }
  return fontSize;
}

bool OutOfBounds(Vector2 target, Vector2 winSize) {
  return target.x > winSize.x || target.x < 0 || target.y > winSize.y ||
         target.y < 0;
}
