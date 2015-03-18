#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "list.h"

#define ARRAY_SIZE 100

BOOLEAN filenotfound(FILE*);
BOOLEAN filenull(char[]);

int main() {
	//Create and initialize file
	FILE *file;
	char filename[ARRAY_SIZE];
	do {
		printf("Please enter filename : ");
		scanf("%s",filename);
		file = fopen(filename,"r");
	}while(filenotfound(file));

	//Continue to take input till EOF
	int nextint;
	fscanf(file,"%d",&nextint);
	while(!feof(file)) {
		add(nextint);
		fscanf(file,"%d",&nextint);
	}

	//Print out values in list in order
	prettyPrint();
	
	delete(26);

	prettyPrint();
	fclose(file);
	return EXIT_SUCCESS;
}

/**
*This function ensures that the file exists
**/
BOOLEAN filenotfound(FILE *fp) {
	if(fp == 0) return TRUE;
	else return FALSE;
}
