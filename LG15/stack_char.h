//
// Stack Implementation, CTIS 152
//
#include <stdio.h>
#define STACK_SIZE  100

typedef  char  SType;

SType  STACK_EMPTY = '\0';

typedef struct
{	int	top;
	SType data[STACK_SIZE];
} stackk_t;

//Functions in this file...
void initializeS (stackk_t *s);
int isEmptyS (stackk_t *s);
int isFullS (stackk_t *s);
void push (stackk_t *s, SType item);
SType pop (stackk_t *s);

//------------------------------------------------------------------------------

void initializeS (stackk_t *s)
{
	s->top = -1;
}

//------------------------------------------------------------------------------

int isEmptyS (stackk_t *s)
{
	if (s->top == -1)
		return 1;
	return 0;
}

//------------------------------------------------------------------------------

int isFullS (stackk_t *s)
{
	if (s->top == STACK_SIZE - 1)
		return 1;
	return 0;
}

//------------------------------------------------------------------------------

void push (stackk_t *s, SType item)
{
	if (isFullS(s))
		printf("Error: Stack is full!\n");
	else
	{
		(s->top)++;
		s->data[s->top] = item;
	}
}

//------------------------------------------------------------------------------

SType pop (stackk_t *s)
{
	SType item;
	if (isEmptyS(s))
	{	printf("Error: Stack is empty!\n");
		item = STACK_EMPTY;	
	}
	else
	{	item = s->data[s->top];
		(s->top)--;
	}		    	
	return (item);
}

//-------------------------------------------------------------------------------

int countStack(stackk_t *s)
{
	int count = 0;

	stackk_t a; 
	initializeS(&a);
	a = *s; 

	while(!isEmptyS(&a))
	{
		pop(&a);
		count++;
	}
	return(count);
}
//-------------------------------------------------------------------------------

void displayStack(stackk_t *s, int size)
{
	while(size - 1 >= 0)
	{
		printf("%d\n", s->data[size - 1]);
		size--;
	}
}

//-------------------------------------------------------------------------------



//------------------------------------------------------------------------------

void remMaxStack(stackk_t *s)
{
	int max = s->data[0]; 	
	int size = countStack(s), pos;

	for (int i = 0; i < size; i++)
		if (s->data[i] > max)
		{
			max = s->data[i];
			pos = i;
		}
		
	int index = size - 1; 
	stackk_t temp;
	initializeS(&temp);

	while (index >= pos)
	{
		push(&temp, pop(s));
		index--;
	}

	(temp.top)--; 
	while (!isEmptyS(&temp))
		push(s, pop(&temp));
	
}

void sendNthToEnd(stackk_t *s, int n)
{
	int index = countStack(s) - 1; 

	stackk_t temp, temp2;
	initializeS(&temp);
	initializeS(&temp2);

	while (index >= n - 1)
	{
		push(&temp, pop(s));
		index--;
	}

	while(!isEmptyS(s))
		push(&temp2, pop(s));
	push(s, pop(&temp)); 
	while(!isEmptyS(&temp2))
		push(s, pop(&temp2)); 
	while(!isEmptyS(&temp))
		push(s, pop(&temp));
}