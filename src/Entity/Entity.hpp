#pragma once

class Entity {
public:
  Entity() {}
  virtual ~Entity() {}

  virtual void Update() = 0;
  // w: window width, h: window height
  virtual void Resize(float oldW, float oldH, float newW, float newH) = 0;
  virtual void Draw() = 0;
};
