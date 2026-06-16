#include "GameBase.h"

namespace Core
{
    GameBase::GameBase() = default;

    GameBase::~GameBase() = default;

    void GameBase::run()
    {
        while (_loop)
        {
            // Minimal runner: delegate to the virtual hooks implemented by derived classes.
            // Keep this simple so linking succeeds and derived classes control the behavior.
            handleInput();
            update();
            render();
        }
    }
}
