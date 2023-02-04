#include <iostream>
#include <SDL2/SDL.h>
#include <vector> 
#include <map>
#include <string> 
class Game {
    public: 
    bool isRunning ; 
    SDL_MouseMotionEvent mouseevent ;    
    SDL_Window * window ; 
    SDL_Renderer * renderer ; 
    Game () ;  // calls the initialize method 
    ~Game () ; // calls the void destory () method 
    void initialize() ;  // creates a window and renderer 
    void processInput () ;  // records the input and stores them into a ceratin data type 
    void update () ;  // updates the postion and presence of objects based on the input 
    void render () ;  // just paste everything on thhe renderrer 
    void destroy () ; // destroys the window and the renderer 
    
} ; 