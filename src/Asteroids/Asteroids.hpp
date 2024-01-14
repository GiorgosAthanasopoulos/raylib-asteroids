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

  std::vector<Asteroid> asteroids;
  std::vector<Bullet> bullets;

  bool gameHasStarted = false;
  bool playerLost = false;
  bool increaseBackgroundOpacity = true;
  bool muted = false;

  int playerScore = 0;
  int playerHighScore = 0;
  float asteroidSpawnTimeCounter;
  float backgroundOpacityTimer = 0.0f;
  unsigned char backgroundOpacity = BACKGROUND_OPACITY_STEP;

public:
  Assets assets;
  Player player;

  Asteroids();
  ~Asteroids();

  void Update();
  void Resize(Vector2 oldWinSize, Vector2 newWinSize);
  void Draw();

  void Reset();
};
