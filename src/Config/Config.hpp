#pragma once

#include <raylib.h>

// == WINDOW ==
#define WINDOW_FLAGS                                                           \
  FLAG_WINDOW_RESIZABLE // configuration flags for raylib window
#define DEFAULT_WINDOW_WIDTH 900
#define DEFAULT_WINDOW_HEIGHT 700
#define WINDOW_TITLE "Asteroids"
#define TARGET_FPS 60
// == WINDOW ==

// == ASSETS ==
#define ASSETS_PATH "assets/"
#define SPRITES_PATH ASSETS_PATH "sprites/"
#define SCALED_PATH SPRITES_PATH "scaled/"
#define MUSIC_PATH ASSETS_PATH "music/"
#define SOUNDS_PATH ASSETS_PATH "sounds/"
// == ASSETS ==

// == KEYBINDS ==
#define KEY_EXIT KEY_NULL
#define KEY_START_GAME KEY_SPACE
#define KEY_PLAYER_MOVE_UP KEY_W
#define KEY_PLAYER_MOVE_DOWN KEY_S
#define KEY_PLAYER_MOVE_RIGHT KEY_D
#define KEY_PLAYER_MOVE_LEFT KEY_A
#define KEY_PLAYER_SHOOT KEY_SPACE
#define KEY_RESTART KEY_SPACE
#define KEY_MUTE KEY_M
// == KEYBINDS ==

// == PLAYER ==
#define STARTING_ANGLE 0  // player's gun will look at corresponding angle
#define STARTING_HEALTH 3 // health points the player has by default
#define PLAYER_SCALE_FACTOR 100
#define PLAYER_COLOR WHITE
#define PLAYER_MOVEMENT_SPEED_FACTOR 5
#define SPACESHIP_TEXTURE_PATH SCALED_PATH "spaceship-scaled.png"
#define PLAYER_SHOOT_DELAY 1
// == PLAYER ==

// == SPRITES ==
#define FRAME_WIDTH 24
#define FRAME_HEIGHT 24
// == SPRITES ==

// == ASTEROIDS ==
#define ASTEROID_SCALE_FACTOR 100
#define ASTEROID_COLOR RED
#define ASTEROID_SPAWN_TIME                                                    \
  1.5 // every ASTEROI_SPAWN_TIME seconds, a new asteroid will spawn
#define ASTEROID_MOVEMENT_SPEED_FACTOR 300
#define ASTEROID_TEXTURE_PATH SCALED_PATH "asteroid-scaled.png"
#define ASTEROID_GRAY                                                          \
  (Color) { 127, 127, 127, 255 }
// == ASTEROIDS ==

// == FONTS ==
#define H1_FONT_SIZE 100
#define H2_FONT_SIZE 60
// == FONTS ==

// == UI ==
#define UI_SCALE_FACTOR 5
#define UI_TEXT_COLOR SKYBLUE
#define UI_BORDER_OFFSET 10
// == UI ==

// == AUDIO ==
#define BACKGROUND_MUSIC_PATH MUSIC_PATH "background.mp3"
#define DEATH_SOUND_PATH SOUNDS_PATH "death.mp3"
#define HIT_SOUND_PATH SOUNDS_PATH "hit.mp3"
#define EXPLOSION_SOUND_PATH SOUNDS_PATH "explosion.mp3"
#define GUNSHOT_SOUND_PATH SOUNDS_PATH "gunshot.mp3"
// == MUSIC ==

// == BULLETS ==
#define BULLET_SCALE_FACTOR 300
#define BULLET_MOVEMENT_SPEED_FACTOR 300
#define BULLET_TEXTURE_PATH SCALED_PATH "rocket-scaled.png"
// == BULLETS ==

// == BACKGROUND ==
#define WINDOW_BACKGROUND_COLOR BLACK
#define BACKGROUND_IMAGE_PATH SPRITES_PATH "space.png"
#define BACKGROUND_FRAME_WIDTH 240
#define BACKGROUND_SCALE_FACTOR 2.5
#define BACKGROUND_OPACITY_TIME 0.1
#define BACKGROUND_OPACITY_STEP 20
// == BACKGROUND ==
