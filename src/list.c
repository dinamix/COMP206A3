#include <stdlib.h>
#include <stdio.h>
#include "list.h"

/*NODE *head;
NODE *tail;
NODE firstnode;
head = &firstnode;

void add(int nvalue) {
	
}*/

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
	NODE newnode = {newindex,newvalue};	
	thislist->tail->nextnode = &newnode;
	thislist->tail = &newnode;
}
