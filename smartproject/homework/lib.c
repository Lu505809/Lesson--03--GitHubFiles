#include "header.h"
#include <stdio.h>
#include <stdlib.h>
void insert_at_end(struct Node **pheadNode, int value)
{
    Node *currentNode;
    if (NULL == pheadNode)
    {
        printf("the link list is not exist.\n"); // pointer is null, no adress
        return;
    }
    currentNode = malloc(sizeof *currentNode);
    Node *i = *pheadNode;
    currentNode->data = value;
    currentNode->next = NULL;
    if (*pheadNode == NULL) // ptr arrive to the last position!
    {                       /* The list is empty */
        *pheadNode = currentNode;
        return;
    }
    while (i->next != NULL)
    { /* Go to the end of the list */
        i = i->next;
    }
    i->next = currentNode;
}
void print_list(struct Node *headNode) // print from the head to the end
{
    struct Node *i;
    for (i = headNode; i != NULL; i = i->next)
    {
        printf("Value: %d\n", i->data);
    }
}
