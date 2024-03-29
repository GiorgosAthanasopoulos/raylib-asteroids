#include <ostream>
#include <raylib.h>
#include <sstream>
#include <string>

#include "../Asteroids/Asteroids.hpp"
#include "../Utils/Utils.hpp"

// TODO: fix collisions

// TODO: fix OutOfBounds for scaled sprites (new function with rotated
// rectangle)

// TODO: maybe add 2nd asteroid sprite and choose randomly which one the new
//       asteroid will use

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

  if (IsKeyPressed(KEY_MUTE)) {
    muted = !muted;
    SetMusicVolume(assets.backgroundMusic, muted ? 0 : 1);
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
  playerShotDelay += GetFrameTime();
  if (IsKeyPressed(KEY_PLAYER_SHOOT) && playerShotDelay >= PLAYER_SHOOT_DELAY) {
    bullets.push_back(
        Bullet(player.pos, winSize, player.angle, &assets.bulletTexture));
    PlaySound(assets.gunshotSound);
    playerShotDelay = 0;
  }

  // update entities
  player.Update();
  for (int i = 0; i < bullets.size(); ++i) {
    if (OutOfBounds(bullets[i].pos,
                    {(float)assets.bulletTexture.width,
                     (float)assets.bulletTexture.height},
                    winSize)) {
      bullets.erase(bullets.begin() + i);
      continue;
    }
    bullets[i].Update();
  }
  for (int i = 0; i < asteroids.size(); ++i) {
    if (OutOfBounds(asteroids[i].pos,
                    {(float)assets.asteroidTexture.width,
                     (float)assets.asteroidTexture.height},
                    winSize)) {
      asteroids.erase(asteroids.begin() + i);
      continue;
    }
    asteroids[i].Update();
  }

  // physics
  Rectangle playerRect = {player.pos.x, player.pos.y,
                          player.spaceship.width * player.scale,
                          player.spaceship.height * player.scale};
  for (int i = 0; i < asteroids.size(); ++i) {
    Rectangle asteroidRect = {
        asteroids[i].pos.x, asteroids[i].pos.y,
        asteroids[i].asteroidTexture->width * asteroids[i].scale,
        asteroids[i].asteroidTexture->height * asteroids[i].scale};
    if (CheckRotatedRectangleCollision(playerRect, player.angle, asteroidRect,
                                       asteroids[i].angle)) {
      asteroids.erase(asteroids.begin() + i);
      player.health--;
      PlaySound(assets.hitSound);
    }

    for (int j = 0; j < bullets.size(); ++j) {
      Rectangle bulletRect = {
          bullets[j].pos.x, bullets[j].pos.y,
          bullets[j].bulletTexture->width * bullets[j].scale,
          bullets[j].bulletTexture->height * bullets[j].scale};
      if (CheckRotatedRectangleCollision(asteroidRect, asteroids[i].angle,
                                         bulletRect, bullets[j].angle)) {
        asteroids.erase(asteroids.begin() + i);
        bullets.erase(bullets.begin() + j);
        playerScore++;
        PlaySound(assets.explosionSound);
      }
    }
  }

  if (player.health == 0) {
    playerLost = true;
    PlaySound(assets.deathSound);
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

  std::ostringstream highScore;
  highScore << "High Score: ";
  highScore << std::to_string(playerHighScore);
  fontSize = AssertTextFitsInViewport(
      highScore.str().c_str(), H1_FONT_SIZE,
      {winSize.x / UI_SCALE_FACTOR, winSize.y / UI_SCALE_FACTOR});
  textW = MeasureText(highScore.str().c_str(), fontSize);
  DrawText(highScore.str().c_str(), winSize.x / 2 - (float)textW / 2,
           UI_BORDER_OFFSET, fontSize, UI_TEXT_COLOR);

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

    text = "Press SPACEBAR to restart!";
    int fontSize2 = AssertTextFitsInViewport(text, H1_FONT_SIZE,
                                             {winSize.x / 1.5f, winSize.y});
    textW = MeasureText(text.c_str(), fontSize2);
    DrawText(text.c_str(), winSize.x / 2 - (float)textW / 2,
             winSize.y / 2 - (float)fontSize2 / 2 + fontSize, fontSize2,
             UI_TEXT_COLOR);
  }
}

void Asteroids::Reset() {
  player.Reset(winSize);
  playerLost = false;
  if (playerScore > playerHighScore) {
    playerHighScore = playerScore;
  }
  playerScore = 0;
  playerShotDelay = PLAYER_SHOOT_DELAY;

  asteroids.clear();
  asteroids.push_back(Asteroid(winSize, &assets.asteroidTexture, player.pos));
  asteroidSpawnTimeCounter = 0;
  bullets.clear();

  backgroundOpacity = BACKGROUND_OPACITY_STEP;
  increaseBackgroundOpacity = true;
  backgroundOpacityTimer = 0.0f;
  gameHasStarted = false;
}
