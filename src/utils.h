#pragma once

#include "config.h"
#include <raylib.h>

void RaylibInit(float w, float h) {
  SetConfigFlags(WINDOW_FLAGS);
  InitWindow(w, h, WINDOW_TITLE);
  SetTargetFPS(TARGET_FPS);
  InitAudioDevice();
}

void RaylibDeinit() {
  CloseAudioDevice();
  CloseWindow();
}

Vector2 AsteroidGetRandomSpawnCoordinates(float w, float h) {
  switch (GetRandomValue(0, 3)) {
  case 0:
    // top
    return (Vector2){(float)GetRandomValue(0, w), 0};
    break;
  case 1:
    // left
    return (Vector2){0, (float)GetRandomValue(0, h)};
    break;
  case 2:
    // bottom
    return (Vector2){(float)GetRandomValue(0, w), h};
    break;
  case 3:
    // right
    return (Vector2){w, (float)GetRandomValue(0, h)};
    break;
  default:
    return (Vector2){0, 0};
    break;
  }
}
