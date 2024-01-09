#pragma once

typedef struct {
  float w, h;
  float radius;
  int angle;
  int health;
} Player;

typedef struct {
  float w, h;
  Player player;
} Breakout;
