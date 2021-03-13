#pragma once
#include "raylib-cpp.hpp"
#include "Player.hpp"

class Game{
    public:
        Game();
        ~Game();
        void update();
        Camera2D camera = {0};
        GameModel playerModel;
        Vector2 playerPos = {10,10};
        Player * player;
};