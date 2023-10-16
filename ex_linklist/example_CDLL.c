#include <stdio.h>
#include <stdlib.h>
// Implementation of a Circular Doubly Linked List
// use the base of code en example, but call by pointer not value!
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
//  Creating a node of a Circular Doubly Linked List
void circularDoubly(struct node **ptail, int data);
// Inserting a node in an empty list
void CDLL_addToEmpty(struct node **ptail, int data);
// Inserting a node at the beginning of the CDLL
void CDLL_addAtBeg(struct node **ptail, int data);
void CDLL_create(struct node **ptail, int size);
void CDLL_reverse(struct node **ptail);
// Inserting a node at the end of the CDLL
// void CDLL_addAtEnd(struct node **ptail, int data);
// Inserting a node in between nodes of the CDLL
void CDLL_addAfterPos(struct node **ptail, int data, int pos);
// Deleting the first node of the CDLL
// struct node *CDLL_delFirst(struct node *tail);
// Deleting the last node of the CDLL
// struct node *CDLL_delLast(struct node *tail);
// Deleting an intermediate node of the CDLL
void CDLL_delInter(struct node **ptail, int pos);
// Printing a Doubly linked List
void print_CDLL(struct node *head);
int main()
{
    printf("\n");
    int data = 34;
    int size = 5;
    int tab[] = {1, 2, 3, 4, 5, 6};
    struct node *tail;
    // circularDoubly(&tail, tab[0]);
    // CDLL_addToEmpty(&tail, tab[0]);
    //  CDLL_addAtBeg(&tail, tab[1]);
    CDLL_create(&tail, size);
    print_CDLL(tail);
    CDLL_reverse(&tail);
    print_CDLL(tail);
   /*CDLL_addAfterPos(&tail, data, 3);
    print_CDLL(tail);
    CDLL_delInter(&tail, 2);
    print_CDLL(tail);*/ 

    /*struct node *tail = NULL;
     tail = CDLL_delFirst(tail);
     tail = CDLL_addToEmpty(45);
     tail = CDLL_addAtBeg(tail, 34);
     tail = CDLL_addAtEnd(tail, 555);
     tail = CDLL_addAtEnd(tail, 444);
     tail = CDLL_addAtEnd(tail, 666);
     print_CDLL(tail);
     tail = CDLL_addAfterPos(tail, 467, 3);
     print_CDLL(tail);
     tail = CDLL_addAfterPos(tail, 745, 6);
     print_CDLL(tail);
     tail = CDLL_delFirst(tail);
     print_CDLL(tail);
     tail = CDLL_delLast(tail);
     print_CDLL(tail);
     tail = CDLL_delInter(tail, 3);
     print_CDLL(tail);
     tail = CDLL_delInter(tail, 4);
     print_CDLL(tail);*/

    printf("\n\n\n");
    return 0;
}
void print_CDLL(struct node *head)
{
    if (head == NULL)
    {
        printf("No element in the List.\n");
        return;
    }
    struct node *i = head->next;
    printf("the element in the CDLL are:");
    do
    {
        printf("\t%d", i->data);
        i = i->next;
    } while (i != head->next);
    printf("\n");
}
void circularDoubly(struct node **ptail, int data)
{ // Creating a node of a Circular Doubly Linked List
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = temp;
    temp->prev = temp;
    *ptail = temp;
}
void CDLL_addToEmpty(struct node **ptail, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = temp;
    temp->prev = temp;
    *ptail = temp;
}
void CDLL_addAtBeg(struct node **ptail, int data)
{
    struct node *newP, *temp;
    CDLL_addToEmpty(&newP, data);
    if (*ptail == NULL)
        *ptail = newP;
    else
    {
        temp = (*ptail)->next;
        (*ptail)->next = newP;
        newP->prev = *ptail;
        newP->next = temp;
        temp->prev = newP;
    }
}
void CDLL_create(struct node **ptail, int size)
{
    int tab[] = {1, 2, 3, 4, 5, 6};
    *ptail = NULL;
    CDLL_addToEmpty(ptail, tab[0]);
    if (size > 1)
    {
        for (int i = 1; i < size; i++)
        {
            CDLL_addAtBeg(ptail, tab[i]);
        }
    }
}
void CDLL_reverse(struct node **ptail)
{
    struct node *current;
    struct node *temp;
    current = *ptail;
    do
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        //printf("current%dtemp%d", current->data,temp->data);
        current = current->prev;
    }while (current != *ptail);
    *ptail = current->prev;
}
void CDLL_addAfterPos(struct node **ptail, int data, int pos)
{
    struct node *newP, *temp;
    CDLL_addToEmpty(&newP, data);
    if (*ptail == NULL)
        *ptail = newP;
    while (pos > 1) // arrive to position
    {
        temp = temp->next;
        pos--;
    }
    newP->prev = temp;
    newP->next = temp->next;
    temp->next->prev = newP;
    temp->next = newP;
    if (temp == *ptail)
        *ptail = (*ptail)->next;
}
void CDLL_delInter(struct node **ptail, int pos)
{
    struct node *temp;
    temp = (*ptail)->next;
    while (pos > 1)
    {
        temp = temp->next;
        pos--;
    }
    struct node *temp2 = temp->prev;
    temp2->next = temp->next;
    temp->next->prev = temp2;
    free(temp);
    if (temp == *ptail)
        *ptail = temp2;
}