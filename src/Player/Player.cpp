#include <cmath>
#include <raylib.h>

#include "../Config/Config.hpp"
#include "../Player/Player.hpp"

Player::Player(Vector2 winSize) {
  pos.x = winSize.x / 2;
  pos.y = winSize.y / 2;
  speed = winSize.x / PLAYER_MOVEMENT_SPEED_FACTOR;
  scale = winSize.x / FRAME_WIDTH / PLAYER_SCALE_FACTOR;
}

Player::~Player() {}

void Player::Update() {
  float speed = this->speed * GetFrameTime();
  if (IsKeyDown(KEY_PLAYER_MOVE_UP)) {
    pos.y -= speed;
  }
  if (IsKeyDown(KEY_PLAYER_MOVE_DOWN)) {
    pos.y += speed;
  }
  if (IsKeyDown(KEY_PLAYER_MOVE_RIGHT)) {
    pos.x += speed;
  }
  if (IsKeyDown(KEY_PLAYER_MOVE_LEFT)) {
    pos.x -= speed;
  }

  // ✨
  // https://stackoverflow.com/questions/41518021/find-clockwise-angle-between-two-points-with-respect-to-an-arbitrary-origin
  Vector2 a = {pos.x, pos.y - 100};
  Vector2 c = {pos.x, pos.y};
  Vector2 b = {(float)GetMouseX(), (float)GetMouseY()};
  float dir_c_a = atan2(a.y - c.y, a.x - c.x) * RAD2DEG;
  float dir_c_b = atan2(b.y - c.y, b.x - c.x) * RAD2DEG;
  float angle_acb = dir_c_a - dir_c_b;
  if (angle_acb > 0) {
    angle_acb = 270 + (90 - angle_acb);
  }
  angle = std::abs(angle_acb);
}

void Player::Resize(Vector2 oldWinSize, Vector2 newWinSize) {
  speed = newWinSize.x / PLAYER_MOVEMENT_SPEED_FACTOR;
  scale = newWinSize.x / FRAME_WIDTH / PLAYER_SCALE_FACTOR;
  pos.x = newWinSize.x / (oldWinSize.x / pos.x);
  pos.y = newWinSize.y / (oldWinSize.y / pos.y);
}

void Player::Draw() { DrawTextureEx(spaceship, pos, angle, scale, WHITE); }

void Player::Reset(Vector2 winSize) {
  angle = STARTING_ANGLE;
  health = STARTING_HEALTH;
  pos.x = winSize.x / 2;
  pos.y = winSize.y / 2;
}
