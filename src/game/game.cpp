#include <iostream>
#include "game.h"
void Game ::initialize()
{
    if (!SDL_Init(SDL_INIT_EVERYTHING))
    {
        std::cerr << "problem initializing everything " << std::endl;
        return;
    }

    SDL_DisplayMode displayMode;
    SDL_GetCurrentDisplayMode(0 , &displayMode);

    window = SDL_CreateWindow(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, (*displayMode).w, (*displayMode).h, SDL_WINDOW_FULLSCREEN); // MIGHT GIVE AN ERROR
    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
    renderer = SDL_CreateRenderer(window, NULL, 0);
}
void Game ::processInput()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) // fills the event with all kinds of important information about the current state of keyboard and mouse
    {
        switch (event.type)
        {
            case SDL_QUIT {
                // handle quitting event here 
                isRunning = false ; 
                break ; 
            }
            case SDL_KEYDOWN {
                switch (event.key.keysym.scancode){
                    case SDL_SCANCODE_ESCAPE {
                        isRunning = false ; break ; 
                    }
                    default break ; 

                }

            case SDL_MOUSEMOTION {
                mouseevent = event.motion  ; 
            }     

            }
            default break ; 
        }
   } 

}
void Game :: update () {
} 

void Game :: render () {
} 
void Game :: destroy () {
    SDL_DestroyWindow (window ) ; 
    SDL_DestroRenderer (renderer ) ;  
}