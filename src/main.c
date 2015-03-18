#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#define ARRAY_SIZE 100

int filenotfound(FILE*);
int filenull(char[]);

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

	//Initialize linkedlist with first int
	int initial;
	fscanf(file,"%d",&initial);	
	LINKEDLIST list = createList(initial);

	//Continue to take input till EOF
	int nextint;
	while(!feof(file)) {
		fscanf(file,"%d",&nextint);
		addNode(&list,nextint);
	}
	printf("%d\n",list.tail->value);
	return EXIT_SUCCESS;
}

/**
*This function ensures that the file exists
**/
int filenotfound(FILE *fp) {
	if(fp == 0) return 1;
	else return 0;
}

int filenull(char filename[ARRAY_SIZE]) {
	FILE *testfile;
	testfile = fopen(filename,"r");
	getc(testfile);
	if(feof(testfile)) {
		fclose(testfile);
		return 1;
	}
	else {
		fclose(testfile);
		return 0;
	}
}
