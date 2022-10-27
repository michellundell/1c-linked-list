
#include <stdio.h>
#include <stdlib.h>

struct LinkedNode {
	int data;
	struct LinkedNode *next;
};

void printList(struct LinkedNode *start)
{
	struct LinkedNode *pl = start;
	for( pl = start; pl != NULL; pl = pl->next ) {
		printf("%d ",pl->data);
	}
	printf("\n");
}

struct LinkedNode *createList()
{
	struct LinkedNode *p2 = NULL;
	struct LinkedNode *pl = malloc(sizeof(struct LinkedNode));
	pl->data = rand()%100;
	pl->next = NULL;
	for(int i=0;i<10;i++) {
		p2 = malloc(sizeof(struct LinkedNode));
		p2->data = rand()%100;
		p2->next = pl;
		pl = p2;
	}
	return(pl);
}

void sortList(struct LinkedNode *start)
{
    struct LinkedNode *node=NULL, *temp = NULL;
    int tempvar;//temp variable to store node data
    int swapping = 0;
    do {
	    printf("sorting list\n");
	    node = start;
	    swapping = 0;
	    while(node != NULL)
	    {
		temp=node; 
		while (temp->next !=NULL) /*travel till the second last element */
		{
		   if(temp->data > temp->next->data) /*compare the data of the nodes */
		   {
		      printf("%d > %d, swapping\n",temp->data,temp->next->data);
		      swapping = 1;
		      tempvar = temp->data;
		      temp->data = temp->next->data; /* swap the data */
		      temp->next->data = tempvar;
		      printList(start);
		   }
		 temp = temp->next;    /* move to the next element  */
		}
		node = node->next;    /* move to the next node */
	    }
    } while( swapping );
}

int main(int argc, char **argv)
{
	struct LinkedNode *lista = createList();
	printf("created list\n");
	printList(lista);
	printf("sorting ...\n");
	sortList(lista);
	printf("sorted list\n");
	printList(lista);
	return(0);
}
