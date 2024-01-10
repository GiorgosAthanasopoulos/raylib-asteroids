#pragma once

#include <malloc.h>
#include <vector>

#include "asteroid.h"
#include "config.h"
#include "player.h"

typedef struct {
  float w, h;
  Player *player;
  std::vector<Asteroid *> asteroids;
  float asteroidSpawnCounter;
} Breakout;

Breakout *BreakoutInit() {
  Breakout *game = (Breakout *)malloc(sizeof(Breakout));
  game->w = DEFAULT_WINDOW_WIDTH;
  game->h = DEFAULT_WINDOW_HEIGHT;
  game->player = PlayerInit(game->w, game->h);
  game->asteroids.push_back(AsteroidInit(game->w, game->h));
  return game;
}

void BreakoutDeinit(Breakout *game) {
  PlayerDeinit(game->player);
  for (int i = 0; i < game->asteroids.size(); ++i) {
    AsteroidDeinit(game->asteroids[i]);
  }
}

void BreakoutUpdate(Breakout *game) {
  // resize window if needed and adjust sprite sizes accordingly
  int newW = GetRenderWidth();
  int newH = GetRenderHeight();
  if (newW != game->w || newH != game->h) {
    game->w = GetRenderWidth();
    game->h = GetRenderHeight();
    PlayerUpdateAfterResize(game->player, game->w, game->h);
    for (int i = 0; i < game->asteroids.size(); ++i) {
      AsteroidUpdateAfterResize(game->asteroids[i], game->w, game->h);
    }
  }

  // update game objects
  PlayerUpdate(game->player);
  for (int i = 0; i < game->asteroids.size(); ++i) {
    AsteroidUpdate(game->asteroids[i], game->player->x, game->player->y);
  }

  // spawn new asteroid every ASTEROID_SPAWN_TIME seconds
  game->asteroidSpawnCounter += GetFrameTime();
  if (game->asteroidSpawnCounter > ASTEROID_SPAWN_TIME) {
    game->asteroids.push_back(AsteroidInit(game->w, game->h));
    game->asteroidSpawnCounter = 0;
  }
}

void BreakoutDraw(Breakout game) {
  // draw sprites
  PlayerDraw(*game.player, game.w, game.h);
  for (int i = 0; i < game.asteroids.size(); ++i) {
    AsteroidDraw(*game.asteroids[i]);
  }
}
