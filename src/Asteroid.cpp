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
  scale = w / ASTEROID_SCALE_FACTOR;
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

void Asteroid::Resize(float oldW, float oldh, float newW, float newH) {
  this->w = newW / ASTEROID_SCALE_FACTOR;
  this->h = newH / ASTEROID_SCALE_FACTOR;
  radius = newW / ASTEROID_SCALE_FACTOR;
  speed = newW / ASTEROID_MOVEMENT_SPEED_FACTOR;
  scale = newW / ASTEROID_SCALE_FACTOR;
  // TODO: replace x, y with same ratios as before the resize
}

void Asteroid::Draw() {
  // TODO: redraw sprite
  // DrawCircle(asteroid.x, asteroid.y, asteroid.radius, ASTEROID_COLOR);
  DrawTextureEx(*texture, {x, y}, 0, scale, ASTEROID_GRAY);
}
