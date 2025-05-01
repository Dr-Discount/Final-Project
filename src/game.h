#pragma once
#include "snake.h"
#include "food.h"

class Game {
public:
	Snake snake = Snake();
	Food food = Food();

	void Draw() {
		snake.Draw();
		food.Draw();
	}

	void Update() {
		snake.Update();
	}

};