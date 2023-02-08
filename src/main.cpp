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

// void display_model (glm::mat4 model )  {
//     std::cout<<glm::to_string (model[0]) <<std::endl;     
//     std::cout<<glm::to_string (model[1]) <<std::endl;       
//     std::cout<<glm::to_string (model[2]) <<std::endl;    
//     std::cout<<glm::to_string (model[3]) <<std::endl; 
// } 
template <typename T>
void MyRenderFunction (T function ){
    function () ;
};

void MyRenderFunction (){

};
int main () {

    Game game ; 
    Square square(100.0) ; 
    square.squarePosition
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
    }
    return 0 ; 
     }