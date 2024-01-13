#pragma once

#include <raylib.h>

#include "../Config/Config.hpp"
#include "../Entity/Entity.hpp"

class Assets : public Entity {
public:
  Texture2D background = LoadTexture(BACKGROUND_IMAGE_PATH);
  Texture2D asteroidTexture = LoadTexture(ASTEROID_TEXTURE_PATH);
  Texture2D bulletTexture = LoadTexture(BULLET_TEXTURE_PATH);

  Music backgroundMusic = LoadMusicStream(BACKGROUND_MUSIC_PATH);
  Sound deathSound = LoadSound(DEATH_SOUND_PATH);
  Sound hitSound = LoadSound(HIT_SOUND_PATH);
  Sound explosionSound = LoadSound(EXPLOSION_SOUND_PATH);
  Sound gunshotSound = LoadSound(GUNSHOT_SOUND_PATH);

  Assets();
  ~Assets();

  void Update();
  void Resize(Vector2 oldWinSize, Vector2 newWinSize);
  void Draw();
};
