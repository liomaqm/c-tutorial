#include "raylib.h"
// For sprintf
#include <stdio.h> 
int main(void)
{
    /**
     * Define the screen dimensions in pixels (width and height)
     */
    const int _screenWidth = 800;
    const int _screenHeight = 450;

    InitWindow(_screenWidth, _screenHeight, "raylib - moving circle");
    SetTargetFPS(60);

    // Start the position of the circle in the center of the screen
    int _circleSize = 8;
    int _posX = _screenWidth / 2;
    int _posY = _screenHeight / 2;
    int _speed = 1;

    // _message is used to display the circle position and speed
    char _message[256];
    while (!WindowShouldClose())
    {
        // Move the circle with arrow keys
        if (IsKeyDown(KEY_RIGHT)) _posX += _speed;
        if (IsKeyDown(KEY_LEFT)) _posX -= _speed;
        if (IsKeyDown(KEY_UP)) _posY -= _speed;
        if (IsKeyDown(KEY_DOWN)) _posY += _speed;

        // Keep the circle inside the screen bounds
        if (_posX < _circleSize) _posX = _circleSize;
        if (_posX > _screenWidth - _circleSize) _posX = _screenWidth - _circleSize;
        if (_posY < _circleSize) _posY = _circleSize;
        if (_posY > _screenHeight - _circleSize) _posY = _screenHeight - _circleSize;

        // Change speed with PAGE UP and PAGE DOWN keys
        // Speed is limited to 1-10
        if (IsKeyPressed(KEY_PAGE_DOWN)) _speed--;
        if (IsKeyPressed(KEY_PAGE_UP)) _speed++;
        if (_speed < 1) _speed = 1;
        if (_speed > 10) _speed = 10;

        // sprintf is used to format the message with circle position and speed
        // it create the required "string" in the _message char array
        sprintf(_message, "Circle (x,y): (%4d, %4d) speed: %i",_posX, _posY,  _speed);

        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("Use arrow keys to move, PAGE UP and PAGE DOWN to change speed", 10, 10, 20, DARKGRAY);
        DrawText(_message, 10, 40, 20, DARKGRAY);

        DrawCircle(_posX, _posY, _circleSize, RED);

        EndDrawing();
    }

    /**
     * This code is only reached once the window is closed.
     * At this stage, we can unload resources and close the window.
     */
    CloseWindow();

    return 0;
}