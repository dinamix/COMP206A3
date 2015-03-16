typedef struct NODE {
	int index;
	int value;
}NODE;

typedef struct LINKEDLIST {
	NODE firstnode;
	NODE *head;
	NODE *tail;
}LINKEDLIST;
