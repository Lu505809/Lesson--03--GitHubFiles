#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* This data is not always stored in a structure, but it is sometimes for ease of use */
struct Node
{
    int data;
    struct Node *next;
};
void deletelast(struct Node **pheadNode);
void creat_list(struct Node **pheadNode, int n);
void print_list(struct Node *headNode);
int search_list(struct Node **pheadNode, int element);
void delete_list(struct Node **pheadNode, int pos);
int main()
{
   struct Node *head = NULL;
    srand(time(NULL)); 
    int n = 5;
    creat_list(&head, n);
    print_list(head);
    //deletelast(&head);
    //print_list(head);
    //find the element
        int element;
    printf("Enter the element to search for: ");
    scanf("%d", &element);
    int index = search_list(&head, element);
    if(index == -1)
        printf("Element not found!");
    else if(index == -2)
        printf("Linked List is empty!");
    else
        printf("Element %d is at index %d", element, index);
        printf("\n");
  //delete by the pos(index)
  int pos=3;
  delete_list(&head,pos);
   print_list(head);

    return 0;
}
void creat_list(struct Node **pheadNode, int n)
{
    struct Node *head, *node, *end;
    head = malloc(sizeof(*head)); //  head only have pointer, no value
    int tab[]={34,56,764,24,94};
    end = head;
    for (int i = 0; i < n; i++)
    {
        node = malloc(sizeof(*node));
        node->data=tab[i];
        end->next = node;
        end = node;
    }
     end->next = NULL;
     *pheadNode = head;
      if (NULL == pheadNode)
    {
        return;
    }
}
void print_list(struct Node *head)
{
     printf("the values are:");
    while (head->next != NULL)
    {
        head = head->next;
        printf("%d\t", head->data);
    }
     printf("\n");
}
void deletelast(struct Node **pheadNode)
{
    struct Node *t, *temp;
    t=*pheadNode;
    temp=t;
     if (t == NULL)
    {
        printf("the node is not exist.\n");
    }
   while (t->next!= NULL)
    { 
        temp=t;
        t=t->next;
    }
        temp->next=NULL;
         free(t);
    
}
void delete_list(struct Node **pheadNode, int pos)
 {
    struct Node *temp1,*temp2;
    temp1 = *pheadNode;
    int i = 0;
    while (i < pos+1 && temp1 != NULL)
    {
        temp2=temp1;
        temp1 = temp1->next;
        i++;
    }
    if (temp1 != NULL) //arrive to delete position
    {
       temp2->next=temp1->next;
       free(temp1);
    }
    else
        printf("the node is not exist.\n");
}
int search_list(struct Node **pheadNode, int element)
{
    struct Node *temp1;
    temp1 = *pheadNode;
    int index = 0;

    if(temp1 == NULL)
        return -2;
    do {
        if(temp1->data == element)
            return (index-1);
        temp1 = temp1->next;
        index++;
    }   while(temp1 != NULL);
    return -1;
}