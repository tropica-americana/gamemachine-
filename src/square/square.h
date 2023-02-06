#include <iostream>
// #include <SDL2/SDL.h>
#include <vector> 
#include <map>
#include "glm/glm.hpp"
#include <SDL2/SDL.h>
#include <array>
class Square {
    double squareWidth ; 
    glm::vec3 squarePosition(0.0f) ; 
    glm::vec3 squareOrientation (0.0f) ; // contains the value of square rotation in radians  
    std::vector <glm::vec3> squareverticesarray  ;   
    Square (double squareWidth ) ; 
    ~Square ()  ; 
    double square_width ; 
    void renderMyself ( SDLsRenderer * renderer ) ;  
}; 




