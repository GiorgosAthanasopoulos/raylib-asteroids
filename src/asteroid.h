#pragma once

#include <malloc.h>
#include <raylib.h>
#include <vector>

#include "config.h"
#include "utils.h"

typedef struct {
  float x, y;
  float w, h;
  float radius;
  float speed;
} Asteroid;

Asteroid *AsteroidInit(float w, float h) {
  Asteroid *asteroid = (Asteroid *)malloc(sizeof(Asteroid));
  Vector2 asteroidSpawnCoordinates = AsteroidGetRandomSpawnCoordinates(w, h);
  asteroid->x = asteroidSpawnCoordinates.x;
  asteroid->y = asteroidSpawnCoordinates.y;
  asteroid->w = w / ASTEROID_SCALE_FACTOR;
  asteroid->h = h / ASTEROID_SCALE_FACTOR;
  asteroid->radius = w / ASTEROID_SCALE_FACTOR;
  asteroid->speed = w / ASTEROID_MOVEMENT_SPEED_FACTOR;
  return asteroid;
}

Asteroid *AsteroidDeinit(Asteroid *asteroid) { free(asteroid); }

void AsteroidUpdate(Asteroid *asteroid, float playerX, float playerY) {
  float speed = asteroid->speed * GetFrameTime();
  if (playerX < asteroid->x) {
    asteroid->x -= speed;
  } else {
    asteroid->x += speed;
  }
  if (playerY < asteroid->y) {
    asteroid->y -= speed;
  } else {
    asteroid->y += speed;
  }

  // TODO: check for collisions with border/objects
}

void AsteroidUpdateAfterResize(Asteroid *asteroid, float w, float h) {
  asteroid->w = w / ASTEROID_SCALE_FACTOR;
  asteroid->h = h / ASTEROID_SCALE_FACTOR;
  asteroid->radius = w / ASTEROID_SCALE_FACTOR;
  asteroid->speed = w / ASTEROID_MOVEMENT_SPEED_FACTOR;
  // TODO: replace x, y with same ratios as before the resize
}

void AsteroidDraw(Asteroid asteroid) {
  // TODO: Maybe add a custom sprite?
  DrawCircle(asteroid.x, asteroid.y, asteroid.radius, ASTEROID_COLOR);
}
