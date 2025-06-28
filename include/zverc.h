
#ifndef ZVERC_H
#define ZVERC_H

#include "status.h"

#define VERSION "1.0"

/*
 * function for parse the user argument
 *
 * @param argc argument count
 * @param argv[] argument vector
 * @return Status
 *
 * */
Status parse_argument(int argc, char* argv[]);

/*
 * function for generate the template
 *
 * @param project_name the name op project
 * @param lang_type the type of language c or cpp
 * @return Status
 * 
 * */
Status generate_templates(char* project_name, Lang lang_type);

/*
 * function for print help
 *
 * @return void
 *
 * */
void print_help();

/*
 * function for print invalid argument
 *
 * @return void
 *
 * */
void print_invalid_argument();

/*
 * function for print the version of zverc
 *
 * @return void
 *
 * */
void print_version();

/*
 * function for print the example how to use zverc 
 *
 * @return void
 *
 * */
void print_example();

/*
 * function for print warning to user that the type language is missing
 *
 * @return void 
 *
 * */
void print_type_missing();

/*
 * function for print warning to user that the name of project is missing 
 *
 * @return void 
 *
 * */
void print_project_name_missing();

/*
 * function for print warning to user that the name of project is to long
 *
 * @return void 
 *
 * */
void print_project_name_tl();

/*
 * function for print to user that generate the template is success
 *
 * @return void 
 * */
void print_gen_success(char* project_name);

/*
 * function for print to user that generate the template is failes
 *
 * @return void
 *
 * */
void print_gen_failed(char* project_name);

#endif // ZVERC_H
