#pragma once  
#include "raylib.h"  
#include <deque>
#include <iostream>

extern int cellSize;
extern int cellCount;

class Food {
public:
    Vector2 position = { 5, 6 };

	bool comparePosition(Vector2 pos, std::deque<Vector2> deque) {
		for (int i = 0; i < deque.size(); i++) {
			if (Vector2Equals(deque[i], pos)) {
				return true;
			}
			return false;
		}

	};

    Vector2 ranPosition(std::deque<Vector2> snakeBody) {
        float x = GetRandomValue(0, cellCount - 1);
        float y = GetRandomValue(0, cellCount - 1);
        Vector2 pos = { x, y };

        while (comparePosition(pos, snakeBody)) {
			std::cout << "Position already occupied by snake, generating new position..." << std::endl;
            float x = GetRandomValue(0, cellCount - 1);
            float y = GetRandomValue(0, cellCount - 1);
            pos = { x, y };
        }
        return { x, y };
    };

    void Draw() {
        DrawRectangle(position.x * cellSize, position.y * cellSize, cellSize, cellSize, RED);
    }
};
