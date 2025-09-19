#include "raylib.h"
// For sprintf
#include <stdio.h> 

/**
 * @brief Structure to hold grid information
 * 
 */
struct GameGrid {
    // Size of each cell in pixels (line will be 1 pixel wide)
    int cellSize;

    // Screen dimensions
    int screenWidth;
    int screenHeight;

    // Offset from the screen edge to start drawing the grid
    int offsetX;
    int offsetY;

    // Number of cells in each direction
    int cellsX;
    int cellsY;

    // End position of the grid
    int endX;
    int endY;
};

// Maximum length of the snake using C macros
#define SNAKE_MAX_LENGTH 100

struct Game {
    struct GameGrid grid;

    // Snake body positions and length in cells
    int snakeLength;
    Vector2 snake[SNAKE_MAX_LENGTH];
};

/**
 * @brief Create a Grid object
 * 
 * We use a pointer to the grid object so we can modify it directly.
 * 
 * @param grid Pointer to the grid object to be created 
 */
void createGrid(int screenWidth, int screenHeight, int cellSize, struct GameGrid *grid) {
    if (grid == NULL) return;
    grid->cellSize = cellSize;
    grid->screenWidth = screenWidth;
    grid->screenHeight = screenHeight;
    grid->offsetX = 5;
    grid->offsetY = 5;
    grid->cellsX = (screenWidth - grid->offsetX) / (cellSize + 1);
    grid->cellsY = (screenHeight - grid->offsetY) / (cellSize + 1);
    grid->endX = grid->offsetX + grid->cellsX * (cellSize + 1);
    grid->endY = grid->offsetY + grid->cellsY * (cellSize + 1);
}

void drawGrid(const struct GameGrid *grid) {
    if (grid == NULL) return;

    for (int i = 0; i <= grid->cellsX; i++) {
        int x = grid->offsetX + i * (grid->cellSize + 1);
        DrawLine(x, grid->offsetY, x, grid->endY, DARKGRAY);
    }
    for (int i = 0; i <= grid->cellsY; i++) {
        int y = grid->offsetY + i * (grid->cellSize + 1);
        DrawLine(grid->offsetX, y, grid->endX, y, DARKGRAY);
    }
}

void drawSnake(const struct Game *game) {
    if (game == NULL) return;

    for (int i = 0; i < game->snakeLength; i++) {
        Vector2 pos = game->snake[i];
        int _posX = game->grid.offsetX + pos.x * (game->grid.cellSize + 1);
        int _posY = game->grid.offsetY + pos.y * (game->grid.cellSize + 1);
        Vector2 _start = (Vector2){_posX, _posY};
        DrawRectangleV(_start, (Vector2){game->grid.cellSize, game->grid.cellSize}, GREEN);
    }
}

int main(void)
{
    /**
     * Define the screen dimensions in pixels (width and height)
     */
    const int _screenWidth = 800;
    const int _screenHeight = 450;
    struct Game game;

    createGrid(_screenWidth, _screenHeight, 20, &game.grid);
    game.snakeLength = 1;
    game.snake[0] = (Vector2){game.grid.cellsX / 2, game.grid.cellsY / 2};

    InitWindow(_screenWidth, _screenHeight, "raylib - snake");
    SetTargetFPS(60);

    // Start the position of the circle in the center of the screen
    int _speedX = 1;
    int _speedY = 0;
    int _speed = 8;

    int _frameCounter = 0;
    while (!WindowShouldClose())
    {
        // Update speed based on arrow keys
        // Prevent snake from going in the opposite direction directly
        if (IsKeyPressed(KEY_RIGHT)) {
            if (_speedX == -1) {
                // Ignore reverse direction
            } else {
                _speedX = 1;
                _speedY = 0;
            }
        } else if (IsKeyPressed(KEY_LEFT)) {
            if (_speedX == 1) {
                // Ignore reverse direction
            } else {
                _speedX = -1;
                _speedY = 0;
            }
        } else if (IsKeyPressed(KEY_DOWN)) {
            if (_speedY == -1) {
                // Ignore reverse direction
            } else {
                _speedY = 1;
                _speedX = 0;
            }
        } else if (IsKeyPressed(KEY_UP)) {
            if (_speedY == 1) {
                // Ignore reverse direction
            } else {
                _speedY = -1;
                _speedX = 0;
            }
        }

        // Change speed with PAGE UP and PAGE DOWN keys
        // Speed is limited to 1-10
        if (IsKeyPressed(KEY_PAGE_DOWN)) _speed--;
        if (IsKeyPressed(KEY_PAGE_UP)) _speed++;


        _frameCounter++;
        if (_frameCounter >= (20 - _speed)) {
            _frameCounter = 0;

            // Only update the snake position every X frames
            game.snake[0].x += _speedX;
            game.snake[0].y += _speedY;


            // Easy mode - keep the snake inside the screen bounds by clamping
            // If snake hits bounds, change direction to follow the wall clockwise
            if (game.snake[0].x < 0) {
                game.snake[0].x = 0;
                if (game.snake[0].y <= game.grid.cellsY / 2) {
                    _speedX = 0;
                    _speedY = 1;
                } else {
                    _speedX = 0;
                    _speedY = -1;
                }
            } else if (game.snake[0].x >= game.grid.cellsX) {
                game.snake[0].x = game.grid.cellsX - 1;
                if (game.snake[0].y <= game.grid.cellsY / 2) {
                    _speedX = 0;
                    _speedY = 1;
                } else {
                    _speedX = 0;
                    _speedY = -1;
                }
            } else if (game.snake[0].y < 0) {
                game.snake[0].y = 0;
                if (game.snake[0].x <= game.grid.cellsX / 2) {
                    _speedX = 1;
                    _speedY = 0;
                } else {
                    _speedX = -1;
                    _speedY = 0;
                }
            } else if (game.snake[0].y >= game.grid.cellsY) {
                game.snake[0].y = game.grid.cellsY - 1;
                if (game.snake[0].x <= game.grid.cellsX / 2) {
                    _speedX = 1;
                    _speedY = 0;
                } else {
                    _speedX = -1;
                    _speedY = 0;
                }
            } 
        }

        BeginDrawing();
        ClearBackground(BLACK);
        drawGrid(&game.grid);
        drawSnake(&game);
        EndDrawing();
    }

    /**
     * This code is only reached once the window is closed.
     * At this stage, we can unload resources and close the window.
     */
    CloseWindow();

    return 0;
}