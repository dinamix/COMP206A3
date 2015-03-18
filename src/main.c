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
	
	//Check if file has something in it
	if(filenull(filename)) {
		printf("Nothing found in file.\n");
		return EXIT_SUCCESS;
	}
	
	/*Initialize list
	int initint;
	fscanf(file,"%d",&initint);
	init(initint);
	*/

	//Continue to take input till EOF
	int nextint;
	fscanf(file,"%d",&nextint);
	while(!feof(file)) {
		add(nextint);
		fscanf(file,"%d",&nextint);
	}
	prettyPrint();
	fclose(file);
	//printf("%d\n",list.tail->value);
	return EXIT_SUCCESS;
}

/**
*This function ensures that the file exists
**/
BOOLEAN filenotfound(FILE *fp) {
	if(fp == 0) return TRUE;
	else return FALSE;
}

/**
*This function checks if EOF is second char
*and ensure first char is not a digit
*If so, it returns that the file contains nothing
**/
BOOLEAN filenull(char filename[ARRAY_SIZE]) {
	FILE *testfile;
	testfile = fopen(filename,"r");
	char test = getc(testfile);
	if(feof(testfile) && !isdigit(test)) {
		fclose(testfile);
		return TRUE;
	}
	else {
		fclose(testfile);
		return FALSE;
	}
}
