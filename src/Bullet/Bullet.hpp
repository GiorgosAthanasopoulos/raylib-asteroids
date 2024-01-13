#pragma once

#include "../Entity/Entity.hpp"

class Bullet : public Entity {
private:
  // TODO: create necessary fields for bullet entity
public:
  Bullet();
  ~Bullet();

  void Update();
  // w: window width, h: window height
  void Resize(float w, float h);
  void Draw();
};
