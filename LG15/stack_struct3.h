//
// Stack Implementation, CTIS 152
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE  100

typedef struct
{
	char projectName[20];
	double profit;
	int team[3]; 
} project_t;

typedef  project_t SType;

SType  STACK_EMPTY = { "", -987654321, {0,0,0}}; 

typedef struct
{
	int	top;
	SType data[STACK_SIZE];
} stackk_t;

//Functions in this file...
void initializeS(stackk_t *s);
int isEmptyS(stackk_t *s);
int isFullS(stackk_t *s);
void push(stackk_t *s, SType item);
SType pop(stackk_t *s);

//------------------------------------------------------------------------------

void initializeS(stackk_t *s)
{
	s->top = -1;
}

//------------------------------------------------------------------------------

int isEmptyS(stackk_t *s)
{
	if (s->top == -1)
		return 1;
	return 0;
}

//------------------------------------------------------------------------------

int isFullS(stackk_t *s)
{
	if (s->top == STACK_SIZE - 1)
		return 1;
	return 0;
}

//------------------------------------------------------------------------------

void push(stackk_t *s, SType item)
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

SType pop(stackk_t *s)
{
	SType item;
	if (isEmptyS(s))
	{
		printf("Error: Stack is empty!\n");
		item = STACK_EMPTY;
	}
	else
	{
		item = s->data[s->top];
		(s->top)--;
	}
	return (item);
}
