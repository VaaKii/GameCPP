#include "Body.hh"

Body::Body(Coordinates coordinates,Size size,int speed){
    this->data.coordinates=coordinates;
    this->data.size=size;
    this->data.speed=speed;
    this->data.texture = {0};
    this->data.texture_reverse = {0};
}

Body::Body(Coordinates coordinates,Size size){
    this->data.coordinates=coordinates;
    this->data.size=size;
    this->data.texture = {0};
    this->data.texture_reverse = {0};
}


Coordinates Body::GetCoordinates(){
    return this->data.coordinates;
}

Size Body::GetSize(){
    return this->data.size;
}