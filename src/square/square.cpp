#include "square.h" // might give an linker error 
#include <algorithm>
static void display_model (const glm::mat4 &model , std::string &&content)  {
    std::cout<<std::endl; 
    std::cout<<content <<std::endl;
    std::cout<<glm::to_string (model[0]) <<std::endl;     
    std::cout<<glm::to_string (model[1]) <<std::endl;       
    std::cout<<glm::to_string (model[2]) <<std::endl;    
    std::cout<<glm::to_string (model[3]) <<std::endl; 
    std::cout<<std::endl;
} 
static void display_model (const glm::mat4 &model)  {
    std::cout<<std::endl;
    std::cout<<glm::to_string (model[0]) <<std::endl;     
    std::cout<<glm::to_string (model[1]) <<std::endl;       
    std::cout<<glm::to_string (model[2]) <<std::endl;    
    std::cout<<glm::to_string (model[3]) <<std::endl; 
    std::cout<<std::endl;
} 

void Square :: renderMyself (SDL_Renderer * renderer )
{
    //-----------------creating the square vertices --------------------------
    glm::mat4 model (1.0f) ; 
    model = glm::scale (model , glm::vec3 (squareWidth , squareWidth , squareWidth)); 
    for (int i = 0 ; i < 4 ; i++)
    {  
        model = glm::rotate (model ,( 1.5707f)/* angle in the radians */  , 
        glm::vec3 (0.0f , 0.0f  , 1.0f )/*we are rotating it along the z axis */ ) ;
        glm::vec4 vertex =  (model * glm::vec4(1.0f))+ glm::vec4(squarePosition , 1.0f) ; 
        squareverticesarray.push_back (vertex ) ; 

    }   
// ----------------------------------------------------------------------------------

    int numvertices  = squareverticesarray.size () ; 
    auto iterator_end = squareverticesarray.end() - 1  ;
    auto start = squareverticesarray.begin () ; 
    for (int i = 0 ; i <= numvertices  ; i++ ){
        if (i != 0 && i < numvertices  ){    
        SDL_RenderDrawLine(renderer , squareverticesarray[i].x , squareverticesarray[i].y , 
        squareverticesarray[i-1].x , squareverticesarray[i-1].y );} ; 
        if (i == numvertices ) {
            SDL_RenderDrawLine(renderer , (iterator_end)->x , (iterator_end)->y , start->x , start->y  );
        };
     }  

}

Square::Square(float  squareWidth ): squareWidth{squareWidth} { 
    squarePosition.x = 100.0f ; 
    squarePosition.y = 30.0f ;
    squarePosition.z = 10.0f ; 
                                                   
}
void Square::handleMouseEvents (SDL_MouseMotionEvent &mouseEvent) {
    if (mouseEvent.state &  SDL_BUTTON_LMASK )
    {
        squarePosition.x +=  mouseEvent.xrel ; 
        squarePosition.y +=  mouseEvent.yrel ; 
        std::cout<<"button pressed "<<std::endl;
    }
    
} 
