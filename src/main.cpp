#include <raylib.h>
#include <raymath.h>

#include "Brush.hpp"
#include "Canvas.hpp"

#define ZOOM_FACTOR 1.2f
const Vector2 WIN = {1080, 720};

int main()
{
    InitWindow(WIN.x, WIN.y, "PikaDraw");
    SetTargetFPS(120);

    Canvas canvas(WIN.x, WIN.y);
    Brush brush;

    Camera2D cam = { 0 };
    cam.zoom = 1.0f;
    cam.target = Vector2{ WIN.x / 2.0f, WIN.y / 2.0f };
    cam.offset = Vector2{ WIN.x / 2.0f, WIN.y / 2.0f }; // center screen

    Vector2 prevMouse = GetMousePosition();

    while (!WindowShouldClose())
    {
        Vector2 mouse = GetMousePosition();
        Vector2 mouseDelta = Vector2Subtract(mouse, prevMouse);
        prevMouse = mouse;

        // ── Zoom: Hold Ctrl + Scroll ──
        if (IsKeyDown(KEY_LEFT_CONTROL)) {
            float wheel = GetMouseWheelMove();
            if (wheel != 0.0f) {
                Vector2 worldBefore = GetScreenToWorld2D(mouse, cam);
                cam.zoom *= (wheel > 0) ? ZOOM_FACTOR : (1.0f / ZOOM_FACTOR);
                Vector2 worldAfter = GetScreenToWorld2D(mouse, cam);
                cam.target = Vector2Add(cam.target, Vector2Subtract(worldBefore, worldAfter));
            }
        }

        // ── Pan: Hold Middle Mouse ──
        if (IsMouseButtonDown(MOUSE_BUTTON_MIDDLE)) {
            Vector2 worldDelta = Vector2Scale(mouseDelta, -1.0f / cam.zoom);
            cam.target = Vector2Add(cam.target, worldDelta);
        }

        // ── Brush Drawing ──
        Vector2 mouseWorld = GetScreenToWorld2D(mouse, cam);
        canvas.write(mouseWorld, brush);

        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            DrawCircle(mouseWorld.x, mouseWorld.y, brush.size, brush.color);
        }

        // ── Brush Size Adjust ──
        if (IsKeyDown(KEY_LEFT_SHIFT)) {
            brush.changeSize();
        }

        // ── Rendering ──
        BeginDrawing();
        {
            ClearBackground(RAYWHITE);
            BeginMode2D(cam);
            canvas.render();
            EndMode2D();
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
