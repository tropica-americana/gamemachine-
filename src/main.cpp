#include <iostream>
#include <SDL2/SDL.h>
#include <vector> 
#include <map>
#include "./square/square.h"
#include "./game/game.h"
#include <glm/glm.hpp>
#include "glm/gtc/matrix_transform.hpp"
#include <glm/gtx/string_cast.hpp>
using namesspace std ; 

void display_model (glm::mat4 model )  {
    std::cout<<glm::to_string (model[0]) <<std::endl;     
    std::cout<<glm::to_string (model[1]) <<std::endl;       
    std::cout<<glm::to_string (model[2]) <<std::endl;    
    std::cout<<glm::to_string (model[3]) <<std::endl; 
} 

int main () {

    Game game ; 
    Square square ; 
    cout<<game.isRunning<<endl; 
    while (game.isRunning) {
        game.processInput() ; 
        game.update()  ; 
        square.renderMyself (game.renderer);
        game.render () ; 
    }

    // glm::vec4 vertex (1.0f , 5.0f , 1.0f , 1.0f ) ; 
    // glm::mat4 model (1.0f ) ;  
    // model = glm::scale (model , glm::vec3 (2.0f) ) ; 
    // model = glm::rotate (model, glm::radians (180.0f ) , glm::vec3 (0,1,0) ) ; 
  
    // glm:: vec4 worldspace_vertex  = (model * vertex ) ; 
    // std::cout << glm::to_string (worldspace_vertex) <<std::endl ; 
    
    return 0 ;  }