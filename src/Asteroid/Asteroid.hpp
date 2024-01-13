#pragma once

#include <raylib.h>

#include "../Entity/Entity.hpp"

// TODO: dont travel towards player, just start going towards his angle aand
// keep same angle trajectory

class Asteroid : public Entity {
private:
  float speed;
  float scale;
  float angle;

public:
  Vector2 pos;
  Texture2D *asteroidTexture;

  Asteroid(Vector2 winSize, Texture2D *asteroidTexture, Vector2 playerPos);
  ~Asteroid();

  void Update();
  void Resize(Vector2 oldWinSize, Vector2 newWinSize);
  void Draw();
};
