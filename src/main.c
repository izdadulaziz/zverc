

#include "zverc.h"
#include "status.h"

int main(int argc, char* argv[]){


	Status argument = parse_argument(argc, argv);
	
	if(argument == STATUS_INVALID_ARGUMENT){
		print_invalid_argument();

	}else if(argument == STATUS_PRINT_HELP){
		print_help();
		
	}else if(argument == STATUS_PRINT_VERSION){
		print_version();

	}else if(argument == STATUS_TYPE_MISSING){
		print_type_missing();

	}else if(argument == STATUS_PRINT_EXAMPLE){
		print_example();

	}else if(argument == STATUS_CREATE_C){
		Status rgen = generate_templates(argv[3], LANG_C);
		
		if(rgen == STATUS_OK)
			print_gen_success(argv[3]);
		else
			print_gen_failed(argv[3]);
	}else if(argument == STATUS_CREATE_CPP){
		
		Status rgen = generate_templates(argv[3], LANG_CPP);

		if(rgen == STATUS_OK)
			print_gen_success(argv[3]);
		else 
			print_gen_failed(argv[3]);
	
	}else if(argument == STATUS_PROJECT_NAME_MISSING){

		print_project_name_missing();

	}else if(argument == STATUS_PROJECT_NAME_TL){
		print_project_name_tl();

	}else{
		print_invalid_argument();

	}

	return 0;
}
