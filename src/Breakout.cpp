#include <raylib.h>

#include "Breakout.hpp"
#include "Config.hpp"
#include "Player.hpp"

Breakout::Breakout() {
  w = DEFAULT_WINDOW_WIDTH;
  h = DEFAULT_WINDOW_HEIGHT;
  player = new Player(w, h);
  asteroidTexture = new Texture2D;
  *asteroidTexture = LoadTexture(ASTEROID_TEXTURE_PATH);
  asteroids.push_back(
      new Asteroid(w, h, asteroidTexture, &player->x, &player->y));
}

Breakout::~Breakout() {
  delete player;
  for (int i = 0; i < asteroids.size(); ++i) {
    delete asteroids[i];
  }
  UnloadTexture(*asteroidTexture);
  delete asteroidTexture;
}

void Breakout::Update() {
  int newW = GetRenderWidth();
  int newH = GetRenderHeight();
  if (newW != w || newH != h) {
    Resize(newW, newH);
  }

  player->Update();
  for (int i = 0; i < asteroids.size(); ++i) {
    asteroids[i]->Update();
  }

  asteroidSpawnCounter += GetFrameTime();
  if (asteroidSpawnCounter > ASTEROID_SPAWN_TIME) {
    asteroids.push_back(
        new Asteroid(w, h, asteroidTexture, &player->x, &player->y));
    asteroidSpawnCounter = 0;
  }
}

void Breakout::Resize(float w, float h) {
  this->w = w;
  this->h = h;
  player->Resize(w, h);
  for (int i = 0; i < asteroids.size(); ++i) {
    asteroids[i]->Resize(w, h);
  }
}

void Breakout::Draw() {
  ClearBackground(WINDOW_BACKGROUND_COLOR);

  player->Draw();
  for (int i = 0; i < asteroids.size(); ++i) {
    asteroids[i]->Draw();
  }

  // TODO: maybe draw some some starts at random places on the screen?
}
