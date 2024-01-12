#pragma once

#include <raylib.h>

#define DEFAULT_WINDOW_WIDTH 1280
#define DEFAULT_WINDOW_HEIGHT 720
#define WINDOW_TITLE "Asteroids"
#define TARGET_FPS 60
#define WINDOW_FLAGS                                                           \
  FLAG_WINDOW_RESIZABLE // configuration flags for raylib window
#define WINDOW_BACKGROUND_COLOR BLACK
#define STARTING_ANGLE 0  // player's gun will look at corresponding angle
#define STARTING_HEALTH 3 // health points the player has by default
#define PLAYER_SCALE_FACTOR 20
#define PLAYER_COLOR WHITE
#define ASTEROID_SCALE_FACTOR 25
#define ASTEROID_COLOR RED
#define ASTEROID_SPAWN_TIME                                                    \
  3 // every ASTEROI_SPAWN_TIME seconds, a new asteroid will spawn
#define KEY_PLAYER_MOVE_UP KEY_W
#define KEY_PLAYER_MOVE_DOWN KEY_S
#define KEY_PLAYER_MOVE_RIGHT KEY_D
#define KEY_PLAYER_MOVE_LEFT KEY_A
#define KEY_SHOOT KEY_SPACE
#define PLAYER_MOVEMENT_SPEED_FACTOR 5
#define ASTEROID_MOVEMENT_SPEED_FACTOR 7
#define PLAYER_GUN_COLOR RED
#define ASSETS_PATH "assets/"
#define ASTEROID_TEXTURE_PATH ASSETS_PATH "asteroid.png"
#define ASTEROID_GRAY                                                          \
  (Color) { 127, 127, 127, 255 }
#define PLAYER_TEXTURE_PATH ASSETS_PATH "spaceship.png"
#define BACKGROUND_IMAGE_PATH ASSETS_PATH "background.png"
#define SPACE_BLACK                                                            \
  (Color) { 0, 0, 0, 255 }
