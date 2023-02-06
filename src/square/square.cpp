#include "square.h" // might give an linker error 

void Square :: renderMyself (SDL_Renderer * renderer )
{
    numvertices  = squareverticesarray.size () ; 
    for (int i = 0 ; i <= numvertices  ; i++ ){
    
     }
}
Square::Square(double squareWidth ){ 
    glm::mat4 model (1.0f) ; 
    model = glm::scale (model , square_width) ; 
    for (int i = 0 ; i <= 4 ; i++ ) {
        glm::vec3 vertex = glm::rotate (model , 90.0f/* angle in the radians */  , 
        glm::vec3 (0.0f , 0.0f  , 1.0f )/*we are rotating it along the z axis */ ) ; 
        squareverticesarray.pushback (vertex ) ; 
    }

} 
 