#include <iostream>
#include <SDL2/SDL.h>
#include <vector> 
#include <map>
#include "./square/square.h"
#include "./game/game.h"
#include <glm/glm.hpp>
#include "glm/gtc/matrix_transform.hpp"
#include <glm/gtx/string_cast.hpp>
#include <SDL2/SDL.h>
using namespace std ; 


template <typename T>
void MyRenderFunction (T function ){
    function () ;
};

void MyRenderFunction (){

};
int main () {

    Game game ; 
    Square square(10.0) ; 

    cout<<game.isRunning<<endl; 
    while (game.isRunning){
        game.processInput() ; 
        game.update()  ; 
        MyRenderFunction(
            [&game , &square ] (){
                SDL_SetRenderDrawColor(game.renderer , 21,
                21,21,255 ) ; 
                SDL_RenderClear(game.renderer ) ; 
                SDL_SetRenderDrawColor(game.renderer  , 255,255,255,255);
                square.renderMyself(game.renderer ) ; 
                SDL_RenderPresent(game.renderer ) ; 
            }
        );
        SDL_Delay (100) ; 
    }
    return 0 ; 
     }