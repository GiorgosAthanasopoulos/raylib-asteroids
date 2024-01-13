#include <cmath>
#include <raylib.h>

#include "../Config/Config.hpp"
#include "Bullet.hpp"

Bullet::Bullet(Vector2 origin, Vector2 winSize, int angle,
               Texture2D *bulletTexture) {
  pos.x = origin.x;
  pos.y = origin.y;
  this->angle = angle;
  speed = winSize.x / BULLET_SCALE_FACTOR;
  scale = winSize.x / FRAME_WIDTH / BULLET_SCALE_FACTOR;
  this->bulletTexture = bulletTexture;
}

Bullet::~Bullet() {}

void Bullet::Update() {
  float speedX = speed * (sinf(DEG2RAD * angle) * RAD2DEG) * GetFrameTime();
  pos.x += speedX;
  float speedY = speed * (-cosf(DEG2RAD * angle) * RAD2DEG) * GetFrameTime();
  pos.y += speedY;
}

void Bullet::Resize(Vector2 oldWinSize, Vector2 newWinSize) {
  speed = newWinSize.x / BULLET_SCALE_FACTOR;
  scale = newWinSize.x / FRAME_WIDTH / BULLET_SCALE_FACTOR;
  pos.x = newWinSize.x / (oldWinSize.x / pos.x);
  pos.y = newWinSize.y / (oldWinSize.y / pos.y);
}

void Bullet::Draw() { DrawTextureEx(*bulletTexture, pos, angle, scale, WHITE); }
