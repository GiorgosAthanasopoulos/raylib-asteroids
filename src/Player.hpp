#pragma once

#include <raylib.h>

#include "Config.hpp"
#include "Entity.hpp"

class Player : public Entity {
private:
  float angle = STARTING_ANGLE; // angle player is looking at with mouse
  int health = STARTING_HEALTH;
  float speed;
  float scale;

  Texture2D spaceship;

public:
  float x, y;

  Player(float w, float h);
  ~Player();

  void Update();
  // w: window width, window height
  void Resize(float oldW, float oldH, float newW, float newH);
  void Draw();
};
