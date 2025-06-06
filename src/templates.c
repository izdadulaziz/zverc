

#include <stdio.h>
#include <sys/stat.h>

#include "templates.h"
#include "status.h"

Status create_file(char* fname, char* fcontent){
	
	FILE* file = fopen(fname, "w");

	if(file == NULL)
		return STATUS_NULL;

	fprintf(file, "%s", fcontent);

	fclose(file);

	return STATUS_OK;

}

Status create_dir(char* dirname){
	
	int r = mkdir(dirname, 0777);
	
	return (r == 0) ? STATUS_OK : STATUS_ERROR;
}

Status template_main_c(char* project_name){

	char fname[55];
	char fcontent[150];

	snprintf(fname, sizeof(fname),
			"%s/%s/main.c",
			project_name, SRC_DIR);

	snprintf(fcontent, sizeof(fcontent),
			"\n#include <stdio.h>\n\n"
			"int main(){\n\n"
			"\tprintf(\"Hello world\\n\");\n\n"
			"\treturn 0;\n"
			"}");

	Status fresult = create_file(fname, fcontent);

	return (fresult == STATUS_OK) ? STATUS_OK : STATUS_ERROR;

}

Status template_main_cpp(char* project_name){

	char fname[55];
	char fcontent[150];

	snprintf(fname, sizeof(fname),
			"%s/%s/main.cpp",
			project_name, SRC_DIR);

	snprintf(fcontent, sizeof(fcontent),
			"\n#include <iostream>\n\n"
			"int main(){\n\n"
			"\tstd::cout << \"Hello world\" << std::endl;\n\n"
			"\treturn 0;\n"
			"}");

	Status fresult = create_file(fname, fcontent);
	
	return (fresult == STATUS_OK) ? STATUS_OK : STATUS_ERROR;

}

Status template_makefile_c(char* project_name){

	char fname[60];
	char fcontent[300];

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

	Status fresult = create_file(fname, fcontent);
	
	return (fresult == STATUS_OK) ? STATUS_OK : STATUS_ERROR;
}


Status template_makefile_cpp(char* project_name){

	char fname[60];
	char fcontent[300];

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

	Status fresult = create_file(fname, fcontent);

	return (fresult == STATUS_OK) ? STATUS_OK : STATUS_ERROR;

}

Status template_dir(char* project_name){
	

	char dirsrc[50];
	char dirbuild[50];
	char dirbin[50];
	char dirinclude[50];

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

	Status root 	= create_dir(project_name);
	Status src 		= create_dir(dirsrc);
	Status build 	= create_dir(dirbuild);
	Status bin 		= create_dir(dirbin);
	Status include	= create_dir(dirinclude);
	
	Status arr_result[] = {root, src, build, bin, include};

	for(int i = 0; i < 4; i++){
		if(arr_result[i] == STATUS_ERROR)
			return STATUS_ERROR;

	}

	return STATUS_OK;
}




