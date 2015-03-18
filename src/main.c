#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

#define ARRAY_SIZE 100

BOOLEAN filenotfound(FILE*);
BOOLEAN isYes(char[]);
void printRemove(BOOLEAN);

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

	char decision[ARRAY_SIZE];	
	do{
		//Remove given value
		printf("Please provide int to remove: ");
		int input;
		scanf("%d",&input);
		printRemove(delete(input));

		//Ask if want to remove another value
		printf("Would you like to delete another int? ");
		scanf("%s",decision);

	}while(isYes(decision));

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

/**
*Checks to ensure input matches yes
**/
BOOLEAN isYes(char *decision) {
	if(strcmp(decision,"Yes") == 0 ||
	   strcmp(decision,"YES") == 0 ||
	   strcmp(decision,"yes") == 0 ||
	   strcmp(decision,"Y") == 0 ||
	   strcmp(decision,"y") == 0 )
	{
		return TRUE;
	}	
	else return FALSE;
}

void printRemove(BOOLEAN check) {
	if(check == TRUE) {
		printf("NUMBER WAS DELETED\n");
	}
	else {
		printf("NUMBER WAS NOT FOUND\n");
	}
	prettyPrint();
}
