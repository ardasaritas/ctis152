/* Linked List Library */
#include <stdlib.h>

typedef struct 
{
	int supplyID;
	double price;
} supply_t;

typedef supply_t LType;

typedef struct node_s
{	LType data;
	struct node_s *next; 
} node_t;

node_t *getnode (void)
{
	node_t *node;
	node = (node_t *) malloc (sizeof(node_t));
	node->next = NULL;
	return (node);
}

void addAfter (node_t *p, LType item)
{
	node_t *newp;
	newp = getnode();	
	newp->data = item;
	newp->next = p->next;
	p->next = newp;
}

node_t *addBeginning (node_t *headp, LType item)
{	
	node_t *newp;
	newp = getnode();	
	newp->data = item;
	newp->next = headp;
	return (newp);
}


node_t *deleteBeginning(node_t *hp)
{
	node_t *del = hp; // flag the first node
	hp = hp->next; // move the to second node
	free(del); // free the first node
	return(hp); // return the new list pointer
}

void deleteAfter(node_t *p)
{
	node_t *del = p->next; // flag the node to be deleted
	p->next = del->next; // link previous and after 
	free (del); // free the flagged node
}