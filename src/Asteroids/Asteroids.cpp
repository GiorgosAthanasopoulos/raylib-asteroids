#include <ostream>
#include <raylib.h>
#include <sstream>
#include <string>

#include "../Asteroids/Asteroids.hpp"
#include "../Config/Config.hpp"
#include "../Player/Player.hpp"
#include "../Utils/Utils.hpp"

Asteroids::Asteroids() : player(winSize) {
  asteroids.push_back(
      Asteroid(winSize, &assets.asteroidTexture, {player.pos.x, player.pos.y}));

  PlayMusicStream(assets.backgroundMusic);
}

Asteroids::~Asteroids() {}

void Asteroids::Update() {
  // resizing
  Vector2 newWinSize = {(float)GetRenderWidth(), (float)GetRenderHeight()};
  if (newWinSize.x != winSize.x || newWinSize.y != winSize.y) {
    Resize(winSize, newWinSize);
  }

  assets.Update();

  // animate background
  backgroundOpacityTimer += GetFrameTime();
  if (backgroundOpacityTimer >= BACKGROUND_OPACITY_TIME) {
    backgroundOpacity =
        increaseBackgroundOpacity
            ? (char)int(backgroundOpacity) + BACKGROUND_OPACITY_STEP
            : (char)int(backgroundOpacity) - BACKGROUND_OPACITY_STEP;
    backgroundOpacityTimer = 0;
    if (increaseBackgroundOpacity) {
      if (int(backgroundOpacity) > 255 - BACKGROUND_OPACITY_STEP) {
        increaseBackgroundOpacity = !increaseBackgroundOpacity;
      }
    } else {
      if (int(backgroundOpacity) < 0 + BACKGROUND_OPACITY_STEP * 2) {
        increaseBackgroundOpacity = !increaseBackgroundOpacity;
      }
    }
  }

  // other states
  if (!gameHasStarted) {
    if (IsKeyPressed(KEY_START_GAME)) {
      gameHasStarted = true;
    }
    return;
  }

  if (playerLost) {
    if (IsKeyPressed(KEY_RESTART)) {
      Reset();
    }
    return;
  }

  // keybinds
  if (IsKeyPressed(KEY_PLAYER_SHOOT)) {
    // TODO: guessing because of scale, player doesn't shoot
    // (or at least it's not shown)
    bullets.push_back(
        Bullet(player.pos, winSize, player.angle, &assets.bulletTexture));
    PlaySound(assets.gunshotSound);
  }

  // update entities
  player.Update();
  for (int i = 0; i < bullets.size(); ++i) {
    bullets[i].Update();
  }
  for (int i = 0; i < asteroids.size(); ++i) {
    asteroids[i].Update();
  }

  // physics
  for (int i = 0; i < asteroids.size(); ++i) {
    if (OutOfBounds(asteroids[i].pos, winSize)) {
      asteroids.erase(asteroids.begin() + i);
    }

    // TODO: implement collision
    if (CheckCollisionRecs({}, {})) {
      asteroids.erase(asteroids.begin() + i);
      player.health--;
      PlaySound(assets.hitSound);
    }

    for (int i = 0; i < bullets.size(); ++i) {
      if (OutOfBounds(bullets[i].pos, winSize)) {
        bullets.erase(bullets.begin() + i);
      }
      // TODO: implement collision
      if (CheckCollisionRecs({}, {})) {
        asteroids.erase(asteroids.begin() + i);
        playerScore++;
        PlaySound(assets.explosionSound);
      }
    }

    if (player.health == 0) {
      playerLost = true;
      PlaySound(assets.deathSound);
    }
  }

  // gane functions
  asteroidSpawnTimeCounter += GetFrameTime();
  if (asteroidSpawnTimeCounter > ASTEROID_SPAWN_TIME) {
    asteroids.push_back(Asteroid(winSize, &assets.asteroidTexture, player.pos));
    asteroidSpawnTimeCounter = 0;
  }
}

void Asteroids::Resize(Vector2 oldWinSize, Vector2 newWinSize) {
  winSize = newWinSize;
  player.Resize(oldWinSize, newWinSize);
  for (int i = 0; i < asteroids.size(); ++i) {
    asteroids[i].Resize(oldWinSize, newWinSize);
  }
  for (int i = 0; i < bullets.size(); ++i) {
    bullets[i].Resize(oldWinSize, newWinSize);
  }
}

void Asteroids::Draw() {
  ClearBackground(WINDOW_BACKGROUND_COLOR);
  DrawTextureEx(assets.background, {0, 0}, 0,
                winSize.x / BACKGROUND_FRAME_WIDTH / BACKGROUND_SCALE_FACTOR,
                {255, 255, 255, backgroundOpacity});

  if (!gameHasStarted) {
    std::string text = "Press SPACE to start!";
    int fontSize = AssertTextFitsInViewport(text, H1_FONT_SIZE, winSize);
    int textW = MeasureText(text.c_str(), fontSize);
    DrawText(text.c_str(), winSize.x / 2 - (float)textW / 2,
             winSize.y / 2 - (float)fontSize / 2, fontSize, UI_TEXT_COLOR);
    return;
  }

  std::ostringstream _score;
  _score << "Score: ";
  _score << std::to_string(playerScore);
  int fontSize = AssertTextFitsInViewport(
      _score.str(), H1_FONT_SIZE,
      {winSize.x / UI_SCALE_FACTOR, winSize.y / UI_SCALE_FACTOR});
  int textW = MeasureText(_score.str().c_str(), fontSize);
  DrawText(_score.str().c_str(), UI_BORDER_OFFSET, UI_BORDER_OFFSET, fontSize,
           UI_TEXT_COLOR);

  std::ostringstream health;
  health << "Health: ";
  health << std::to_string(player.health);
  fontSize = AssertTextFitsInViewport(
      health.str().c_str(), H1_FONT_SIZE,
      {winSize.x / UI_SCALE_FACTOR, winSize.y / UI_SCALE_FACTOR});
  textW = MeasureText(health.str().c_str(), fontSize);
  DrawText(health.str().c_str(), winSize.x - textW - UI_BORDER_OFFSET,
           UI_BORDER_OFFSET, fontSize, UI_TEXT_COLOR);

  player.Draw();
  for (int i = 0; i < asteroids.size(); ++i) {
    asteroids[i].Draw();
  }
  for (int i = 0; i < bullets.size(); ++i) {
    bullets[i].Draw();
  }

  if (playerLost) {
    std::string text = "You lost!";
    int fontSize = AssertTextFitsInViewport(text, H1_FONT_SIZE, winSize);
    int textW = MeasureText(text.c_str(), fontSize);
    DrawText(text.c_str(), winSize.x / 2 - (float)textW / 2,
             winSize.y / 2 - (float)fontSize / 2, fontSize, UI_TEXT_COLOR);
  }
}

void Asteroids::Reset() {
  player.Reset(winSize);
  asteroids.clear();
  asteroids.push_back(Asteroid(winSize, &assets.asteroidTexture, player.pos));
  playerLost = false;
  playerScore = 0;
  backgroundOpacity = BACKGROUND_OPACITY_STEP;
  increaseBackgroundOpacity = true;
  backgroundOpacityTimer = 0.0f;
  gameHasStarted = false;
}
