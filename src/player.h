#pragma once

#include <malloc.h>
#include <math.h>
#include <raylib.h>

#include "config.h"

typedef struct {
  float x, y;
  float w, h;
  float radius;
  float angle;
  int health;
  float speed;
} Player;

Player *PlayerInit(float w, float h) {
  Player *player = (Player *)malloc(sizeof(Player));
  player->x = w / 2;
  player->y = h / 2;
  player->w = w / PLAYER_SCALE_FACTOR;
  player->h = h / PLAYER_SCALE_FACTOR;
  player->radius = w / PLAYER_SCALE_FACTOR;
  player->angle = 0;
  player->health = STARTING_HEALTH;
  player->speed = w / PLAYER_MOVEMENT_SPEED_FACTOR;
  return player;
}

void PlayerDeinit(Player *player) { free(player); }

void PlayerUpdate(Player *player) {
  float speed = player->speed * GetFrameTime();
  if (IsKeyDown(KEY_PLAYER_MOVE_UP)) {
    player->y -= speed;
  }
  if (IsKeyDown(KEY_PLAYER_MOVE_DOWN)) {
    player->y += speed;
  }
  if (IsKeyDown(KEY_PLAYER_MOVE_RIGHT)) {
    player->x += speed;
  }
  if (IsKeyDown(KEY_PLAYER_MOVE_LEFT)) {
    player->x -= speed;
  }

  float x = GetMouseX() - player->x;
  float y = GetMouseY() - player->y;
  player->angle = atan2(x, y) * -57.29578f;
  // TODO: check collision with border/objects
}

void PlayerUpdateAfterResize(Player *player, float w, float h) {
  player->w = w / PLAYER_SCALE_FACTOR;
  player->h = h / PLAYER_SCALE_FACTOR;
  player->radius = w / PLAYER_SCALE_FACTOR;
  player->speed = w / PLAYER_MOVEMENT_SPEED_FACTOR;
  // TODO: replace x, y with same ratios before resize
}

void PlayerDraw(Player player, float w, float h) {
  // TODO: Maybe add a custom sprite?
  // player's body
  DrawCircle(player.x, player.y, player.radius, PLAYER_COLOR);
  // TODO: draw gun depending on player->angle
}
