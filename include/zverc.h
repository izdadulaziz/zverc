
#ifndef ZVERC_H
#define ZVERC_H

#include <string>

extern std::string version;

void gen_template_file(const std::string& name_project);

void gen_make_file(const std::string& name_project);

void gen_folder(const std::string& name_project);

std::string parse_argument(const int argc, const char* argv[]);

void generate_template(const std::string& name_project);


#endif // ZVERC_H
