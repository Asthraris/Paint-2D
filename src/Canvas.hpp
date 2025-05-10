#pragma once
#include <raylib.h>
#include "Brush.hpp"

class Canvas{
    RenderTexture2D page ;
    
    public:
    Canvas(int WIDTH , int HEIGHT , Color BACKGROUND = BLACK){
        page = LoadRenderTexture(WIDTH, HEIGHT);
        BeginTextureMode(page);
        ClearBackground(BACKGROUND);  // initialize canvas to black
        EndTextureMode();
    }
    ~Canvas(){
        UnloadRenderTexture(page);
    }
    void write(const Vector2& mousepos , Brush& brush){
        BeginTextureMode(page);
        static Vector2 lastPos = { 0 };  // persists across frames
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) ) {
            float distance = Vector2Distance(lastPos, mousepos);
            int steps = (int)distance;
        
            for (int i = 0; i < steps; i++) {
                float t = (float)i / (float)steps;
                //hum is distanve me lerp kar rahe hai as acc to distnace  while drawing circles
                Vector2 interp = Vector2Lerp(lastPos, mousepos, t);
                DrawCircleV(interp, brush.size, brush.color);
            }
            lastPos = mousepos;
        } else {
            lastPos = mousepos;  // update even when not drawing
        }

        EndTextureMode();
    }
    
    void render(){
        Rectangle source = { 0.0f, 0.0f, (float)page.texture.width, -(float)page.texture.height };
        Vector2 position = { 0.0f, 0.0f };
        DrawTextureRec(page.texture, source, position, WHITE);
    }
    
};
