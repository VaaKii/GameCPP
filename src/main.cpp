#include "raylib-cpp.hpp"
#include "Game.hpp"

int main()
{
    raylib::Window window(800, 600, "GameCPP");
    Game game;
    SetTargetFPS(60);
    while (!window.ShouldClose())
    {
        ClearBackground(RAYWHITE);
        BeginDrawing();
        game.update();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}