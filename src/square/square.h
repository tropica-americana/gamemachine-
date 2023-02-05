#include <iostream>
// #include <SDL2/SDL.h>
#include <vector> 
#include <map>
#include <glm/glm.hpp>
#include <SDL2/SDL.h>
class Square {
    glm::vec4 squarePosition() ; 
    glm::vec4 squareOrientation () ; 
    
    double square_width ; 
    void renderMyself ( SDL_Renderer * renderer ) ;  
}; 




