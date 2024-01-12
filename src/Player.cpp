#include <cmath>
#include <iostream>
#include <ostream>
#include <raylib.h>

#include "Config.hpp"
#include "Player.hpp"

Player::Player(float w, float h) {
  x = w / 2;
  y = h / 2;
  speed = w / PLAYER_MOVEMENT_SPEED_FACTOR;
  scale = w / PLAYER_SCALE_FACTOR;
  spaceship = LoadTexture(SPACESHIP_TEXTURE_PATH);
}

Player::~Player() { UnloadTexture(spaceship); }

void Player::Update() {
  float speed = this->speed * GetFrameTime();
  if (IsKeyDown(KEY_PLAYER_MOVE_UP)) {
    y -= speed;
  }
  if (IsKeyDown(KEY_PLAYER_MOVE_DOWN)) {
    y += speed;
  }
  if (IsKeyDown(KEY_PLAYER_MOVE_RIGHT)) {
    x += speed;
  }
  if (IsKeyDown(KEY_PLAYER_MOVE_LEFT)) {
    x -= speed;
  }

  Vector2 a = {x, y - 100};
  Vector2 c = {x, y};
  Vector2 b = {(float)GetMouseX(), (float)GetMouseY()};
  float dir_c_a = atan2(a.y - c.y, a.x - c.x) * RAD2DEG;
  float dir_c_b = atan2(b.y - c.y, b.x - c.x) * RAD2DEG;
  float angle_acb = dir_c_a - dir_c_b;
  if (angle_acb > 0) {
    angle_acb = 270 + (90 - angle_acb);
  }
  angle = std::abs(angle_acb);

  // TODO: check collision with border/objects
}

void Player::Resize(float oldW, float oldH, float newW, float newH) {
  speed = newW / PLAYER_MOVEMENT_SPEED_FACTOR;
  scale = newW / PLAYER_SCALE_FACTOR;
  // TODO: replace x, y with same ratios before resize
}

void Player::Draw() {
  // TODO: replace 0's with actual values for rotation && scale
  DrawTextureEx(spaceship, {x, y}, angle, scale, (Color){255, 255, 255, 255});
}
