#include <raylib.h>
#include <raymath.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800
#define START_VELOCITY 400

#define BLOCKS_X 20
#define BLOCKS_Y 20
#define BLOCK_WIDTH (WINDOW_WIDTH / BLOCKS_X)
#define BLOCK_HEIGHT (WINDOW_HEIGHT / BLOCKS_X)
#define BALL_SIZE ((float)BLOCK_WIDTH / 2.0f)

int board[BLOCKS_X][BLOCKS_Y] = {0};
typedef struct {
  Vector2 pos;
  Vector2 v;
} Ball;
Ball balls[2] = {
  {
    {
      .x = (WINDOW_WIDTH / 2 - BALL_SIZE) / 2,
      .y = (WINDOW_HEIGHT - BALL_SIZE) / 2
    },
    {
      .x = -START_VELOCITY,
      .y = START_VELOCITY
    }
  },
  {
    {
      .x = WINDOW_WIDTH * 0.75f - BALL_SIZE / 2.0f,
      .y = (WINDOW_HEIGHT - BALL_SIZE) / 2
    },
    {
      .x = START_VELOCITY,
      .y = -START_VELOCITY
    }
  },
};

void DrawBoard() {
  for (int x = 0; x < BLOCKS_X; x++) {
    for (int y = 0; y < BLOCKS_Y; y++) {
      Vector2 pos = {.x = x * BLOCK_WIDTH, .y = y * BLOCK_HEIGHT};
      Vector2 size = {.x = BLOCK_WIDTH, .y = BLOCK_HEIGHT};
      DrawRectangleV(pos, size, board[x][y] == 0 ? WHITE : BLACK);
    }
  }
}

void DrawBalls() {
  DrawCircleV(balls[0].pos, BALL_SIZE, BLACK);
  DrawCircleV(balls[1].pos, BALL_SIZE, WHITE);
}

void InitBoard() {
  for (int x = BLOCKS_X / 2; x < BLOCKS_X; x++) {
    for (int y = 0; y < BLOCKS_Y; y++) {
      board[x][y] = 1;
    }
  }
}

void CollisionCheck(Ball *ball) {
  float halfsize = BALL_SIZE / 2.0f;
  if ((ball->pos.x - halfsize <= 0) || (ball->pos.x + halfsize >= WINDOW_WIDTH)) {
    ball->v.x *= -1.0f;
  }

  if ((ball->pos.y - halfsize <= 0) || (ball->pos.y + halfsize >= WINDOW_WIDTH)) {
    ball->v.y *= -1.0f;
  }
}

void Update(float delta) {
  balls[0].pos = Vector2Add(balls[0].pos, Vector2Scale(balls[0].v, delta));
  balls[1].pos = Vector2Add(balls[1].pos, Vector2Scale(balls[1].v, delta));

  CollisionCheck(&balls[0]);
  CollisionCheck(&balls[1]);
}

int main(void) {
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Infinite pong");

  SetTargetFPS(60);

  InitBoard();
  float delta = 0;

  while (!WindowShouldClose())
  {
    delta = GetFrameTime();
    Update(delta);

    BeginDrawing();
    ClearBackground(BLACK);
    DrawBoard();
    DrawBalls();
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
