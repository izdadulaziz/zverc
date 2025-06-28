
#ifndef TEMPLATES_H
#define TEMPLATES_H

#define SRC_DIR 	"src"
#define BUILD_DIR 	"build"
#define BIN_DIR 	"build/bin"
#define INCLUDE_DIR "include"

#include "status.h"
/*
 * function fo create file
 *
 * @param fname file name
 * @param fcontent file content
 * @return Status 
 *
 **/
Status create_file(char* fname, char* fcontent);

/*
 * function for create directory
 *
 * @param dirname directory name
 * @return Status
 *
 **/
Status create_dir(char* dirname);

/*
 * function for create file main.c
 *
 * @param project_name the name of project
 * @return Status
 *
 **/
Status template_main_c(char* project_name);

/*
 * function for create main.cpp
 *
 * @param project_name the name of project
 * @return Status
 *
 * */
Status template_main_cpp(char* project_name);

/*
 * function for create file Makefile only for c 
 *
 * @param project_name the name of project 
 * @return Status
 *
 * */
Status template_makefile_c(char* project_name);

/*
 * function for create file Makefile only for cpp
 *
 * @param project_name the name of project
 * @return Status
 *
 * */
Status template_makefile_cpp(char* project_name);

/*
 * function for create folder structure of project
 *
 * @param project_name the name of project
 * @return Status
 *
 * */
Status template_dir(char* project_name);

#endif // TEMPLATES_H
