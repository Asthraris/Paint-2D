#pragma once
#include <raylib.h>
#include "Brush.hpp"

#include <ctime>
#include <string>

class Canvas
{
    RenderTexture2D page;

public:
    Canvas(int WIDTH, int HEIGHT, Color BACKGROUND = BLACK)
    {
        page = LoadRenderTexture(WIDTH, HEIGHT);
        BeginTextureMode(page);
        ClearBackground(BACKGROUND); // initialize canvas to black
        EndTextureMode();
    }
    ~Canvas()
    {
        UnloadRenderTexture(page);
    }
    void write(const Vector2 &mousepos, Brush &brush)
    {
        BeginTextureMode(page);
        static Vector2 lastPos = {0}; // persists across frames
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            float distance = Vector2Distance(lastPos, mousepos);
            int steps = (int)distance;

            for (int i = 0; i < steps; i++)
            {
                float t = (float)i / (float)steps;
                // hum is distanve me lerp kar rahe hai as acc to distnace  while drawing circles
                Vector2 interp = Vector2Lerp(lastPos, mousepos, t);
                DrawCircleV(interp, brush.size, brush.color);
            }
            lastPos = mousepos;
        }
        else
        {
            lastPos = mousepos; // update even when not drawing
        }

        EndTextureMode();
    }

    void render()
    {
        Rectangle source = {0.0f, 0.0f, (float)page.texture.width, -(float)page.texture.height};
        Vector2 position = {0.0f, 0.0f};
        DrawTextureRec(page.texture, source, position, WHITE);
    }
    void reset()
    {
        BeginTextureMode(page);
        ClearBackground(BLACK);
        EndTextureMode();
    }

    void saveScreenshot()
    {
        time_t now = time(0);
        tm *ltm = localtime(&now);

        char filename[64];
        snprintf(filename, sizeof(filename), "canvas_%04d-%02d-%02d_%02d-%02d-%02d.png",
                 1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday,
                 ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
        Image img = LoadImageFromTexture(page.texture);
        ExportImage(img, filename);
        UnloadImage(img); // Prevent memory leak
    }
};
