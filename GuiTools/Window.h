#ifndef _GuiTools_Window_h_
#define _GuiTools_Window_h_

#include <SDL2/SDL.h>

class Window
{

    private:
        SDL_Window * window = NULL;
        SDL_Renderer * renderer = NULL;

    public:
        static const int WIDTH = 640;
        static const int HEIGHT = 480;
        const char * TITLE = "IXX1420 Gui-Debug";

        Window();
        ~Window();
        void Update();
        void Clear();
        void HandleEvents();
        SDL_Surface * GetSurface();
        SDL_Renderer * GetRenderer();

};

#endif // _GuiTools_Window_h_