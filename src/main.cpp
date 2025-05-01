#include "raylib.h"


#include "game.h"
#include "resource_dir.h"	
#include "raymath.h"

const int screenWidth = 750;
const int screenHeight = 750;

int cellSize = 30;
int cellCount = 25;

double lastUpdateTime = 0;

bool eventTriggered(double interal) {
	double currentTime = GetTime();
	if (currentTime - lastUpdateTime > interal) {
		lastUpdateTime = currentTime;
		return true;
	}
	return false;
}

int main() {
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
	InitWindow(screenWidth, screenHeight, "Retro Snake");
	SetTargetFPS(60);

	Game game = Game();
	
	while (WindowShouldClose() == false) {
		if (IsKeyPressed(KEY_ESCAPE)) {
			CloseWindow();
			return 0;
		}

		if (IsKeyPressed(KEY_SPACE)) {

		}
		BeginDrawing();

		if (eventTriggered(0.2)) {
			game.Update();
		}

		if ((IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) && game.snake.direction.y != 1) {
			game.snake.direction = { 0, -1 };
		} else if ((IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) && game.snake.direction.y != -1) {
			game.snake.direction = { 0, 1 };
		} else if ((IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) && game.snake.direction.x != 1) {
			game.snake.direction = { -1, 0 };
		} else if ((IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) && game.snake.direction.x != -1) {
			game.snake.direction = { 1, 0 };
		}

		ClearBackground(GREEN);


		game.Draw();


		EndDrawing();
	}

	CloseWindow();
	return 0;
}