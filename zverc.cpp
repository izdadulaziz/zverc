

#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>

#include "zverc.h"

    
std::string version = "1.0";

void gen_template_file(const std::string& name_project){

    std::ofstream main_file(name_project + "/src/main.cpp");
    std::ofstream hello_file(name_project + "/src/hello.cpp");
    std::ofstream header_hello(name_project + "/include/hello.h");

    std::cout << "Generate default files" << std::endl;

    if(main_file){

        main_file << "#include <iostream>\n\n";
        main_file << "#include \"hello.h\"\n";
        main_file << "int main(){";
        main_file << "    \n";
        main_file << "    hello();";
        main_file << "    \n";
        main_file << "    return 0;";
        main_file << "}";


    }else{

        std::cout << "Failed generate main.cpp" << std::endl;

    }


    if(hello_file){
            
        hello_file << "#include <iostream>\n\n";
        hello_file << "#include \"hello.h\"\n";
        hello_file << "void hello(){";
        hello_file << "    \n";
        hello_file << "    std::cout << \"Hello World!\" << std::endl;";
        hello_file << "    \n";
        hello_file << "}";


    }else{
            
        std::cout << "Failed generate hello.cpp" << std::endl;

    }


    if(header_hello){
            
        header_hello << "#ifndef HELLO_H\n";
        header_hello << "#define HELLO_H\n\n";
        header_hello << "void hello();\n";
        header_hello << "#endif // HELLO_H";

    }else{

        std::cout << "Failed generate hello.h" << std::endl;

    }

        

}


void gen_make_file(const std::string& name_project){

    std::ofstream make_file(name_project + "/Makefile");

    if(make_file){

        make_file << "TARGET = bin/" << name_project << std::endl;
        make_file << "CC = g++\n" << std::endl;
        make_file << "$(TARGET) : build/main.o build/hello.o" << std::endl;
        make_file << "\t$(CC) $^ -o $@\n" << std::endl;
        make_file << "build/main.o : src/main.cpp include/hello.h" << std::endl;
        make_file << "\t$(CC) -Iinclude -c $< -o $@\n" << std::endl;
        make_file << "build/hello.o : src/hello.cpp include/hello.h" << std::endl;
        make_file << "\t$(CC) -Iinclude -c $< -o $@\n" << std::endl;
        make_file << "clean :" << std::endl;
        make_file << "\trm -f $(TARGET) build/main.o build/hello.o" << std::endl;



    }else{
        
        std::cout << "Failed generate file Makefile" << std::endl;
        
    }


}
    


void gen_folder(const std::string& name_project){

    if(std::filesystem::create_directory(name_project)){

        std::cout << "Generate folder " << name_project << std::endl;

    }else{

        std::cout << "Failed Generate folder " << name_project << std::endl;
    }


    if(std::filesystem::create_directory(name_project + "/src")){

        std::cout << "Generate folder src" << std::endl;

    }else{

        std::cout << "Failed generate folder src" << std::endl;

    }


    if(std::filesystem::create_directory(name_project + "/include")){
            
        std::cout << "Generate include folder" << std::endl;

    }else{
            
        std::cout << "Failed generate include folder" << std::endl;

    }


    if(std::filesystem::create_directory(name_project + "/bin")){

        std::cout << "Generate bin folder" << std::endl;

    }else{
            
        std::cout << "Failed generate bin folder" << std::endl;

    }


    if(std::filesystem::create_directory(name_project + "/build")){

        std::cout << "Generate build folder " << std::endl;

    }else{

        std::cout << "Failed generate build folder" << std::endl;

    }


}

std::string parse_argument(const int argc, const char* argv[]){
            

    std::string argv0;
    std::string argv1;

    if(argc == 1){

        argv0 = argv[0];

    }else if(argc == 2){

        argv1 = argv[1];

    }

    if(argc == 1)
        return "none";

    if((argc == 2) & (argv1 == "generate"))
        return "generate";
        
    if((argc == 2 ) & (argv1  == "help"))
        return "help";
        
    return "none";

}

void generate_template(const std::string& name_project){

    gen_folder(name_project);

    gen_template_file(name_project);

    gen_make_file(name_project);

}

