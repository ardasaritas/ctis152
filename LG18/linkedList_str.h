#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_SIZE 15

typedef char LType;

typedef struct node_s
{
	LType data[STR_SIZE];
	struct node_s *next;
}node_t;

node_t *getNode(void)
{
	node_t *node;
	node = (node_t *)malloc(sizeof(node_t));
	node->next = NULL;
	return (node);
}

void addAfter(node_t *p, LType *item)
{
	node_t *newp;
	newp = getNode();
	newp->next = p->next;
	p->next = newp;
	strcpy(newp->data, item);
}

node_t *addBeginning(node_t *hp, LType *item)
{
	node_t *newp;
	newp = getNode();
	newp->next = hp;
	strcpy(newp->data, item);
	return(newp);
}

void displayList(node_t *hp)
{
	while (hp != NULL)
	{
		printf("%s -> ", hp->data);
		hp = hp->next;
	}
	if (hp == NULL)
		printf("NULL\n");
}

node_t *findLongest(node_t *hp)
{
	node_t *tp = hp;
	node_t *maxNode = NULL;
	
	int max = strlen(tp->data);

	tp = tp->next;

	while (tp!= NULL)
	{
 		if (max < strlen(tp->data))
		{
			max = strlen(tp->data);
			maxNode = tp;
		}
		tp = tp->next;
	}
	return(maxNode);
}
/*
node_t *findLongest(node_t *hp)
{
	node_t *max = hp;
	while (hp != NULL)
	{
		if (strlen(p->data) > strlen(max->data))
			max = hp;
		hp = hp->next
	}
}
*/
