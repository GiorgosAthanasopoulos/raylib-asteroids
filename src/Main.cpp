#include <raylib.h>

#include "Asteroids/Asteroids.hpp"
#include "Config/Config.hpp"

int main() {
  SetConfigFlags(WINDOW_FLAGS);
  InitWindow(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, WINDOW_TITLE);
  SetTargetFPS(TARGET_FPS);
  InitAudioDevice();
  SetExitKey(KEY_EXIT);

  Asteroids game;

  while (!WindowShouldClose()) {
    game.Update();

    BeginDrawing();
    game.Draw();
    EndDrawing();
  }

  UnloadTexture(game.player.spaceship);
  UnloadTexture(game.assets.asteroidTexture);
  UnloadTexture(game.assets.bulletTexture);
  UnloadTexture(game.assets.background);

  CloseAudioDevice();
  CloseWindow();

  return 0;
}
