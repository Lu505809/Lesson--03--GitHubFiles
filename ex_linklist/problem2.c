#include <stdio.h>
#include <stdlib.h>
/* This data is not always stored in a structure, but it is sometimes for ease of use */
struct Node
{
    /* Sometimes a key is also stored and used in the functions */
    int data;
    struct Node *next;
    struct Node *previous;
};
void insert_at_beginning(struct Node **pheadNode, int value);
void insert_at_end(struct Node **pheadNode, int value);
void print_list(struct Node *headNode);
void print_list_backwards(struct Node *headNode);
void free_list(struct Node *headNode);
void creat_list(struct Node **pheadNode, int n);
void change_list(struct Node **pheadNode, int pos);
void delete_list(struct Node **pheadNode, int pos);
void insert_at_pos(struct Node **pheadNode, int value, int pos);
int search_list(struct Node **pheadNode, int element);
void sort_list(struct Node **pheadNode);
void trans_list(struct Node **pheadNode);
int main(void)
{
    /* Sometimes in a doubly linked list the last node is also stored */
    struct Node *head = NULL;
    int size = 5;
    creat_list(&head, size);
    print_list(head);
    int element;
    printf("Enter the element to search for: ");
    scanf("%d", &element);
    // search element
    int index = search_list(&head, element);
    if (index == -1)
        printf("Element not found!");
    else if (index == -2)
        printf("Linked List is empty!");
    else
        printf("Element %d is at position %d", element, index + 1);
    printf("\n");

    // delete element
    int pos;
    printf("Enter the position you want to delete for: ");
    scanf("%d", &pos);
    delete_list(&head, pos);
    printf("after delete, the linklist is: \n");
    print_list(head);
    // sort element
    sort_list(&head);
    printf("after sorted, the linklist is: \n");
    print_list(head);
    // transfor the list into circular double list.
    trans_list(&head);
    
    free_list(head);
    head = NULL;
    return 0;
}
void trans_list(struct Node **pheadNode)
{
    if (*pheadNode == NULL || (*pheadNode)->next == NULL)
    {
        printf("empty list!\n");
        return;
    }
    struct Node *temp;
    temp = *pheadNode;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = *pheadNode;
    (*pheadNode)->previous = temp;
}
void sort_list(struct Node **pheadNode)
{
    if (*pheadNode == NULL || (*pheadNode)->next == NULL)
    {
        printf("empty list!\n");
        return;
    }
    int tt;
    struct Node *temp;
    struct Node *last = NULL;
    struct Node *current;
    do
    {
        tt = 0;
        current = *pheadNode;
        while (current->next != last)
        {
            if (current->data > current->next->data)
            {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                tt = 1;
            }
            current = current->next;
        }
        last = current;
    } while (tt);
}
int search_list(struct Node **pheadNode, int element)
{

    int index = 0;
    if (*pheadNode == NULL)
    {
        index = -2;
    }
    struct Node *temp;
    temp = *pheadNode;
    do
    {
        if (temp->data == element)
            break;
        else
        {
            temp = temp->next;
            index++;
        }
    } while (temp != NULL);
    return index;
}
void print_list_backwards(struct Node *headNode) // print from the end to the start!
{
    if (NULL == headNode)
    {
        return;
    }
    struct Node *i = headNode;
    while (i->next != NULL)
    {
        i = i->next; /* Move to the end of the list */
    }
    while (i != NULL)
    {
        printf("Value: %d\n", i->data);
        i = i->previous;
    }
}
void print_list(struct Node *headNode) // print from the head to the end
{
    struct Node *i;
    for (i = headNode; i != NULL; i = i->next)
    {
        printf("Value: %d\n", i->data);
    }
}
void insert_at_beginning(struct Node **pheadNode, int value)
{
    struct Node *currentNode;
    if (NULL == pheadNode)
    {
        return;
    }
    currentNode = malloc(sizeof *currentNode);
    currentNode->next = NULL;
    currentNode->previous = NULL;
    currentNode->data = value;
    if (*pheadNode == NULL)
    { /* The list is empty */
        *pheadNode = currentNode;
        return;
    }
    currentNode->next = *pheadNode;
    (*pheadNode)->previous = currentNode;
    *pheadNode = currentNode;
}
void insert_at_end(struct Node **pheadNode, int value)
{
    struct Node *currentNode;
    if (NULL == pheadNode)
    {
        return;
    }
    currentNode = malloc(sizeof *currentNode);
    struct Node *i = *pheadNode;
    currentNode->data = value;
    currentNode->next = NULL;
    currentNode->previous = NULL;
    if (*pheadNode == NULL)
    { /* The list is empty */
        *pheadNode = currentNode;
        return;
    }
    while (i->next != NULL)
    { /* Go to the end of the list */
        i = i->next;
    }
    i->next = currentNode;
    currentNode->previous = i;
}
void free_list(struct Node *node)
{
    while (node != NULL)
    {
        struct Node *next = node->next;
        free(node);
        node = next;
    }
}

void creat_list(struct Node **pheadNode, int n)
{
    struct Node *currentNode;
    struct Node *temp;
    if (NULL == pheadNode)
    {
        return;
    }
    *pheadNode = malloc(sizeof *currentNode);
    printf("please entre the 1st value:\n");
    scanf("%d", &(*pheadNode)->data);
    //(*pheadNode)->next = currentNode;
    (*pheadNode)->previous = NULL;
    temp = *pheadNode;
    for (int i = 1; i < n; i++) // creat the following value
    {
        currentNode = malloc(sizeof *currentNode);
        printf("please entre the value:\n");
        scanf("%d", &currentNode->data);
        currentNode->next = NULL;
        currentNode->previous = temp;
        temp->next = currentNode;
        temp = currentNode;
    }
    currentNode->next = NULL;
}
void change_list(struct Node **pheadNode, int pos)
{
    struct Node *temp;
    temp = *pheadNode;
    int i = 0;
    while (i < pos && temp != NULL)
    {
        temp = temp->next;
        i++;
    }
    if (temp != NULL)
    {
        printf("please entre the value you want to change:\n");
        scanf("%d", &temp->data);
    }
    else
        printf("the node is not exist.\n");
}
void delete_list(struct Node **pheadNode, int pos)
{
    struct Node *temp1, *temp2, *temp0;
    temp1 = *pheadNode;
    if (pos = 1)
    {
        *pheadNode = (*pheadNode)->next;
        free((*pheadNode)->previous);
        (*pheadNode)->previous = NULL;
    }
    else
    {
        int i = 0;
        while (i < pos - 1 && temp1 != NULL)
        {
            temp1 = temp1->next;
            i++;
        }
        if (temp1 == NULL)
        {
            temp1->previous->next = NULL;
            free(temp1);
        }
        else
        {
            if (temp1 != NULL) // arrive to delete position
            {
                temp2 = temp1->next;
                temp0 = temp1->previous;
                temp0->next = temp2;
                temp2->previous = temp0;
                free(temp1);
            }
        }
    }
}

void insert_at_pos(struct Node **pheadNode, int value, int pos)
{
    struct Node *currentNode;
    struct Node *temp1, *temp2, *temp0;
    temp1 = *pheadNode;
    if (NULL == pheadNode)
    {
        return;
    }
    int i = 0;
    while (i < pos && temp1 != NULL)
    {
        temp1 = temp1->next;
        i++;
    }
    temp2 = temp1->next;
    currentNode = malloc(sizeof *currentNode);
    currentNode->data = value;
    currentNode->next = temp2;
    currentNode->previous = temp1;
    temp1->next = currentNode;
    temp2->previous = currentNode;
}