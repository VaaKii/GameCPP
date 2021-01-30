#include "Body.hh"

class Player : public Body{
    public: Player(Coordinates coordinates, Size size,int speed) : Body(coordinates, size, speed){};
    void SetSize(Size s) override;
    void SetCoordinates(Coordinates c) override;
    void SetSpeed(int speed) override;
    void MoveUp() override ;
    void MoveDown() override ;
    void MoveLeft() override ;
    void MoveRight() override ;
    void Draw() override ;
    void DrawT() override ;
};