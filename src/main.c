#include <raylib.h>

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 750

typedef struct {
  Vector3 position;
  float radius;
  Color color;
} Sphere;

int main(void) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Raytracer");

  Color pixels[SCREEN_HEIGHT][SCREEN_WIDTH];

  Sphere sphere = {.position = {0, 0, 10}, .radius = 2.f, .color = RED};
  Camera camera = {.position = {0, 0, 0},
                   .target = {0, 0, 10},
                   .up = {0, 1, 0},
                   .fovy = 60,
                   .projection = CAMERA_PERSPECTIVE};

  Image image = {.data = pixels,
                 .width = SCREEN_WIDTH,
                 .height = SCREEN_HEIGHT,
                 .mipmaps = 1,
                 .format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8};

  Texture2D texture = LoadTextureFromImage(image);

  while (!WindowShouldClose()) {
    BeginDrawing();

    for (int x = 0; x < SCREEN_WIDTH; x++) {
      for (int y = 0; y < SCREEN_HEIGHT; y++) {
        Ray ray = GetScreenToWorldRay((Vector2){x, y}, camera);
        RayCollision collision =
            GetRayCollisionSphere(ray, sphere.position, sphere.radius);
        pixels[y][x] = collision.hit ? sphere.color : BLACK;
      };
    };

    UpdateTexture(texture, pixels);
    DrawTexture(texture, 0, 0, WHITE);
    EndDrawing();
  };

  CloseWindow();

  return 0;
}
