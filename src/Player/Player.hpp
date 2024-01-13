#pragma once

#include <raylib.h>

#include "../Config/Config.hpp"
#include "../Entity/Entity.hpp"

class Player : public Entity {
private:
  float speed;
  float scale;

public:
  float angle = STARTING_ANGLE; // angle player is looking at with mouse
  Vector2 pos;
  Texture2D spaceship = LoadTexture(SPACESHIP_TEXTURE_PATH);
  int health = STARTING_HEALTH;

  Player(Vector2 winSize);
  ~Player();

  void Update();
  void Resize(Vector2 oldWinSize, Vector2 newWinSize);
  void Draw();

  void Reset(Vector2 winSize);
};
