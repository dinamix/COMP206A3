#include "list.h"

LINKEDLIST createList(int nvalue) {
	LINKEDLIST newlist;
	NODE afirstnode = {0,nvalue};
	newlist.firstnode = afirstnode;
	newlist.head = &newlist.firstnode;
	newlist.tail = &newlist.firstnode;
	return newlist;
}

