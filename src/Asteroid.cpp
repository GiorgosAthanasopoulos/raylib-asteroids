#include <raylib.h>

#include "Asteroid.hpp"
#include "Config.hpp"
#include "Utils.hpp"

Asteroid::Asteroid(float w, float h, Texture2D *texture, float *playerX,
                   float *playerY) {
  Vector2 spawnCoords = GetRandomSpawnCoordinates(w, h);
  x = spawnCoords.x;
  y = spawnCoords.y;
  this->w = w / ASTEROID_SCALE_FACTOR;
  this->h = h / ASTEROID_SCALE_FACTOR;
  radius = w / ASTEROID_SCALE_FACTOR;
  speed = w / ASTEROID_MOVEMENT_SPEED_FACTOR;
  this->playerX = playerX;
  this->playerY = playerY;
  this->texture = texture;
}

Asteroid::~Asteroid() {}

void Asteroid::Update() {
  float speed = this->speed * GetFrameTime();
  if (*playerX < x) {
    x -= speed;
  } else {
    x += speed;
  }
  if (*playerY < y) {
    y -= speed;
  } else {
    y += speed;
  }

  // TODO: check for collisions with border/objects
}

void Asteroid::Resize(float w, float h) {
  this->w = w / ASTEROID_SCALE_FACTOR;
  this->h = h / ASTEROID_SCALE_FACTOR;
  radius = w / ASTEROID_SCALE_FACTOR;
  speed = w / ASTEROID_MOVEMENT_SPEED_FACTOR;
  // TODO: replace x, y with same ratios as before the resize
}

void Asteroid::Draw() {
  // TODO: redraw sprite
  // DrawCircle(asteroid.x, asteroid.y, asteroid.radius, ASTEROID_COLOR);
  DrawTexture(*texture, x, y, ASTEROID_GRAY);
}
