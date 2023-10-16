#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
//ex for stack reverse by value
struct node
{
    int data;
    struct node *link;
};
struct node *push(int data, struct node *top);
struct node *pop(struct node *top);
int isEmpty(struct node *top);
int Tos(struct node *top);
void print(struct node *top);
struct node *create_stack( struct node *top, int n);
struct node *reverse_stack( struct node *top, int n);
int main()
{
    struct node *top = NULL;
    struct node *top1 = NULL; // temporary stack1
    struct node *temp = NULL;
    int n=5;
    top=create_stack(top, n);
    printf("\n- the original stack is:\n");
    print(top);
    top1=reverse_stack(top,n);
    printf("\n- the reverse stack is:\n");
    print(top1);
    return 0;
}
struct node *push(int data, struct node *top)
{
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Stack overflow!");
        exit(1); // exit with faillure status
    }
    newNode->data = data;
    newNode->link = NULL;

    newNode->link = top;
    top = newNode;
    return top;
}
struct node *create_stack( struct node *top, int n)
{   srand(time(NULL));
    for(int i=0;i<n;i++)
    {int data=rand() % 100;
   top = push(data, top);
    }
    return top;
}
struct node *reverse_stack( struct node *top, int n)
{
    struct node *top1 = NULL; // temporary stack1
    struct node *temp = NULL;
    //repeat n times
    for(int i=0;i<n;i++)
    {temp = pop(top);
    top = temp->link;
    top1 = push(temp->data, top1);
    }
   return top1;
}
// Function to pop an element from the stack
struct node *pop(struct node *top)
{

    struct node *temp;
    temp = top;
    if (isEmpty(top))
    {
        printf("Stack is empty\n");
        exit(1);
    }
    temp = top;
    return temp;
}
// isEmpty() function
int isEmpty(struct node *top)
{
    if (top == NULL)
        return 1;
    else
        return 0;
}
int Tos(struct node *top)
{
    if (isEmpty(top))
    {
        printf("Stack overflow!");
        exit(1);
    }

    return top->data;
}
void print(struct node *top)
{
    struct node *temp;
    temp = top;
    if (isEmpty(top))
    {
        printf("Stack Underflow.");
        exit(1);
    }
    printf("The stack elements are: ");
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}