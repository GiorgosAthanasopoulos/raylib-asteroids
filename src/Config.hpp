#pragma once

#include <raylib.h>

// == WINDOW ==
#define WINDOW_FLAGS                                                           \
  FLAG_WINDOW_RESIZABLE // configuration flags for raylib window
#define DEFAULT_WINDOW_WIDTH 900
#define DEFAULT_WINDOW_HEIGHT 900
#define WINDOW_TITLE "Asteroids"
#define WINDOW_BACKGROUND_COLOR BLACK
#define TARGET_FPS 60
// == WINDOW ==

// == ASSETS ==
#define ASSETS_PATH "assets/"
// == ASSETS ==

// == KEYBINDS ==
#define KEY_EXIT KEY_NULL
#define KEY_PLAYER_MOVE_UP KEY_W
#define KEY_PLAYER_MOVE_DOWN KEY_S
#define KEY_PLAYER_MOVE_RIGHT KEY_D
#define KEY_PLAYER_MOVE_LEFT KEY_A
#define KEY_PLAYER_SHOOT KEY_SPACE
#define KEY_RESTART KEY_SPACE
// == KEYBINDS ==

// == PLAYER ==
#define STARTING_ANGLE 0  // player's gun will look at corresponding angle
#define STARTING_HEALTH 3 // health points the player has by default
#define PLAYER_SCALE_FACTOR 100
#define PLAYER_COLOR WHITE

#define PLAYER_MOVEMENT_SPEED_FACTOR 5
#define SPACESHIP_TEXTURE_PATH ASSETS_PATH "spaceship-scaled.png"
// == PLAYER ==

// == SPRITES ==
#define FRAME_WIDTH 24
#define FRAME_HEIGHT 24
// == SPRITES ==

// == ASTEROID ==
#define ASTEROID_SCALE_FACTOR 100
#define ASTEROID_COLOR RED
#define ASTEROID_SPAWN_TIME                                                    \
  3 // every ASTEROI_SPAWN_TIME seconds, a new asteroid will spawn
#define ASTEROID_MOVEMENT_SPEED_FACTOR 7
#define ASTEROID_TEXTURE_PATH ASSETS_PATH "asteroid-scaled.png"
#define ASTEROID_GRAY                                                          \
  (Color) { 127, 127, 127, 255 }
// == ASTEROID ==

// == FONTS ==
#define H1_FONT_SIZE 100
// == FONTS ==

// == UI ==
#define UI_SCALE_FACTOR 4
#define UI_TEXT_COLOR RED
#define UI_BORDER_OFFSET 10
// == UI ==

// == BACKGROUND ==
#define BACKGROUND_IMAGE_PATH ASSETS_PATH "space.png"
// == BACKGROUND ==
