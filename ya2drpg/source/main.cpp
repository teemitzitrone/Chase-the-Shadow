#include <iostream>
#include "ScreenManager.h"

int main(int argc, char *argv[]) {
    /// this could be our events trigger
    /// auto callback = [](engine::Component trigger, engine::GameObject gameObject) -> void { do some nasty stuff };
    auto func = [](int i) -> double {
        return 2 * i / 1.15;
    };
    double d = func(1);
    std::cout << d << std::endl;

    Game::ScreenManager *screenManager = Game::ScreenManager::GetInstance();

    if (screenManager->Init() != _NULL) {
        std::string map = Game::ScreenManager::maps.back();
        Game::ScreenManager::maps.pop_back();

        screenManager->LoadMap(map);
        screenManager->Run();
    }

    delete screenManager;

    return 0;
}
