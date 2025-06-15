#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList_struct3.h"

int main(void)
{
    LType n;

    FILE *bin = fopen("vegAndFruit.bin","rb");

    while (fread(&n, sizeof(LType), 1, bin) == 1)
    {
        printf("%d %s %f\n", n.ID, n.name, n.price);
    }
}