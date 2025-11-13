
#include <stdio.h>
#include <string.h>

#include "zverc.h"
#include "status.h"
#include "templates.h"

Status parse_argument(int argc, char* argv[]){

	if(argc == 1)
		return STATUS_INVALID_ARGUMENT;


	if(argc == 2 && argv[1] != NULL){
		if(strcmp(argv[1], "create") == 0){
			return STATUS_TYPE_MISSING;

		}else if(strcmp(argv[1], "help") == 0){
			return STATUS_PRINT_HELP;

		}else if(strcmp(argv[1], "version") == 0){
			return STATUS_PRINT_VERSION;

		}else if(strcmp(argv[1], "example") == 0){
			return STATUS_PRINT_EXAMPLE;

		}else{
			return STATUS_INVALID_ARGUMENT;

		}

	}else if(argc == 4 && strcmp(argv[1], "create") == 0 && strcmp(argv[2], "c") == 0){
 
		if(strlen(argv[3]) > 36)
			return STATUS_PROJECT_NAME_TL;

		if(argv[3] == NULL || strlen(argv[3]) == 0)
			return STATUS_PROJECT_NAME_MISSING;
		else
			return STATUS_CREATE_C;

		
	
	}else if(argc == 4 && strcmp(argv[1], "create") == 0 && strcmp(argv[2], "cpp") == 0){
		
		if(strlen(argv[3]) > 36)
			return STATUS_PROJECT_NAME_TL;
		
		if(argv[3] == NULL || strlen(argv[3]) == 0)
			return STATUS_PROJECT_NAME_MISSING;
		else
			return STATUS_CREATE_CPP;

	}else{
		return STATUS_INVALID_ARGUMENT;

	}

}

Status generate_templates(char* project_name, Lang lang_type){
	
	if(lang_type == LANG_C){
		
		Status gen_dir 		= template_dir(project_name);
		Status gen_main 	= template_main_c(project_name);
		Status gen_makefile = template_makefile_c(project_name);
		
	 	return (gen_dir == STATUS_OK && gen_main == STATUS_OK && gen_makefile == STATUS_OK) ? STATUS_OK : STATUS_ERROR;

	}else if(lang_type == LANG_CPP){

		Status gen_dir = template_dir(project_name);
		Status gen_main = template_main_cpp(project_name);
		Status gen_makefile = template_makefile_cpp(project_name);

		return (gen_dir == STATUS_OK && gen_main == STATUS_OK && gen_makefile == STATUS_OK) ? STATUS_OK : STATUS_ERROR;

	}else{

		return STATUS_ERROR;

	}

}

void print_help(){
    
    printf("USAGE: zverc <OPTION> OR zverc [OBJECT] [TYPE] <PROJECT NAME>\n");
    printf("OPTION:\n");
    printf("\thelp -> print this\n\tversion -> print version\n");
    printf("OBJECT:\n");
    printf("\tcreate -> generate template\n");
    printf("TYPE:\n");
    printf("\tc -> template c\n\tcpp -> template cpp\n");
  
}

void print_invalid_argument(){

	printf("try zverc help for more information\n");

}	

void print_version(){
	
	printf("Version v%s\n", VERSION);

}

void print_example(){

	printf("EXAMPLE :\n\tzverc [COMMAND]\n\t\tzverc version -> print version\n\tzverc [COMMAND] [TYPE] <PROJECT NAME>\n\t\tzverc create c helloworld -> create project name helloworld with templates c\n");
}

void print_type_missing(){
	
	printf("TYPE?\nc or cpp?\ntry zverc help for more information\n");
}

void print_project_name_missing(){
	
	printf("PROJECT NAME?\ntry zverc help for more information\n");
}
void print_project_name_tl(){
	
	printf("LENGTH OF PROJECT NAME MUST < 36\n");
}
void print_gen_success(char* project_name){
	
	printf("SUCCESS\nProject %s created\n", project_name);

}

void print_gen_failed(char* project_name){
	
	printf("FAILED\nProject %s not created\n", project_name);

}
