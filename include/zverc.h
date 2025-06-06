
#ifndef ZVERC_H
#define ZVERC_H

#include "status.h"

#define VERSION "1.0"

Status parse_argument(int argc, char* argv[]);

Status generate_templates(char* project_name, Lang lang_type);

void print_help();

void print_invalid_argument();

void print_version();

void print_example();

void print_type_missing();

void print_project_name_missing();

void print_project_name_tl();

void print_gen_success(char* project_name);

void print_gen_failed(char* project_name);

#endif // ZVERC_H
