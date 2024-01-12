#include <iostream>
#include <raylib.h>

#include "Asteroids.hpp"
#include "Config.hpp"
#include "Player.hpp"
#include "Utils.hpp"

Asteroids::Asteroids() {
  player = new Player(w, h);

  asteroidTexture = new Texture2D;
  *asteroidTexture = LoadTexture(ASTEROID_TEXTURE_PATH);
  asteroids.push_back(
      new Asteroid(w, h, asteroidTexture, &player->x, &player->y));

  background = LoadTexture(BACKGROUND_IMAGE_PATH);
}

Asteroids::~Asteroids() {
  delete player;

  for (int i = 0; i < asteroids.size(); ++i) {
    delete asteroids[i];
  }
  UnloadTexture(*asteroidTexture);
  delete asteroidTexture;
}

void Asteroids::Update() {
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

    if (CheckCollisionRecs({player->x, player->y,
                            (float)player->spaceship.width,
                            (float)player->spaceship.height},
                           {asteroids[i]->x, asteroids[i]->y,
                            (float)asteroids[i]->texture->width,
                            (float)asteroids[i]->texture->height})) {
      asteroids.erase(asteroids.begin() + i);
      player->health--;
      lost = true;
    }

    if (player->health == 0) {
      std::cout << "you lost\n";
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
  DrawTextureEx(background, {0, 0}, 0, w / FRAME_WIDTH, WHITE);

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
  // TODO: implement reset game
}
