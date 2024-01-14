#pragma once

#include <raylib.h>

#include "../Entity/Entity.hpp"

class Bullet : public Entity {
private:
  float angle;
  float speed;
  float scale;

public:
  Vector2 pos;
  Texture2D *bulletTexture;

  Bullet(Vector2 origin, Vector2 winSize, int angle, Texture2D *bulletTexture);
  ~Bullet();

  void Update();
  void Resize(Vector2 oldWinSize, Vector2 newWinSize);
  void Draw();
};
