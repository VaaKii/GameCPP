#pragma once
#include <cstddef>

class Core
{
public:
    static Core *core;
    Core();
    ~Core();
    virtual void update();
};