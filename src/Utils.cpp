#include "Utils.hpp"

Vector2 GetRandomSpawnCoordinates(float w, float h) {
  switch (GetRandomValue(0, 3)) {
  case 0:
    // top
    return {(float)GetRandomValue(0, w), 0};
    break;
  case 1:
    // left
    return {0, (float)GetRandomValue(0, h)};
    break;
  case 2:
    // bottom
    return {(float)GetRandomValue(0, w), h};
    break;
  case 3:
    // right
    return {w, (float)GetRandomValue(0, h)};
    break;
  default:
    return {0, 0};
    break;
  }
}
