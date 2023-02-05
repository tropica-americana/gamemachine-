#include <iostream>
#include "game.h"

void Game ::initialize()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0 )
    {
        std::cerr << "problem initializing everything " << std::endl;
        isRunning = false ; 
        return;
    }
    SDL_DisplayMode displayMode;
    SDL_GetCurrentDisplayMode(0 , &displayMode);
    window = SDL_CreateWindow(NULL /*NULL AS THE TITLE */,SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, (displayMode).w, (displayMode).h, SDL_WINDOW_BORDERLESS); // MIGHT GIVE AN ERROR
    if (window == 0 ){isRunning = false ;std::cout<<"probleme windowe "<<std::endl; ;return ; }
    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
    renderer = SDL_CreateRenderer(window, NULL, 0);
    if (renderer == 0 ){isRunning = false ; std::cout<<"probleme renderere "<<std::endl;return ; }
}

void Game ::processInput()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) // fills the event with all kinds of important information about the current state of keyboard and mouse
    {
        switch (event.type)
        {
            case SDL_QUIT :  {
                // handle quitting event here 
                isRunning = false ; 
                break ; 
            }
            case SDL_KEYDOWN  :{
                switch (event.key.keysym.scancode){
                    case SDL_SCANCODE_ESCAPE :{
                        isRunning = false ; break ; 
                    }
                    default : {} ; 

                }

            case SDL_MOUSEMOTION :{
                mouseevent = event.motion  ; 
            }     

            }
            default :{} ; 
        }
   } 

}

void Game :: update () {
} 

void Game :: render () {
    SDL_SetRenderDrawColor(renderer ,255 ,21 ,21 , 255 ) ; 
    SDL_RenderClear (renderer ) ; 
    SDL_RenderPresent(renderer ) ; 
} 

void Game :: destroy () {
    SDL_DestroyWindow (window ) ; 
    SDL_DestroyRenderer (renderer ) ;  
}

//----------constructor of the game object --------------------------------------------
 Game :: Game ( ) {
    isRunning = true ; 
    initialize() ; 
 } 

 Game :: ~ Game () {
    destroy () ; 
 } 