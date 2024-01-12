#pragma once

#include <vector>

#include "Asteroid.hpp"
#include "Config.hpp"
#include "Entity.hpp"
#include "Player.hpp"

class Asteroids : public Entity {
private:
  float w = DEFAULT_WINDOW_WIDTH, h = DEFAULT_WINDOW_HEIGHT;

  Player *player;

  std::vector<Asteroid *> asteroids;
  float asteroidSpawnCounter;
  Texture2D *asteroidTexture;

  Texture2D background = LoadTexture(BACKGROUND_IMAGE_PATH);

  bool lost = false;
  int score = 0;

  Music backgroundMusic;
  Sound deathSound;
  Sound hitSound;
  // TODO: explosion sound when bullet hits asteroid
  // TODO: sound when gun shoots

public:
  Asteroids();
  ~Asteroids();

  void Update();
  // w: window width, h: window height
  void Resize(float oldW, float oldH, float newW, float newH);
  void Draw();

  void Reset();
};
