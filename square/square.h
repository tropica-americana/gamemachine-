#include <iostream>
#include <SDL2/SDL.h>
#include <vector> 
#include <map>
#include <tuple> 
class Square {
    std::tuple <double , double , double > square_rotation_xyz ;  
    std::tuple <double , double , double > square_position_xyz ; 
    double square_width ; 
    void renderMyself ( SDL_Renderer * renderer ) ;  
}; 

