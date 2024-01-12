#pragma once

#include <raylib.h>

#include "Config.hpp"
#include "Entity.hpp"

class Player : public Entity {
private:
  float angle = STARTING_ANGLE; // angle player is looking at with mouse
  float speed;
  float scale;

public:
  float x, y;
  Texture2D spaceship = LoadTexture(SPACESHIP_TEXTURE_PATH);
  int health = STARTING_HEALTH;

  Player(float w, float h);
  ~Player();

  void Update();
  // w: window width, window height
  void Resize(float oldW, float oldH, float newW, float newH);
  void Draw();

  // w: window width, h: window height
  void Reset(float w, float h);
};
