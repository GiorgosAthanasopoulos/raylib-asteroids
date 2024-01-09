#pragma once

#include <raylib.h>

#include "config.h"
#include "types.h"

void DrawPlayer(Breakout *game) {
  // player body
  DrawCircle(game->w / 2, game->h / 2, game->player.radius, PLAYER_COLOR);
}
