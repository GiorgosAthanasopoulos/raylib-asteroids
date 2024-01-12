#pragma once

#include <raylib.h>

#include "Entity.hpp"

class Asteroid : public Entity {
private:
  float x, y;
  float w, h;
  float radius;
  float speed;
  float scale;
  Texture2D *texture;

  float *playerX, *playerY;

public:
  // w: window width, h: window height
  Asteroid(float w, float h, Texture2D *texture, float *playerX,
           float *playerY);
  ~Asteroid();

  void Update();
  // w: window width, h: window height
  void Resize(float oldW, float oldH, float newW, float newH);
  void Draw();
};
