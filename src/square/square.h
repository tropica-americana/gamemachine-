#include <iostream>
// #include <SDL2/SDL.h>
#include <vector> 
#include <map>
#include "glm/glm.hpp"
#include <SDL2/SDL.h>
#include <array>
#include "glm/gtc/matrix_transform.hpp"
#include <glm/gtx/string_cast.hpp>
#include <string>
class Square {
    public:
    float  squareWidth ; 
    glm::vec3 squarePosition ; 
    glm::vec3 squareOrientation ; // contains the value of square rotation in radians  
    std::vector <glm::vec4> squareverticesarray  ;   
    Square (float squareWidth ) ; 
    ~Square () = default   ; 
    void renderMyself ( SDL_Renderer * renderer ) ;  
}; 




