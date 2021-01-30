#include "Game.hh"
#include "Menu.hh"

Player* Game::player=NULL;
test_body* Game::body=NULL;

Game::Game(){
    if(player==NULL){
        player = new Player(Coordinates {10, 10},Size {50 , 74},5);
    }
    if(body==NULL){
        body = new test_body(Coordinates { 20 , 20},Size { 25, 25});
    }
    int x = this->player->GetCoordinates().x, y = this->player->GetCoordinates().y;
    this->camera.target = (Vector2){ x + 25  ,y + 25 };
    this->camera.offset = (Vector2){ 400, 300 };
    this->camera.rotation = 0.0f;
    this->camera.zoom = 1.0f;
     
}

Game::~Game(){
    delete this->player;
    delete this->body;
    this->player=NULL;
    this->body=NULL;
    
}

void Game::load(){
    Image img_p = LoadImage("src/player.png");
    ImageResize(&img_p,50,74);
    Image img_p2 = LoadImage("src/player_reverse.png");
    ImageResize(&img_p2,50,74);
    player->data.texture_main = LoadTextureFromImage(img_p);
    UnloadImage(img_p);
    player->data.texture_reverse = LoadTextureFromImage(img_p2);
    UnloadImage(img_p2);
    player->data.texture = player->data.texture_main;
    Image img_t = LoadImage("src/angry_potato.png");
    ImageResize(&img_t,50,100);
    body->data.texture = LoadTextureFromImage(img_t);
    UnloadImage(img_t);
}

void Game::unload(){
    UnloadTexture(player->data.texture_main);
    UnloadTexture(player->data.texture_reverse);
    UnloadTexture(body->data.texture);
}

void Game::update() {
    auto mousePoint = GetMousePosition();
    if (CheckCollisionPointRec(mousePoint, this->rec))
        {
           if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
                unload();
                Core::core=new MainMenu();
                delete this;
                return;
           }
        }
    if(IsKeyDown(KEY_W)){
            player->MoveUp();
        }
        if(IsKeyDown(KEY_A)){
            player->MoveLeft();
            player->data.texture = player->data.texture_reverse;
        }
        if(IsKeyDown(KEY_S)){
            player->MoveDown();
        }
        if(IsKeyDown(KEY_D)){
            player->MoveRight();
            player->data.texture = player->data.texture_main;
        }
    BeginDrawing();
        ClearBackground(RAYWHITE);
        int x = player->GetCoordinates().x, y = player->GetCoordinates().y;
        DrawRectangleRec(this->rec,BLUE);
        DrawText("P", this->rec.x+10, this->rec.y+2, 50, BLACK); 
        this->camera.target = (Vector2){ x + 25 ,y + 25 };
        BeginMode2D(this->camera);
             player->DrawT();
             body->DrawT();
        EndMode2D();
    EndDrawing();
}