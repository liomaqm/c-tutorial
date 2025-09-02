#include "raylib.h"

int main(void)
{
    /**
     * Define the screen dimensions in pixels (width and height)
     */
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    SetTargetFPS(60);
    
    /**
     * Main game loop
     * 
     * This is an infinite loop that will run until the window is closed.
     * 
     * We use the function `WindowShouldClose()` to check if the window close button
     * has been pressed or if the ESC key has been pressed.
     * 
     * In this example, we don't have any game logic to update, so the loop body
     * only contains drawing code.
     */
    while (!WindowShouldClose())
    {
        /**
         * Drawing statements should be placed between `BeginDrawing()` and `EndDrawing()`
         */
        BeginDrawing();

        // Clear the background with a white color
        ClearBackground(RAYWHITE); 

        // Draw some text
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    }

    /**
     * This code is only reached once the window is closed.
     * At this stage, we can unload resources and close the window.
     */
    CloseWindow(); 

    return 0;
}