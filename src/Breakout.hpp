#pragma once

#include <vector>

#include "Asteroid.hpp"
#include "Entity.hpp"
#include "Player.hpp"

class Breakout : public Entity {
private:
  float w, h;

  Player *player;

  std::vector<Asteroid *> asteroids;
  float asteroidSpawnCounter;
  Texture2D *asteroidTexture;

public:
  Breakout();
  ~Breakout();

  void Update();
  // w: window width, h: window height
  void Resize(float w, float h);
  void Draw();
};
