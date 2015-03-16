#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
	LINKEDLIST list = createList(20);
	printf("%d\n",list.firstnode.nextnode);
	return EXIT_SUCCESS;
}
