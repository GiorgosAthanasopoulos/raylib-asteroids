#pragma once

#include <vector>

#include "../Assets/Assets.hpp"
#include "../Asteroid/Asteroid.hpp"
#include "../Bullet/Bullet.hpp"
#include "../Config/Config.hpp"
#include "../Entity/Entity.hpp"
#include "../Player/Player.hpp"

class Asteroids : public Entity {
private:
  Vector2 winSize = {DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT};

  Assets assets;
  Player player;
  std::vector<Asteroid> asteroids;
  float asteroidSpawnCounter;
  std::vector<Bullet> bullets;

  bool lost = false;
  int score = 0;

public:
  Asteroids();
  ~Asteroids();

  void Update();
  void Resize(Vector2 oldWinSize, Vector2 newWinSize);
  void Draw();

  void Reset();
};
