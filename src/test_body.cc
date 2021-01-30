#include "test_body.hh"


void test_body::SetCoordinates(Coordinates coordinates){
    this->data.coordinates = coordinates;
}

void test_body::SetSize(Size size){
    this->data.size = size;
}

void test_body::SetSpeed(int speed){
    this->data.speed = speed;
}

void test_body::MoveUp(){
    this->data.coordinates.y = this->data.coordinates.y - this->data.speed;
}

void test_body::MoveDown(){
    this->data.coordinates.y = this->data.coordinates.y + this->data.speed;
}

void test_body::MoveLeft(){
    this->data.coordinates.x = this->data.coordinates.x - this->data.speed;
}

void test_body::MoveRight(){
    this->data.coordinates.x = this->data.coordinates.x + this->data.speed;
}

void test_body::Draw() {
    DrawRectangleV((Vector2){this->data.coordinates.x,this->data.coordinates.y},(Vector2){this->data.size.x,this->data.size.y}, GREEN);
}

void test_body::DrawT(){
    DrawTextureV(data.texture,(Vector2){this->data.coordinates.x,this->data.coordinates.y},RAYWHITE);

}