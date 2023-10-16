#include <stdlib.h>
#include <stdio.h>
#include "header.h"
int main()
{
    Node *head = NULL;
    //created 1 node of linked list,
    head = (Node*)malloc(sizeof(Node));
    head->data=5;
    head->next=NULL;
    print_list(head);//test ok for the print for 1 node
    insert_at_end(&head, 10); //add 10 at the end of list
    print_list(head);
    free(head);
  return 0;  
}
void test()
{
    Node *head = NULL;
    Node **ptrNull;
    insert_at_end(&head, 10); //test if the node is empty
    print_list(head);
    insert_at_end(ptrNull, 10); //test if the ptr is no adress
    print_list(*ptrNull);
    Node *head2 = NULL;
    head2 = (Node*)malloc(sizeof(Node));
    head2->data=5;
    head2->next=NULL;
    insert_at_end(&head2, 10); //normal add to a list
}