#include <raylib.h>
#include "Coordinates.hh"
#include "Size.hh"

struct Data_body
{
    Texture2D texture_main;
    Texture2D texture;
    Texture2D texture_reverse;
    Coordinates coordinates;
    Size size;
    int speed;
};
