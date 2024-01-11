#pragma once

class Entity {
public:
  Entity() {}
  virtual ~Entity() {}

  virtual void Update() = 0;
  // w: window width, h: window height
  virtual void Resize(float w, float h) = 0;
  virtual void Draw() = 0;
};
