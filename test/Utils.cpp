#include <cassert>
#include <raylib.h>

#include "../src/Utils/Utils.hpp"

void TestGetRandomSpawnCoordinates() {
  Vector2 tests[] = {{1920, 1080}, {1280, 720}};
  for (Vector2 test : tests) {
    Vector2 result = GetRandomSpawnCoordinates(test);
    assert(result.x >= 0);
    assert(result.y >= 0);
    assert(result.x <= test.x);
    assert(result.y <= test.y);
  }
}

typedef struct ATFIV {
  std::string text;
  int fontSize;
  Vector2 cons;
} ATFIV;

void TestAssertTextFitsInViewport() {
  ATFIV tests[] = {{"Hello, World!", 100, {1920, 1080}},
                   {"Ahoy, Sailor!", 200, {1280, 720}},
                   {"This is a large paragraph!", 300, {640, 480}}};
  for (ATFIV test : tests) {
    int result = AssertTextFitsInViewport(test.text, test.fontSize, test.cons);
    assert(result > 0);
    assert(result <= test.fontSize);
    int textW = MeasureText(test.text.c_str(), result);
    assert(textW <= test.cons.x);
    assert(result > 0);
    assert(result <= test.cons.y);
  }
}

typedef struct OOB {
  Vector2 target, dim, winSize;
  bool result;
} OOB;

void TestOutOfBounds() {
  OOB tests[] = {
      {{(float)1920 / 2, (float)1080 / 2}, {300, 300}, {1920, 1080}, false},
      {{2000, 2000}, {100, 100}, {1280, 720}, true},
      {{5, 0}, {6, 5}, {10, 10}, false}};
  for (OOB test : tests) {
    bool result = OutOfBounds(test.target, test.dim, test.winSize);
    assert(result == test.result);
  }
}

int main() {
  TestGetRandomSpawnCoordinates();
  TestAssertTextFitsInViewport();
  TestOutOfBounds();
  return 0;
}
