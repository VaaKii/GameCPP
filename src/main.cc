#include "Core.hh"
#include "Game.hh"
#include "Menu.hh"

bool exit000 = 0;

void exitGame(){exit000=1;}

int main(){
    Core::core = new MainMenu();

    const int screenWidth = 800;
	const int screenHeight = 600;

    InitWindow(screenWidth,screenHeight,"NoName");
    SetTargetFPS(60);


    while (!WindowShouldClose())
    {
        if(exit000)break;
        Core::core->update();
    }
    CloseWindow();
    
}