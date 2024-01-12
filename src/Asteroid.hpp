#pragma once

#include <raylib.h>

#include "Entity.hpp"

class Asteroid : public Entity {
private:
  float radius;
  float speed;
  float scale;
  float w, h;

  float *playerX, *playerY;

public:
  float x, y;
  Texture2D *texture;

  // w: window width, h: window height
  Asteroid(float w, float h, Texture2D *texture, float *playerX,
           float *playerY);
  ~Asteroid();

  void Update();
  // w: window width, h: window height
  void Resize(float oldW, float oldH, float newW, float newH);
  void Draw();
};
