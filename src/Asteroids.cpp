#include <raylib.h>

#include "Asteroids.hpp"
#include "Config.hpp"
#include "Player.hpp"

Asteroids::Asteroids() {
  w = DEFAULT_WINDOW_WIDTH;
  h = DEFAULT_WINDOW_HEIGHT;

  playerTexture = new Texture2D;
  *playerTexture = LoadTexture(PLAYER_TEXTURE_PATH);
  player = new Player(w, h, playerTexture);

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

void Asteroids::Resize(float w, float h) {
  this->w = w;
  this->h = h;
  player->Resize(w, h);
  for (int i = 0; i < asteroids.size(); ++i) {
    asteroids[i]->Resize(w, h);
  }
}

void Asteroids::Draw() {
  ClearBackground(WINDOW_BACKGROUND_COLOR);
  DrawTexture(background, 0, 0, SPACE_BLACK);

  player->Draw();
  for (int i = 0; i < asteroids.size(); ++i) {
    asteroids[i]->Draw();
  }

  // TODO: maybe draw some some starts at random places on the screen?
}
