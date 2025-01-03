
#ifndef ZVERC_H
#define ZVERC_H

#include <string>

namespace zverc{

    extern std::string gitignore;
    extern std::string version;

    void nf();

    void help();
    
    void ver();

    bool check(std::string &name);

    bool make_folder(std::string &name_folder);

    bool make_file(std::string &name_file);

    std::string template_cpp(std::string &name_project);

}

#endif // ZVERC_H

