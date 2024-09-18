/* Linked List Library */

typedef int LType;

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

//function that displays the list
void displayList (node_t *hp)
{	
	if (hp == NULL)
		printf("\nThe List is EMPTY !!!\n\n");
	else 
	{	
		while (hp != NULL)
		{	
			printf ("%d -> ",hp->data);
			hp = hp->next;
		}
		printf("NULL\n\n");
	}
}