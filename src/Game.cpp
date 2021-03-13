#include "Game.hpp"

Game::Game(){
    this->player = new Player(this->playerPos,this->playerModel,this->camera);
};
Game::~Game(){
}

void Game::update(){
    this->player->render();
    this->player->update();
}