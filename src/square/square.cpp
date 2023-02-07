#include "square.h" // might give an linker error 

void Square :: renderMyself (SDL_Renderer * renderer )
{
    int numvertices  = squareverticesarray.size () ; 
    for (int i = 0 ; i <= numvertices  ; i++ ){
        SDL_RenderDrawLine(renderer , squareverticesarray[i].x , squareverticesarray[i].y , 
        squareverticesarray[i-1].x , squareverticesarray[i-1].y );
     }
}
Square::Square(float  squareWidth ){ 
    glm::mat4 model (1.0f) ; 
    model = glm::scale (model , glm::vec3 (4.0f)); 
    glm::mat4 rotatedMatrix  = model;  
    for (int i = 0 ; i <= 4 ; i++ ) {
        rotatedMatrix = glm::rotate (rotatedMatrix , 90.0f/* angle in the radians */  , 
        glm::vec3 (0.0f , 0.0f  , 1.0f )/*we are rotating it along the z axis */ ) ;
        glm::vec4 vertex = rotatedMatrix * glm::vec4(1.0f ) ;  
        squareverticesarray.push_back (vertex ) ; 
    }

} 
