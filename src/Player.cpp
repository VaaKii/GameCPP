#include "Player.hpp"

Player::Player(Vector2 pos, GameModel model,Camera2D camera){
    this->position = pos;
    this->model = model;
    this->camera = camera;
};

Player::~Player(){}

void Player::move_to(Vector2 pos){
    this->position = pos;
}

void Player::render(){
    this->model.render();
}

void Player::update(){
    this->position.x += this->velocity;
    this->position.y -= this->gravity;
}