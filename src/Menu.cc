#include "Menu.hh"
#include "Game.hh"

bool clicked = false;
bool clicked_mainmenu= true;

MainMenu::MainMenu(){

}

MainMenu::~MainMenu(){

}

void MainMenu::update(){
    auto mousePoint = GetMousePosition();
    if (CheckCollisionPointRec(mousePoint, this->play)){
           if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
                Core::core=new Game();
                Game::load();
                delete this;
                return;
           }
        }
    if (CheckCollisionPointRec(mousePoint, this->multiplayer)){
           if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON)){
                clicked_mainmenu = false;
                Core::core=new MultiplayerMenu();
                delete this;
                return;
           }
        }
    if(CheckCollisionPointRec(mousePoint,this->exit)){
        if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON)){
            if(clicked_mainmenu){
                exitGame();
            }
            else{
                clicked_mainmenu = true;
            }
            
        }
    }
    BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawRectangleRec(this->play,BLUE);
        DrawRectangleRec(this->multiplayer,BLUE);
        DrawRectangleRec(this->exit,BLUE);
        DrawText("Play", this->play.x+play.x/2 - 18, this->play.y+3, 40, BLACK); 
        DrawText("Multiplayer",this->multiplayer.x+multiplayer.x/2 -75,this->multiplayer.y+4,40,BLACK);
        DrawText("Exit",this->exit.x+exit.x/2 - 10,this->exit.y+4,40,BLACK);
    EndDrawing();
}

MultiplayerMenu::MultiplayerMenu(){
}

MultiplayerMenu::~MultiplayerMenu(){}

void MultiplayerMenu::update(){
    auto mousePoint = GetMousePosition();
    if (CheckCollisionPointRec(mousePoint, this->client_b))
        {
           if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
                printf("Тип страртует клиент\n");
           }
        }

    if (CheckCollisionPointRec(mousePoint, this->server_b))
        {
           if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
               if(clicked){
                server = new Server();
               }
               else
               {
                   clicked = true;
               }
               
           }
        }
    if(CheckCollisionPointRec(mousePoint,this->back)){
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)){
            clicked = false;
            Core::core = new MainMenu();
            delete this;
            return;
        }
    }
    BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawRectangleRec(this->client_b,BLUE);
        DrawRectangleRec(this->server_b,BLUE);
        DrawRectangleRec(this->back,BLUE);
        DrawText("Client", this->client_b.x+client_b.x/2- 25, this->client_b.y+3, 40, BLACK); 
        DrawText("Server",this->server_b.x+server_b.x/2 -40,this->server_b.y+4,40,BLACK);
        DrawText("Back",this->back.x+back.x/2 - 15,this->back.y + 4,40,BLACK);
    EndDrawing();
}
