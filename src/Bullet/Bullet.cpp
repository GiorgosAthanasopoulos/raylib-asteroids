#include <cmath>
#include <raylib.h>

#include "../Config/Config.hpp"
#include "Bullet.hpp"

Bullet::Bullet(Vector2 origin, Vector2 winSize, int angle,
               Texture2D *bulletTexture) {
  pos = origin;
  this->angle = angle;
  speed = winSize.x / BULLET_MOVEMENT_SPEED_FACTOR;
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
  speed = newWinSize.x / BULLET_MOVEMENT_SPEED_FACTOR;
  scale = newWinSize.x / FRAME_WIDTH / BULLET_SCALE_FACTOR;
  pos.x = newWinSize.x / (oldWinSize.x / pos.x);
  pos.y = newWinSize.y / (oldWinSize.y / pos.y);
}

void Bullet::Draw() {
#ifdef DEBUG
  DrawRectangleLines(pos.x, pos.x, bulletTexture->width * scale,
                     bulletTexture->height * scale, RED);
#endif
  DrawTextureEx(*bulletTexture, pos, angle, scale, WHITE);
}
