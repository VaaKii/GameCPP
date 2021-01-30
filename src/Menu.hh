#include <raylib.h>
#include "Core.hh"
#include "Server.hh"
#include "main.hh"
#include <stdio.h>

class MainMenu : public Core{
    public:
    Rectangle play = {240,120,300,50};
    Rectangle multiplayer = {240,220,300,50};
    Rectangle exit = {240,320,300,50};
    MainMenu();
    ~MainMenu();
    void update();
};

class MultiplayerMenu : public Core{
    public:
    Server * server;
    MultiplayerMenu();
    ~MultiplayerMenu();
    void update();
    Rectangle client_b = {240,120,300,50};
    Rectangle server_b = {240,220,300,50};
    Rectangle back = {240,320,300,50};
};