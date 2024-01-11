#pragma once

#include "Entity.hpp"

class Player : public Entity {
private:
  float w, h;
  float radius;
  float angle;
  int health;
  float speed;

public:
  float x, y;

  // w: window width, h: window height
  Player(float w, float h);
  ~Player();

  void Update();
  // w: window width, window height
  void Resize(float w, float h);
  void Draw();
};
