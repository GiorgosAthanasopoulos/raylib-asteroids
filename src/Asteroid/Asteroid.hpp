#pragma once

#include <raylib.h>

#include "../Entity/Entity.hpp"

class Asteroid : public Entity {
private:
  float speed;

public:
  float scale;
  Vector2 pos;
  float angle;
  Texture2D *asteroidTexture;

  Asteroid(Vector2 winSize, Texture2D *asteroidTexture, Vector2 playerPos);
  ~Asteroid();

  void Update();
  void Resize(Vector2 oldWinSize, Vector2 newWinSize);
  void Draw();
};
