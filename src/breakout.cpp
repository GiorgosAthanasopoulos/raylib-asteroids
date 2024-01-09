#include <raylib.h>

#include "config.h"
#include "types.h"
#include "utils.h"

void Draw(Breakout *game) {
  BeginDrawing();
  ClearBackground(WINDOW_BACKGROUND_COLOR);

  DrawPlayer(game);

  EndDrawing();
}

void Update(Breakout *game) {
  game->w = GetRenderWidth();
  game->h = GetRenderHeight();
  game->player.w = game->w / PLAYER_SCALE_FACTOR;
  game->player.h = game->h / PLAYER_SCALE_FACTOR;
  game->player.radius = game->w / PLAYER_SCALE_FACTOR;
}

int main() {
  Breakout game = {0};
  game.w = DEFAULT_WINDOW_WIDTH;
  game.h = DEFAULT_WINDOW_HEIGHT;
  game.player = (Player){STARTING_ANGLE, STARTING_HEALTH};

  SetConfigFlags(WINDOW_FLAGS);
  InitWindow(game.w, game.h, WINDOW_TITLE);
  SetTargetFPS(TARGET_FPS);
  InitAudioDevice();

  while (!WindowShouldClose()) {
    Update(&game);
    Draw(&game);
  }

  CloseAudioDevice();
  CloseWindow();
  return 0;
}
