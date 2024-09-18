#include <stdio.h>
#include <stdlib.h>
#include "bstlib_int.h"

int main(void)
{
    bnode_t *root = getBinaryNode(40); 
    insertRec(root, 25);
    insertRec(root, 20);
    insertRec(root, 30); 
    insertRec(root, 10);
    insertRec(root, 35);
    insertRec(root, 15); 
    insertRec(root, 70);
    insertRec(root, 50);
    insertRec(root, 60); 
    

    
    root = deleteNode(root, 25); 

    inOrderTraversal(root); 
    printf("\n%d \n", countNodesPreOrder(root)); 
    printf("%d \n", countNodesInOrderPrint(root)); 
    printf("%d \n", countNodesPostOrder(root)); 
    return 0; 
}
