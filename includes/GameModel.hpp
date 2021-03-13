#pragma once
#include "raylib-cpp.hpp"

class GameModel : public Rectangle{
    public:
    GameModel();
    GameModel(Rectangle rec);
    GameModel(Rectangle rec,Texture2D texture);
    ~GameModel();
    Texture2D texture = {0};
    Color color = GREEN;
    void render();
};