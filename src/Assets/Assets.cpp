#include <raylib.h>

#include "Assets.hpp"

Assets::Assets() { backgroundMusic.looping = true; }

Assets::~Assets() {
  UnloadTexture(asteroidTexture);
  UnloadTexture(bulletTexture);
  UnloadTexture(background);

  UnloadMusicStream(backgroundMusic);
  UnloadSound(deathSound);
  UnloadSound(hitSound);
  UnloadSound(explosionSound);
  UnloadSound(gunshotSound);
}

void Assets::Update() { UpdateMusicStream(backgroundMusic); }

void Assets::Resize(Vector2 oldWinSize, Vector2 newWinSize) {}

void Assets::Draw() {}
