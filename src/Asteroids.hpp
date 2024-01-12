#pragma once

#include <vector>

#include "Asteroid.hpp"
#include "Entity.hpp"
#include "Player.hpp"

class Asteroids : public Entity {
private:
  float w, h;

  Player *player;
  Texture2D *playerTexture;

  std::vector<Asteroid *> asteroids;
  float asteroidSpawnCounter;
  Texture2D *asteroidTexture;

  Texture2D background;

public:
  Asteroids();
  ~Asteroids();

  void Update();
  // w: window width, h: window height
  void Resize(float w, float h);
  void Draw();
};
