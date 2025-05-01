#pragma once  
#include "raylib.h"  
#include "raymath.h"
#include <deque>  

extern int cellSize;
extern int cellCount;

class Snake {
public:
    std::deque<Vector2> body = { Vector2{6.0f, 9.0f}, Vector2{5.0f, 9.0f}, Vector2{4.0f, 9.0f} };
    Vector2 direction = { 1.0f, 0.0f };

    void Draw() {
        for (unsigned int i = 0; i < body.size(); i++) {
            float x = body[i].x;
            float y = body[i].y;
            Rectangle segment = Rectangle{ x * static_cast<float>(cellSize), y * static_cast<float>(cellSize), static_cast<float>(cellSize), static_cast<float>(cellSize) };
            DrawRectangleRounded(segment, 0.3f, 6, DARKGREEN);
        }
    }

    void Update() {
        body.pop_back();
        body.push_front(Vector2Add(body[0], direction));
    }
};
