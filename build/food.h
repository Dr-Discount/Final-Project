#pragma once  
#include "raylib.h"  

extern int cellSize;
extern int cellCount;

class Food {
public:
    Vector2 position = { 5, 6 };

    Food() {
        position = ranPosition();
    }

    Vector2 ranPosition() {
        float x = GetRandomValue(0, cellCount - 1);
        float y = GetRandomValue(0, cellCount - 1);
        return { x, y };
    };

    void Draw() {
        DrawRectangle(position.x * cellSize, position.y * cellSize, cellSize, cellSize, RED);
    }
};
