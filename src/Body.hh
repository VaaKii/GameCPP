#ifndef BodyH
#define BodyH
#include "Coordinates.hh"
#include "Size.hh"
#include "Data_body.hh"
#include <raylib.h>
#include <cstddef>

class Body {
    public:
        Data_body data;
        Body(Coordinates coordinates, Size size,int speed);
        Body(Coordinates coordinates,Size size);
        Coordinates GetCoordinates();
        Size GetSize();
        virtual void SetSize(Size s)=0;
        virtual void SetCoordinates(Coordinates c)=0;
        virtual void SetSpeed(int speed)=0;
        virtual void MoveUp()=0;
        virtual void MoveDown()=0;
        virtual void MoveLeft()=0;
        virtual void MoveRight()=0;
        virtual void Draw()=0;
        virtual void DrawT()=0;
};
#endif