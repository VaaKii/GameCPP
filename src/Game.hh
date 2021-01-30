#include <raylib.h>
#include "Core.hh"
#include "Player.hh"
#include "test_body.hh"

class Game : public Core{
    public:
    Camera2D camera = {0};
    Rectangle rec = {20,20,50,50};
    static Player* player;
    static test_body* body;
    Player* players[32];
    void update();
    static void load();
    static void unload();
    Game();
    ~Game();
};