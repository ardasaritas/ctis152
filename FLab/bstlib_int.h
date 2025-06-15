#include <stdio.h>
#include <stdlib.h>

typedef int BType; 

typedef struct node_b
{
    BType data; 
    struct node_b *leftchild; 
    struct node_b *rightchild;
}bnode_t;

bnode_t *getBinaryNode(BType key)
{
    bnode_t *node; 
    node = (bnode_t *)malloc(sizeof(bnode_t)); 
    node->data = key; 
    node->leftchild = NULL;
    node->rightchild = NULL;
    return(node);
}

bnode_t *insert(bnode_t *root, BType key)
{
    bnode_t *tempNode, *current, *parent;
    tempNode = getBinaryNode(key); // create a node with key
    
    if (root == NULL) // if tree is empty, create root node
        root = tempNode; 
    else
    {
        current = root; 
        while (current != NULL && current->data != key)
        {
            parent = current; // reserve the current's location
            if (key < parent->data) // if key < data, go left
            {
                current = current->leftchild; // move to current = parent's leftchild
                if (current == NULL) // if there exists no node: 
                    parent->leftchild = tempNode; 
                // else, do not overwrite, iterate one more time, go on until current == NULL
            }
            else
            {
                current = current->rightchild; // if key > data, go right
                if (current == NULL) // if there exists no node:
                    parent->rightchild = tempNode;
                // else, do not overwrite, iterate one more time, go on until current == NULL
            }
        }
    }
    return(root); // return the root 
}

bnode_t *insertRec(bnode_t *node, BType key)
{
    if (node == NULL) // simple case
        return getBinaryNode(key); 
    else if (key < node->data)
        node->leftchild = insertRec(node->leftchild, key); 
    else if (key > node->data)
        node->rightchild = insertRec(node->rightchild, key);
    return(node); 
}

bnode_t *search(bnode_t *root, BType key)
{
    bnode_t *current = root; 
    printf("Visiting elements: "); 

    while (current != NULL && current->data != key)
    {
        printf("%d ", current->data); 

        if (key < current->data)
            current = current->leftchild; 
        else    
            current = current->rightchild; 
    }
    return(current); 
}

bnode_t *minValueNode(bnode_t *node)
{
    bnode_t *current = node; 
    while (current->leftchild != NULL)
        current = current->leftchild; 
    return(current);
}

bnode_t *maxValueNode(bnode_t *node)
{
    bnode_t *current = node; 
    while (current->rightchild != NULL)
        current = current->rightchild; 
    return(current);
}

bnode_t *deleteNode(bnode_t *root, BType key)
{
    bnode_t *temp; 
    
    if (root == NULL) // If there isn't a tree, return NULL
        return root; 
    
    // If the key to be deleted is smaller than root's value,
    // then it lies in the left subtree of it
    if (key < root->data) 
        root->leftchild = deleteNode(root->leftchild, key); 
    else if (key > root->data) // else we go right
        root->rightchild = deleteNode(root->rightchild, key); 
    else // found, root->data == key
    {
        if (root->leftchild == NULL)
        {
            temp = root->rightchild; 
            free(root);
            return temp;
        }
        else if (root->rightchild == NULL)  
        {
            temp = root->leftchild;
            free(root);
            return temp;
        }
        else // get the inorder successor, copy to node, delete it
        {
            temp = minValueNode(root->rightchild);
            root->data = temp->data;
            root->rightchild = deleteNode(root->rightchild, temp->data);
        }
    }
    return root;
}

void preOrderTraversal(bnode_t *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data); //  N
        preOrderTraversal(root->leftchild); // L
        preOrderTraversal(root->rightchild); // R
    }
}

void inOrderTraversal(bnode_t *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->leftchild); // L
        printf("%d ", root->data); //  N
        inOrderTraversal(root->rightchild); // R
    }
}

void postOrderTraversal(bnode_t *root)
{
    if (root != NULL)
    {
        postOrderTraversal(root->leftchild); // L
        postOrderTraversal(root->rightchild); // R
        printf("%d ", root->data); //  N
    }
}

int totalNodes(bnode_t* root)
{
    if (root == NULL)
        return 0;
 
    int l = totalNodes(root->leftchild);
    int r = totalNodes(root->rightchild);
 
    return 1 + l + r;
}

// Function to count nodes using pre-order traversal
int countNodesPreOrder(bnode_t* root) 
{
    if (root == NULL) 
        return 0;
    else 
        return 1 + countNodesPreOrder(root->leftchild) + countNodesPreOrder(root->rightchild);
}

int countNodesInOrder(bnode_t* root) 
{
    if (root == NULL) 
        return 0;
    return countNodesInOrder(root->leftchild) + 1 + countNodesInOrder(root->rightchild);
}

int countNodesPostOrder(bnode_t* root) 
{
    if (root == NULL) 
        return 0;
    return countNodesPostOrder(root->leftchild) + countNodesPostOrder(root->rightchild) + 1;
}

int countNodesInOrderPrint(bnode_t * root) 
{
    if (root == NULL) 
    {
        return 0;
    }
    
    // Count left subtree nodes
    int leftCount = countNodesInOrderPrint(root->leftchild);

    // Print the current node value
    printf("%d ", root->data);

    // Count right subtree nodes
    int rightCount = countNodesInOrderPrint(root->rightchild);

    // Return total count (left + right + 1 for the current node)
    return leftCount + rightCount + 1;
}