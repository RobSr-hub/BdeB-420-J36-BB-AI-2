#include "Core/Globals.h"
#include <iostream>

namespace Core
{
    void log(const char* message)
    {
        std::cout << message << '\n';
    }
}