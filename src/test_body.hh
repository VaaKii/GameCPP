#include "Body.hh"

class test_body : public Body{
    public: test_body (Coordinates c,Size s) : Body(c,s){};
    void SetSize(Size s) override;
    void SetCoordinates(Coordinates c) override;
    void SetSpeed(int speed) override;
    void MoveUp() override ;
    void MoveDown() override ;
    void MoveLeft() override ;
    void MoveRight() override ;
    void Draw() override ;
    void DrawT() override;
};