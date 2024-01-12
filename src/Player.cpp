#include <cmath>
#include <raylib.h>

#include "Config.hpp"
#include "Player.hpp"

Player::Player(float w, float h) {
  x = w / 2;
  y = h / 2;
  speed = w / PLAYER_MOVEMENT_SPEED_FACTOR;
  scale = (w / FRAME_WIDTH / PLAYER_SCALE_FACTOR +
           h / FRAME_HEIGHT / PLAYER_SCALE_FACTOR) /
          2;
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
}

void Player::Resize(float oldW, float oldH, float newW, float newH) {
  speed = newW / PLAYER_MOVEMENT_SPEED_FACTOR;
  scale = (newW / FRAME_WIDTH / PLAYER_SCALE_FACTOR +
           newH / FRAME_HEIGHT / PLAYER_SCALE_FACTOR) /
          2;
  ;
  float oldXRatio = oldW / x;
  float oldYRatio = oldH / y;
  x = newW / oldXRatio;
  y = newH / oldYRatio;
}

void Player::Draw() { DrawTextureEx(spaceship, {x, y}, angle, scale, WHITE); }

void Player::Reset(float w, float h) {
  angle = STARTING_ANGLE;
  health = STARTING_HEALTH;
  x = w / 2;
  y = h / 2;
}
