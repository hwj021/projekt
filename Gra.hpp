#ifndef GRA_HPP
#define GRA_HPP

#include "SDL.h"
#include <iostream>

class Game {
public:
    Game();
    ~Game();

    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();

    bool running() { return isrunning; }

private:
    int cnt = 0;
    bool isrunning;
    SDL_Window* window;
    SDL_Renderer* renderer;
};

#endif /* GRA_HPP */