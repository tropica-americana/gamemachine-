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
    int numvertices  = squareverticesarray.size () ; 
    auto iterator = squareverticesarray.begin () ;
    std::cout<<numvertices<<std::endl;
    for (int i = 0 ; i < numvertices  ; i++ ){
        if (i != 0 && iterator != squareverticesarray.end ()  ){
        iterator++ ; 
        SDL_RenderDrawLine(renderer , squareverticesarray[i].x , squareverticesarray[i].y , 
        squareverticesarray[i-1].x , squareverticesarray[i-1].y );} ; 
        if (iterator == squareverticesarray.end ()) {
            auto start = squareverticesarray.begin () ; 
            SDL_RenderDrawLine(renderer , iterator->x , iterator->y , start->x , start->y  );
        };
     }    
}

Square::Square(float  squareWidth ): squareWidth{squareWidth} { 
    squarePosition.x = 300.0f ; 
    squarePosition.y = 300.0f ;
    squarePosition.z = 10.0f ; 
    glm::mat4 model (1.0f) ; 
    model = glm::scale (model , glm::vec3 (squareWidth , squareWidth , squareWidth)); 
    // tranlate the model matrix to a specific position 
    // model = glm::translate (model , squarePosition );
    for (int i = 0 ; i < 4 ; i++)
    {  

        model = glm::rotate (model , 90.0f/* angle in the radians */  , 
        glm::vec3 (0.0f , 0.0f  , 1.0f )/*we are rotating it along the z axis */ ) ;
        display_model(model , "before translation "); 
        glm::vec4 vertex =  (model * glm::vec4(1.0f))+ glm::vec4(squarePosition , 1.0f) ; 
        std::cout<< glm::to_string(vertex) <<std::endl; 
        squareverticesarray.push_back (vertex ) ; 

    }                                                  
}

