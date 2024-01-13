#include <raylib.h>
#include <sstream>
#include <string>

#include "../Asteroids/Asteroids.hpp"
#include "../Config/Config.hpp"
#include "../Player/Player.hpp"
#include "../Utils/Utils.hpp"

Asteroids::Asteroids() {
  player = new Player(w, h);

  asteroidTexture = new Texture2D;
  *asteroidTexture = LoadTexture(ASTEROID_TEXTURE_PATH);
  asteroids.push_back(
      new Asteroid(w, h, asteroidTexture, &player->x, &player->y));

  backgroundMusic = LoadMusicStream(BACKGROUND_MUSIC_PATH);
  backgroundMusic.looping = true;
  PlayMusicStream(backgroundMusic);
  deathSound = LoadSound(DEATH_SOUND_PATH);
  hitSound = LoadSound(HIT_SOUND_PATH);
}

Asteroids::~Asteroids() {
  delete player;

  for (int i = 0; i < asteroids.size(); ++i) {
    delete asteroids[i];
  }
  UnloadTexture(*asteroidTexture);
  delete asteroidTexture;

  UnloadTexture(background);

  StopMusicStream(backgroundMusic);
  UnloadMusicStream(backgroundMusic);
  UnloadSound(deathSound);
  UnloadSound(hitSound);
}

void Asteroids::Update() {
  UpdateMusicStream(backgroundMusic);

  int newW = GetRenderWidth();
  int newH = GetRenderHeight();
  if (newW != w || newH != h) {
    Resize(w, h, newW, newH);
  }

  if (lost) {
    if (IsKeyPressed(KEY_RESTART)) {
      Reset();
    }
    return;
  }

  player->Update();
  for (int i = 0; i < asteroids.size(); ++i) {
    asteroids[i]->Update();

    // FIX: broken collision
    if (CheckCollisionRecs({player->x, player->y,
                            (float)player->spaceship.width,
                            (float)player->spaceship.height},
                           {asteroids[i]->x, asteroids[i]->y,
                            (float)asteroids[i]->texture->width,
                            (float)asteroids[i]->texture->height})) {
      asteroids.erase(asteroids.begin() + i);
      player->health--;
      PlaySound(hitSound);
    }
    if (false) { // TODO: replace with bullet collision with asteroid
      score++;
    }

    if (player->health == 0) {
      lost = true;
      PlaySound(deathSound);
    }
  }

  asteroidSpawnCounter += GetFrameTime();
  if (asteroidSpawnCounter > ASTEROID_SPAWN_TIME) {
    asteroids.push_back(
        new Asteroid(w, h, asteroidTexture, &player->x, &player->y));
    asteroidSpawnCounter = 0;
  }
}

void Asteroids::Resize(float oldW, float oldH, float newW, float newH) {
  this->w = newW;
  this->h = newH;
  player->Resize(oldW, oldH, newW, newH);
  for (int i = 0; i < asteroids.size(); ++i) {
    asteroids[i]->Resize(oldW, oldH, newW, newH);
  }
}

void Asteroids::Draw() {
  ClearBackground(WINDOW_BACKGROUND_COLOR);
  DrawTextureEx(background, {0, 0}, 0, w / 240, WHITE);

  std::ostringstream _score;
  _score << "Score: ";
  _score << std::to_string(score);
  int fontSize = AssertTextFitsInViewport(
      _score.str(), H1_FONT_SIZE, w / UI_SCALE_FACTOR, h / UI_SCALE_FACTOR);
  int textW = MeasureText(_score.str().c_str(), fontSize);
  DrawText(_score.str().c_str(), UI_BORDER_OFFSET, UI_BORDER_OFFSET, fontSize,
           UI_TEXT_COLOR);

  std::ostringstream health;
  health << "Health: ";
  health << std::to_string(player->health);
  fontSize = AssertTextFitsInViewport(health.str().c_str(), H1_FONT_SIZE,
                                      w / UI_SCALE_FACTOR, h / UI_SCALE_FACTOR);
  textW = MeasureText(health.str().c_str(), fontSize);
  DrawText(health.str().c_str(), w - textW - UI_BORDER_OFFSET, UI_BORDER_OFFSET,
           fontSize, UI_TEXT_COLOR);

  if (lost) {
    std::string text = "You lost!";
    int fontSize = AssertTextFitsInViewport(text, H1_FONT_SIZE, w, h);
    int textW = MeasureText(text.c_str(), fontSize);
    DrawText(text.c_str(), w / 2 - (float)textW / 2,
             h / 2 - (float)fontSize / 2, fontSize, RED);
    return;
  }

  player->Draw();
  for (int i = 0; i < asteroids.size(); ++i) {
    asteroids[i]->Draw();
  }
}

void Asteroids::Reset() {
  player->Reset(w, h);
  for (int i = 0; i < asteroids.size(); ++i) {
    delete asteroids[i];
  }
  asteroids.push_back(
      new Asteroid(w, h, asteroidTexture, &player->x, &player->y));
  lost = false;
  score = 0;
}
