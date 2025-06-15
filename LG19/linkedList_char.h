#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef char LType;

typedef struct node_s
{
	LType data;
	struct node_s *next;
}node_t;

node_t *getNode(void)
{
	node_t *node;
	node = (node_t *)malloc(sizeof(node_t));
	node->next = NULL;
	return (node);
}

void addAfter(node_t *p, LType item)
{
	node_t *newp;
	newp = getNode();
	newp->next = p->next;
	p->next = newp;
	newp->data = item;
}

node_t *addBeginning(node_t *hp, LType item)
{
	node_t *newp;
	newp = getNode();
	newp->next = hp;
	newp->data = item;
	return(newp);
}

node_t *createList(node_t *hp, char A[], int size)
{
	hp = addBeginning(hp, A[0]);
	node_t *tp;
	tp = hp;

	for (int k = 1; k < size; k++)
	{
		addAfter(tp, A[k]);
		tp = tp->next;
	}
	return(hp);
}

void displayList(node_t *hp)
{
	while (hp != NULL)
	{
		printf("%c -> ", hp->data);
		hp = hp->next;
	}
	if (hp == NULL)
		printf("NULL\n");
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

node_t * search(node_t *hp, char item)
{
	if(hp->data!=item)
		while ((hp->next != NULL) && (hp->next->data != item))
			hp = hp->next;

	return hp;
}
