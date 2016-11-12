#include "Window.h"
#include <cassert>

Window* Window::getInstance()
{
    static Window * instance;
    if (!instance) {
        instance = new Window();
    }
    return instance;
};

Window::Window()
{
    assert(SDL_Init(SDL_INIT_VIDEO) >= 0);

    window = SDL_CreateWindow(
        TITLE,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        WIDTH,
        HEIGHT,
        SDL_WINDOW_SHOWN
    );

    assert(window != NULL);

    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
    assert( renderer != NULL );

    clear();
    update();
}

Window::~Window()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Window::clear()
{
    SDL_Surface * surface = getSurface();
    SDL_FillRect(
        surface,
        NULL,
        SDL_MapRGB(
            surface->format,
            0x00, 0x00, 0x00
        )
    );
}

void Window::update()
{
    SDL_UpdateWindowSurface(window);
}

SDL_Surface * Window::getSurface()
{
    return SDL_GetWindowSurface(window);
}

void Window::handleEvents()
{
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            throw 0;
        }
    }
}

SDL_Renderer * Window::getRenderer()
{
    return renderer;
}