#include <malloc.h>
#include <raylib.h>

#include "breakout.h"
#include "config.h"
#include "utils.h"

int main() {
  Breakout *game = BreakoutInit();

  RaylibInit(game->w, game->h);

  while (!WindowShouldClose()) {
    BreakoutUpdate(game);
    BeginDrawing();
    ClearBackground(WINDOW_BACKGROUND_COLOR);
    BreakoutDraw(*game);
    EndDrawing();
  }

  BreakoutDeinit(game);
  RaylibDeinit();

  free(game);
  return 0;
}
