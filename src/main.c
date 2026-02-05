#include <raylib.h>

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 750

int main(void) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Raytracer");

  Color pixels[SCREEN_HEIGHT][SCREEN_WIDTH];

  for (int x = 0; x < SCREEN_WIDTH; x++) {
    for (int y = 0; y < SCREEN_HEIGHT; y++) {
      pixels[y][x] = RED;
    };
  };

  Image image = {.data = &pixels,
                 .width = SCREEN_WIDTH,
                 .height = SCREEN_HEIGHT,
                 .mipmaps = 1,
                 .format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8};

  Texture2D texture = LoadTextureFromImage(image);

  while (!WindowShouldClose()) {
    BeginDrawing();
    DrawTexture(texture, 0, 0, WHITE);
    EndDrawing();
  };

  CloseWindow();

  return 0;
}
