#pragma once
#include "GameModel.hpp"

class Player
{
public:
    Player(Vector2 pos, GameModel model, Camera2D camera = {0});
    ~Player();
    Vector2 position;
    GameModel model;
    float velocity = 0.0;
    float gravity = 0.0;
    bool can_jump = true;
    Camera2D camera;
    void move_to(Vector2 pos);
    void render();
    void update();
};
