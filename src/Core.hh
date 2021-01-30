#ifndef CoreH
#define CoreH
#include <cstddef>
class Core;
class Core{
    public:
        static Core* core;
        Core();
        ~Core();
        virtual void update();
};
#endif