#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <dirent.h>
#include <

void go_through(char *path){
	DIR *dir;
	struct dirent *file;
	dir = opendir(path);
	char *fullpath;
	if(dir){
		while((file = readdir(dir))!=NULL){
			if(strcmp(file->d_name, "..")||strcmp(file->d_name, ".")){ continue; }
			fullpath = strcomb(path, "/");
			fullpath = strcomb(fullpath, file->d_name);
			if(opendir(fullpath)!=NULL){ go_through(fullpath); }
			else { printf("%s\n", fullpath); }
		}
		closedir(dir);
	}
}

int main(){
	go_through("test");
	return 0;
}
