#pragma once

#include <raylib.h>

class Entity {
public:
  Entity() {}
  virtual ~Entity() {}

  virtual void Update() = 0;
  virtual void Resize(Vector2 oldWinSize, Vector2 newWinSize) = 0;
  virtual void Draw() = 0;
};
