#include "Window.h"
#include <cassert>

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

    Clear();
    Update();
}

Window::~Window()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Window::Clear()
{
    SDL_Surface * surface = GetSurface();
    SDL_FillRect(
        surface,
        NULL,
        SDL_MapRGB(
            surface->format,
            0x00, 0x00, 0x00
        )
    );
}

void Window::Update()
{
    SDL_UpdateWindowSurface(window);
}

SDL_Surface * Window::GetSurface()
{
    return SDL_GetWindowSurface(window);
}

void Window::HandleEvents()
{
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            throw 0;
        }
    }
}

SDL_Renderer * Window::GetRenderer()
{
    return renderer;
}