#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* This data is not always stored in a structure, but it is sometimes for ease of use */
struct node
{
    int data;
    struct node *next;
};
struct node *CSLL_addToEmpty(int data);
struct node *CSLL_addAtEnd(struct node *tail, int data);
int CSLL_searchElement(struct node *tail, int element);
void print_CSLL(struct node *tail);
struct node *CSLL_createList(struct node *tail, int n);
struct node *CSLL_delInter(struct node *tail, int pos);
int CSLL_countElements(struct node *tail);
int main()
{

    struct node *tail;
    int n=5;
   tail = CSLL_createList(tail,n);
    print_CSLL(tail);

    int pos = 2;
    CSLL_delInter(tail, pos);
    print_CSLL(tail);
    int count;
    count = CSLL_countElements(tail);
    int element;
    printf("Enter the element to search for: ");
    scanf("%d", &element);

    int index = CSLL_searchElement(tail, element);
    if (index == count)
        printf("Element not found!");
    else if (index == -2)
        printf("Linked List is empty!");
    else
        printf("Element %d is at index %d", element, index-1);

        return 0;
}
struct node *CSLL_addToEmpty(int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = temp;
    return temp;
}
// Adding a node at the end of a CSLL
struct node *CSLL_addAtEnd(struct node *tail, int data)
{
    struct node *newP = malloc(sizeof(struct node));
    newP->data = data;
    newP->next = NULL;

    newP->next = tail->next;
    tail->next = newP;
    tail = tail->next;
    return tail;
}
struct node *CSLL_createList(struct node *tail, int n)
{
    int i, data;
    int tab[] = {34, 56, 764, 24, 94};
    if (n == 0)
        return NULL;
    tail = CSLL_addToEmpty(tab[0]);

    for (i = 1; i < n; i++)
    {
        tail = CSLL_addAtEnd(tail, tab[i]);
    }
    return tail;
}
struct node *CSLL_delInter(struct node *tail, int pos)
{
    if (tail == NULL)
        return tail;
    struct node *temp = tail->next;
    if (tail->next == tail)
    {
        free(tail);
        tail = NULL;
        return tail;
    }
    while (pos > 2)
    {
        temp = temp->next;
        pos--;
    }
    struct node *temp2 = temp->next;
    temp->next = temp2->next;

    if (temp2 == tail)
        tail = temp;
    free(temp2);
    temp2 = NULL;
    return tail;
}
int CSLL_countElements(struct node *tail)
{
    if (tail == NULL)
    {
        printf("there is no element in this linklist.\n");
        return 0;
    }
    struct node *temp = tail;
    int count = 0;
    do
    {
        count++;
        temp = temp->next;
    } while (temp != tail);
    printf("there is %d element in this linklist.\n", count);
    return count;
}
int CSLL_searchElement(struct node *tail, int element)
{
    int index = 0;
    if (tail == NULL)
    {
        index = -2;
    }
    struct node *temp = tail;
    do
    {
        if (temp->data == element)
            break;
        else
        {
            temp = temp->next;
            index++;
        }
    } while (temp != tail);
    return index;
}
void print_CSLL(struct node *tail)
{
    if (tail == NULL)
    {
        printf("No node in the List.\n");
        return;
    }
    struct node *ptr = tail->next;
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != tail->next);
    printf("\n");
}