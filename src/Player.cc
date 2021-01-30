#include "Player.hh"

void Player::SetCoordinates(Coordinates coordinates){
    this->data.coordinates = coordinates;
}

void Player::SetSize(Size size){
    this->data.size = size;
}

void Player::SetSpeed(int speed){
    this->data.speed = speed;
}

void Player::MoveUp(){
    this->data.coordinates.y = this->data.coordinates.y - this->data.speed;
}

void Player::MoveDown(){
    this->data.coordinates.y = this->data.coordinates.y + this->data.speed;
}

void Player::MoveLeft(){
    this->data.coordinates.x = this->data.coordinates.x - this->data.speed;
}

void Player::MoveRight(){
    this->data.coordinates.x = this->data.coordinates.x + this->data.speed;
}

void Player::Draw() {
    DrawRectangleV((Vector2){this->data.coordinates.x,this->data.coordinates.y},(Vector2){this->data.size.x,this->data.size.y}, GREEN);
}

void Player::DrawT(){
    DrawTextureV(data.texture,(Vector2){this->data.coordinates.x,this->data.coordinates.y},RAYWHITE);

}