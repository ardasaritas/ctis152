/* Reversal of a linked list using recursion */
#include <stdio.h>
#include <stdlib.h>
#include "linkedList_int.h"

// divide the list by first and rest, call recursive on rest, 
// each time reverse the link between two nodes
node_t * recReverse(node_t *hp) 
{
    if (hp == NULL || hp->next == NULL) // list does not exist or only has one node
        return(hp);

    node_t *rest = recReverse(hp->next); // recursive call on rest

    hp->next->next = hp; 
    hp->next = NULL;

    return (rest);
}

int main (void)
{
    node_t *hp = NULL;
    hp = addBeginning(hp, 1);

    node_t *current = hp;

    for (int r = 0; r < 4; r++) // Implement a hp -> 1 -> 2 -> 3 -> 4 -> 5 -> NULL ll for convention
    {
        addAfter(current, r + 2);
        current = current->next;
    }

    displayList(hp); // Initial List

    hp = recReverse(hp);

    displayList(hp); // Reversed List

    return(0);
}