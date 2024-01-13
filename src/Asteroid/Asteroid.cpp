#include <cmath>
#include <raylib.h>

#include "../Asteroid/Asteroid.hpp"
#include "../Config/Config.hpp"
#include "../Utils/Utils.hpp"

Asteroid::Asteroid(Vector2 winSize, Texture2D *asteroidTexture,
                   Vector2 playerPos) {
  Vector2 spawnCoords = GetRandomSpawnCoordinates(winSize);
  pos.x = spawnCoords.x;
  pos.y = spawnCoords.y;
  speed = winSize.x / ASTEROID_MOVEMENT_SPEED_FACTOR;
  scale = winSize.x / FRAME_WIDTH / ASTEROID_SCALE_FACTOR;
  this->asteroidTexture = asteroidTexture;

  // TODO: fix incorrect angle of travel
  Vector2 a = {pos.x, pos.y - 100};
  Vector2 c = {pos.x, pos.y};
  Vector2 b = playerPos;
  float dir_c_a = atan2(a.y - c.y, a.x - c.x) * RAD2DEG;
  float dir_c_b = atan2(b.y - c.y, b.x - c.x) * RAD2DEG;
  float angle_acb = dir_c_a - dir_c_b;
  if (angle_acb > 0) {
    angle_acb = 270 + (90 - angle_acb);
  }
  angle = std::abs(angle_acb);
}

Asteroid::~Asteroid() {}

void Asteroid::Update() {
  float speedX = this->speed * cosf(DEG2RAD * angle) * GetFrameTime();
  float speedY = this->speed * sinf(DEG2RAD * angle) * GetFrameTime();
  pos.x += speedX;
  pos.y += speedY;
}

void Asteroid::Resize(Vector2 oldWinSize, Vector2 newWinSize) {
  speed = newWinSize.x / ASTEROID_MOVEMENT_SPEED_FACTOR;
  scale = newWinSize.x / FRAME_WIDTH / ASTEROID_SCALE_FACTOR;
  pos.x = newWinSize.x / (oldWinSize.x / pos.x);
  pos.y = newWinSize.y / (oldWinSize.y / pos.y);
}

void Asteroid::Draw() {
  DrawTextureEx(*asteroidTexture, pos, 0, scale, ASTEROID_GRAY);
}
