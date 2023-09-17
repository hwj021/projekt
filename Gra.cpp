#include "Gra.hpp"
#include <iostream> // Dodaj nag³ówek dla cout

using namespace std;

Game::Game()
    : isrunning(false), window(nullptr), renderer(nullptr)
{
    // Konstruktor
}

Game::~Game()
{
    // Destruktor
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "Odpalono" << std::endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window)
        {
            std::cout << "STWORZONO OKNO" << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 140);
            std::cout << "STWORZONO renderer" << std::endl;
        }

        isrunning = true;
    }
    else {
        isrunning = false;
    }
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        isrunning = false;
        break;
    default:
        break;
    }
}

void Game::update()
{
    cnt++;
    cout << cnt << endl;
}

void Game::render()
{
    SDL_RenderClear(renderer);
    //tu dodajemy rzeczy do zrenderowania 
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "gra" << endl;
}