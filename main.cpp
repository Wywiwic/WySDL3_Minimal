#include <SDL3/SDL.h>

#ifdef __EMSCRIPTEN__
    #include <emscripten.h>
#endif

#include "main.h"

void mainLoop()
{
    SDL_Event event;

    SDL_PollEvent(&event);
    switch (event.type)
    {
        case SDL_EVENT_KEY_DOWN:
        {
            if (event.key.key == SDLK_ESCAPE)
            {
                #ifdef __EMSCRIPTEN__
                    emscripten_cancel_main_loop();
                #else
                    isMainLoopActive = false;
                #endif
            }
            break;
        }
        default:
        {
        }
    }

    ///@remarks Animate the square
    mainSquare.animateSquare();

    ///@remarks Draw the square on the renderer
    mainSquare.drawSquare(renderer);
}

int main(int argc, char* argv[])
{
    ///@remarks Initialize the SDL Video
    SDL_Init(SDL_INIT_VIDEO);

    ///@remarks Create a window & a renderer
    SDL_Window* window = SDL_CreateWindow("WySDL3 Minimal", SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    renderer = SDL_CreateRenderer(window, nullptr);

    ///@remarks Create a square
    mainSquare.initSquare();

    ///@remarks SDL or Emscripten main loop
    #ifdef __EMSCRIPTEN__
        emscripten_set_main_loop(mainLoop, 0, 1);
    #else
        while (isMainLoopActive)
        {
            mainLoop();
        }
    #endif

    ///@remarks Cleanup the application
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
