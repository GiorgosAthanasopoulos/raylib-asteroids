#include <raylib.h>

#include "../Asteroid/Asteroid.hpp"
#include "../Config/Config.hpp"
#include "../Utils/Utils.hpp"

Asteroid::Asteroid(float w, float h, Texture2D *texture, float *playerX,
                   float *playerY) {
  Vector2 spawnCoords = GetRandomSpawnCoordinates(w, h);
  x = spawnCoords.x;
  y = spawnCoords.y;
  radius = w / ASTEROID_SCALE_FACTOR;
  speed = w / ASTEROID_MOVEMENT_SPEED_FACTOR;
  scale = (w / FRAME_WIDTH / ASTEROID_SCALE_FACTOR +
           h / FRAME_HEIGHT / ASTEROID_SCALE_FACTOR) /
          2;
  this->playerX = playerX;
  this->playerY = playerY;
  this->texture = texture;
  this->w = w;
  this->h = h;
}

Asteroid::~Asteroid() {}

void Asteroid::Update() {
  float speed = this->speed * GetFrameTime();
  if (*playerX < x) {
    x -= speed;
  } else {
    x += speed;
  }
  if (x <= texture->width) {
    x = texture->width;
  } else if (x >= w - texture->width) {
    x = w - texture->width;
  }
  if (*playerY < y) {
    y -= speed;
  } else {
    y += speed;
  }
  if (y <= texture->height) {
    x = texture->height;
  } else if (y >= h - texture->height) {
    y = h - texture->height;
  }

  if (x < 0) {
  }
}

void Asteroid::Resize(float oldW, float oldH, float newW, float newH) {
  radius = newW / ASTEROID_SCALE_FACTOR;
  speed = newW / ASTEROID_MOVEMENT_SPEED_FACTOR;
  scale = (newW / FRAME_WIDTH / ASTEROID_SCALE_FACTOR +
           newH / FRAME_HEIGHT / ASTEROID_SCALE_FACTOR) /
          2;
  float oldXRatio = oldW / x;
  float oldYRatio = oldH / y;
  x = newW / oldXRatio;
  y = newH / oldYRatio;
  this->w = newW;
  this->h = newH;
}

void Asteroid::Draw() {
  DrawTextureEx(*texture, {x, y}, 0, scale, ASTEROID_GRAY);
}
