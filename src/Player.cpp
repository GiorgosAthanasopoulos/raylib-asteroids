#include "Player.hpp"
#include "Config.hpp"
#include <cmath>

Player::Player(float w, float h) {
  x = w / 2;
  y = h / 2;
  this->w = w / PLAYER_SCALE_FACTOR;
  this->h = h / PLAYER_SCALE_FACTOR;
  radius = w / PLAYER_SCALE_FACTOR;
  angle = STARTING_ANGLE;
  health = STARTING_HEALTH;
  speed = w / PLAYER_MOVEMENT_SPEED_FACTOR;
}

Player::~Player() {}

void Player::Update() {
  float speed = speed * GetFrameTime();
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

  float x = GetMouseX() - x;
  float y = GetMouseY() - y;
  // FIX: reversed player angle
  angle = atan2(y, x) * RAD2DEG;
  // TODO: check collision with border/objects
}

void Player::Resize(float w, float h) {
  this->w = w / PLAYER_SCALE_FACTOR;
  this->h = h / PLAYER_SCALE_FACTOR;
  radius = w / PLAYER_SCALE_FACTOR;
  speed = w / PLAYER_MOVEMENT_SPEED_FACTOR;
  // TODO: replace x, y with same ratios before resize
}

void Player::Draw() {
  // TODO: Maybe add a custom sprite?
  // player's body
  DrawCircle(x, y, radius, PLAYER_COLOR);
  // TODO: draw gun depending on angle
}
