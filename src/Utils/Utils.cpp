#include <cmath>
#include <raylib.h>

#include "Utils.hpp"

Vector2 GetRandomSpawnCoordinates(Vector2 winSize) {
  switch (GetRandomValue(0, 3)) {
  case 0:
    // top
    return {(float)GetRandomValue(0, winSize.x), 0};
    break;
  case 1:
    // left
    return {0, (float)GetRandomValue(0, winSize.y)};
    break;
  case 2:
    // bottom
    return {(float)GetRandomValue(0, winSize.x), winSize.y};
    break;
  case 3:
    // right
    return {winSize.x, (float)GetRandomValue(0, winSize.y)};
    break;
  default:
    return {0, 0};
    break;
  }
}

int AssertTextFitsInViewport(std::string text, int fontSize,
                             Vector2 constraints) {
  int textW = MeasureText(text.c_str(), fontSize);
  while (textW > constraints.x || fontSize > constraints.y) {
    fontSize--;
    textW = MeasureText(text.c_str(), fontSize);
  }
  return fontSize;
}

bool OutOfBounds(Vector2 target, Vector2 dim, Vector2 winSize) {
  return target.x > winSize.x || target.x + dim.x < 0 || target.y > winSize.y ||
         target.y + dim.y < 0;
}

RotatedRectangle GetRotatedRectangle(Rectangle rec, float rotation) {
  Vector2 topLeft = {0};
  Vector2 topRight = {0};
  Vector2 bottomLeft = {0};
  Vector2 bottomRight = {0};

  Vector2 origin = {0, 0};

  if (rotation == 0.0f) {
    float x = rec.x - origin.x;
    float y = rec.y - origin.y;
    topLeft = (Vector2){x, y};
    topRight = (Vector2){x + rec.width, y};
    bottomLeft = (Vector2){x, y + rec.height};
    bottomRight = (Vector2){x + rec.width, y + rec.height};
  } else {
    float sinRotation = sinf(rotation * DEG2RAD);
    float cosRotation = cosf(rotation * DEG2RAD);
    float x = rec.x;
    float y = rec.y;
    float dx = -origin.x;
    float dy = -origin.y;

    topLeft.x = x + dx * cosRotation - dy * sinRotation;
    topLeft.y = y + dx * sinRotation + dy * cosRotation;

    topRight.x = x + (dx + rec.width) * cosRotation - dy * sinRotation;
    topRight.y = y + (dx + rec.width) * sinRotation + dy * cosRotation;

    bottomLeft.x = x + dx * cosRotation - (dy + rec.height) * sinRotation;
    bottomLeft.y = y + dx * sinRotation + (dy + rec.height) * cosRotation;

    bottomRight.x =
        x + (dx + rec.width) * cosRotation - (dy + rec.height) * sinRotation;
    bottomRight.y =
        y + (dx + rec.width) * sinRotation + (dy + rec.height) * cosRotation;
  }

  return {.tl = topLeft, .tr = topRight, .bl = bottomLeft, .br = bottomRight};
}

bool CheckRotatedRectangleCollision(Rectangle a, float rotA, Rectangle b,
                                    float rotB) {
  RotatedRectangle aa = GetRotatedRectangle(a, rotA);
  RotatedRectangle bb = GetRotatedRectangle(b, rotB);

  for (int aax = aa.tl.x; aax <= aa.tr.x; ++aax) {
    for (int aay = aa.tl.y; aay <= aa.bl.y; ++aay) {
      for (int bbx = bb.tl.x; bbx <= bb.tr.x; ++bbx) {
        for (int bby = bb.tl.y; bby <= bb.bl.y; ++bby) {
          if (aax == bbx && aay == bby) {
            return true;
          }
        }
      }
    }
  }
  return false;
}
