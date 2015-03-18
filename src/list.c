#include <stdlib.h>
#include <stdio.h>
#include "list.h"

/*
*PLEASE NOTE THAT IMPLEMENTATION USING
*A LINKEDLIST STRUCT AND A NODE STRUCT
*WAS APPROVED BY PROFESSOR VYBIHAL
*WITH FUNCTION INPUTS CHANGED ACCORDINGLY
*/

NODE currentnode = {-1};
NODE *head;
NODE *tail;

LINKEDLIST createList(int nvalue) {
	LINKEDLIST newlist;
	NODE afirstnode = {0,nvalue};
	newlist.firstnode = afirstnode;
	newlist.head = &newlist.firstnode;
	newlist.tail = &newlist.firstnode;
	return newlist;
}

void addNode(LINKEDLIST* thislist,int newvalue) {
	int newindex = thislist->tail->index + 1;	
	NODE newnode = {newindex,newvalue,NULL};	
	thislist->tail->nextnode = &newnode;
	printf("lol %d %d\n",thislist->tail->nextnode->value,thislist->tail->nextnode->index);
	thislist->tail = &newnode;
	printf("%d\n",thislist->tail->nextnode->value);
}

void add(int newvalue) {
	if(currentnode.index == -1) {
		NODE first = {0,newvalue,NULL};
		currentnode = first;
		head = &first; 
		tail = &first;
	}
	else {
		NODE newnode = {currentnode.index + 1,newvalue,NULL};
		tail->nextnode = &newnode;
		currentnode = newnode;
	}
}

void prettyPrint(LINKEDLIST* thislist) {
	//int n = thislist->head->nextnode->value;
	//printf("%d\n",n);
	//printf("%d\n",thislist->head->value);
}
