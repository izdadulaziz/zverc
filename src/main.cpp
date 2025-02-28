
#include <iostream>
#include <string>
#include "zverc.h"


int main(const int argc, const char* argv[]){

    std::string parse_result = parse_argument(argc, argv);
    std::string name_project;

    if(parse_result == "none"){
        
        std::cout << "Try zverc help" << std::endl;

    }else if (parse_result == "help"){

        std::cout << "usage : zverc <option>" << std::endl;
        std::cout << "\thelp => print this" << std::endl;
        std::cout << "\tgenerate => generate cpp template" << std::endl;

    }else if (parse_result == "generate"){

        std::cout << "Enter project name : ";
        std::cin >> name_project;

        if(!name_project.empty()){
            
            generate_template(name_project);

        }else{

            std::cout << "Name project is empty" << std::endl;

        }
    }

}
