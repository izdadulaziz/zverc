
#ifndef TEMPLATES_H
#define TEMPLATES_H

#define SRC_DIR 	"src"
#define BUILD_DIR 	"build"
#define BIN_DIR 	"build/bin"
#define INCLUDE_DIR "include"

#include "status.h"

Status create_file(char* fname, char* fcontent);

Status create_dir(char* dirname);

Status template_main_c(char* project_name);

Status template_main_cpp(char* project_name);

Status template_makefile_c(char* project_name);

Status template_makefile_cpp(char* project_name);

Status template_dir(char* project_name);

#endif // TEMPLATES_H
