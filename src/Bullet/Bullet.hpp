#pragma once

#include <raylib.h>

#include "../Entity/Entity.hpp"

class Bullet : public Entity {
private:
  float speed;

public:
  float angle;
  float scale;
  Vector2 pos;
  Texture2D *bulletTexture;

  Bullet(Vector2 origin, Vector2 winSize, int angle, Texture2D *bulletTexture);
  ~Bullet();

  void Update();
  void Resize(Vector2 oldWinSize, Vector2 newWinSize);
  void Draw();
};
