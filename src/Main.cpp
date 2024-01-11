#include <raylib.h>

#include "Breakout.hpp"
#include "Config.hpp"

int main() {
  SetConfigFlags(WINDOW_FLAGS);
  InitWindow(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, WINDOW_TITLE);
  SetTargetFPS(TARGET_FPS);
  InitAudioDevice();

  Breakout game;

  while (!WindowShouldClose()) {
    game.Update();

    BeginDrawing();
    game.Draw();
    EndDrawing();
  }

  CloseAudioDevice();
  CloseWindow();
}
