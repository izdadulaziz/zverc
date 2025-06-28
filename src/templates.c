

#include <stdio.h>
#include <sys/stat.h>

#include "templates.h"
#include "status.h"

Status create_file(char* fname, char* fcontent){

    // open a file and the mode is write
	FILE* file = fopen(fname, "w");
    
    // return STATUS_NULL if file isnull
	if(file == NULL)
		return STATUS_NULL;
    
    // write file
	fprintf(file, "%s", fcontent);

    //close file
	fclose(file);

	return STATUS_OK;

}

Status create_dir(char* dirname){
	
    // make directory 
	int r = mkdir(dirname, 0777);

	// return STATUS_OK if success and return STATUS_ERROR if failed
	return (r == 0) ? STATUS_OK : STATUS_ERROR;
}

Status template_main_c(char* project_name){

	char fname[55]; // variable for store file name
	char fcontent[150]; // variable for store content of file

	snprintf(fname, sizeof(fname),
			"%s/%s/main.c",
			project_name, SRC_DIR);

	snprintf(fcontent, sizeof(fcontent),
			"\n#include <stdio.h>\n\n"
			"int main(){\n\n"
			"\tprintf(\"Hello world\\n\");\n\n"
			"\treturn 0;\n"
			"}");

    // create file main.c
	Status fresult = create_file(fname, fcontent);
    
    // return STATUS_OK if success and return STATUS_ERROR if failed
	return (fresult == STATUS_OK) ? STATUS_OK : STATUS_ERROR;

}

Status template_main_cpp(char* project_name){

	char fname[55]; // variable  for store file name 
	char fcontent[150]; // variable for store content  of file 

	snprintf(fname, sizeof(fname),
			"%s/%s/main.cpp",
			project_name, SRC_DIR);

	snprintf(fcontent, sizeof(fcontent),
			"\n#include <iostream>\n\n"
			"int main(){\n\n"
			"\tstd::cout << \"Hello world\" << std::endl;\n\n"
			"\treturn 0;\n"
			"}");
    // create main.cpp
	Status fresult = create_file(fname, fcontent);
	
    // return STATUS_OK if success and return STATUS_ERROR if failed
	return (fresult == STATUS_OK) ? STATUS_OK : STATUS_ERROR;

}

Status template_makefile_c(char* project_name){

	char fname[60]; // variable for store file name
	char fcontent[300]; // variable  for  store file content

	snprintf(fname, sizeof(fname),
			"%s/Makefile",
			project_name);

	snprintf(fcontent, sizeof(fcontent),
			"NAME=hello\n\n"
			"CC=gcc\n"
			"TARGET=build/bin/$(NAME)\n\n"
			"SRCFILE=src/main.c\n"
			"OBJFILE=build/main.o\n\n"
			"$(TARGET) : $(OBJFILE)\n"
			"\t$(CC) $< -o $@\n\n"
			"$(OBJFILE) : $(SRCFILE)\n"
			"\t$(CC) -c $< -o $@\n\n"
			"clean :\n"
			"\trm $(OBJFILE) $(TARGET)\n");

    // create file Makefile
	Status fresult = create_file(fname, fcontent);
	
    // return STATUS_OK if success and  return STATUS_ERROR if failed
	return (fresult == STATUS_OK) ? STATUS_OK : STATUS_ERROR;
}


Status template_makefile_cpp(char* project_name){

	char fname[60]; // variable for  store file name
	char fcontent[300]; // variable for store file content

	snprintf(fname, sizeof(fname),
			"%s/Makefile",
			project_name);

	snprintf(fcontent, sizeof(fcontent),
			"NAME=hello\n\n"
			"CXX=g++\n"
			"TARGET=build/bin/$(NAME)\n\n"
			"SRCFILE=src/main.cpp\n"
			"OBJFILE=/build/main.o\n"
			"$(TARGET : $(OBJFILE)\n"
			"\t$(CXX) $< -o $@\n\n"
			"$(OBJFILE) : $(SRCFILE)\n"
			"\t$(CXX) -c $< -o $@\n\n"
			"clean :\n"
			"\trm $(OBJFILE) $(TARGET)\n");
    
    // create file Makefile
	Status fresult = create_file(fname, fcontent);
    
    // return STATUS_OK if  success and return STATUS_ERROR if failed
	return (fresult == STATUS_OK) ? STATUS_OK : STATUS_ERROR;

}

Status template_dir(char* project_name){
	

	char dirsrc[50]; // variable for store name of src directory
	char dirbuild[50]; // variable for store name of build directory
	char dirbin[50]; // variable for store name of bin directory
	char dirinclude[50]; // variabe for store name of include directory

	snprintf(dirsrc, sizeof(dirsrc),
			"%s/%s/",
			project_name, SRC_DIR);

	snprintf(dirbuild, sizeof(dirbuild),
			"%s/%s/",
			project_name, BUILD_DIR);

	snprintf(dirbin, sizeof(dirbin),
			"%s/%s/",
			project_name, BIN_DIR);

	snprintf(dirinclude, sizeof(dirinclude), 
			"%s/%s/",
			project_name, INCLUDE_DIR);
    
    // create directory
	Status root 	= create_dir(project_name);
	Status src 		= create_dir(dirsrc);
	Status build 	= create_dir(dirbuild);
	Status bin 		= create_dir(dirbin);
	Status include	= create_dir(dirinclude);
	
    // array of result create directory
	Status arr_result[] = {root, src, build, bin, include};

    /*
     * check all item in arr_result
     *
     * if in arr_result have STATUS_ERROR return STATUS_ERROR
     * if in arr_result don't have STATUS_ERROR return STATUS_OK
     */
	for(int i = 0; i < 4; i++){
		if(arr_result[i] == STATUS_ERROR)
			return STATUS_ERROR;

	}

	return STATUS_OK;
}




