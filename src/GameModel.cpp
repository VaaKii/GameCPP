#include "GameModel.hpp"

GameModel::GameModel() : Rectangle({10,10,10,10}){
};

GameModel::GameModel(Rectangle rec){
    this->x=rec.x;
    this->y=rec.y;
    this->height = rec.height;
    this->width = rec.width;

};

GameModel::GameModel(Rectangle rec, Texture2D texture){
    this->x=rec.x;
    this->y=rec.y;
    this->height = rec.height;
    this->width = rec.width;
    this->texture = texture;
}

GameModel::~GameModel(){};

void GameModel::render(){
    if (this->texture.id == 0){
        DrawRectangleRec(*this,this->color);
    }
    //lse{
      //  DrawTextureRec(this->texture,*this,)
   // };
}