/* Linked List Library */
#include <stdlib.h>

typedef struct 
{
	int ID;
	char name[20];
	double price;
} vegAndFruit_t;

typedef vegAndFruit_t LType;

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

node_t * deleteBeginning(node_t *hp)
{
	node_t *del;
	del = hp;
	hp = hp->next;
	free(del);
	return hp;
}

void deleteAfter(node_t *p)
{
	node_t *del;
	del = p->next;
	p->next = del->next;
	free(del);
}