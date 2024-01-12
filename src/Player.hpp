#pragma once

#include <raylib.h>

#include "Entity.hpp"

class Player : public Entity {
private:
  float w, h;
  float radius;
  float angle;
  int health;
  float speed;
  Texture2D *texture;

public:
  float x, y;

  // w: window width, h: window height
  Player(float w, float h, Texture2D *texture);
  ~Player();

  void Update();
  // w: window width, window height
  void Resize(float w, float h);
  void Draw();
};
