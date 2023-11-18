//#include <chrono>
//#include <thread>
#include "./Flappy_Bird/OBSTACLES/OBSTACLES.h"
#include "./Flappy_Bird/GAME/GAME.h"
#include "./Flappy_Bird/PLAYER/PLAYER.h"
#include "./Flappy_Bird/COLLISION/COLLISION.h"

#ifdef __linux__
#include <X11/Xlib.h>
#endif

int main() {
#ifdef __linux__
    XInitThreads();
#endif

    Game game = Game();
    game.run();
    return 0;
}