//
// Stack Implementation, CTIS 152
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STR_SIZE 50
#define STACK_SIZE  10

typedef  char  SType;

SType  STACK_EMPTY[STR_SIZE] = "";

typedef struct
{
	int	top;
	SType data[STACK_SIZE][STR_SIZE];
} stackk_t;

//Functions in this file...
void initializeS(stackk_t *s);
int isEmptyS(stackk_t *s);
int isFullS(stackk_t *s);
void push(stackk_t *s, SType *item);
SType *pop(stackk_t *s);

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

void push(stackk_t *s, SType *item)
{
	if (isFullS(s))
		printf("Error: Stack is full!\n");
	else
	{
		(s->top)++;
		strcpy(s->data[s->top], item);
	}
}

//------------------------------------------------------------------------------

SType *pop(stackk_t *s)
{
	SType *item = (SType *)malloc(sizeof(SType) * STR_SIZE);
	
	if (isEmptyS(s))
	{
		printf("Error: Stack is empty!\n");
		strcpy(item, STACK_EMPTY);
	}
	else
	{
		strcpy(item, s->data[s->top]);
		(s->top)--;
	}
	return (item);
}
