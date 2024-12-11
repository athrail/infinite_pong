#include <raylib.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

int main(void) {
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Infinite pong");

  SetTargetFPS(60);

  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(BLACK);
    DrawText("Hello, world", 100, 100, 16, WHITE);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
