#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
struct node
{
    int data;
    struct node *link;
};
void push(int data, struct node **top); // push function/add
int pop(struct node **top);
int isEmpty(struct node *top);
int tos(struct node *top);
int peek(struct node *top);
void print(struct node *top);
void create_stack(struct node **top, int n);
void reverse_stack(struct node **top, int n);

int main()
{
    struct node *top = NULL;
    int n = 5;
    create_stack(&top, n);
    printf("\n- the original stack is:\n");
    print(top);
    reverse_stack(&top, n);
    printf("\n- the reverse stack is:\n");
    print(top);
    free(top);
    return 0;
}
void push(int data, struct node **top)
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

    newNode->link = *top;
    *top = newNode;
}
void create_stack(struct node **top, int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        int data = rand() % 100;
        push(data, top);
    }
}
// POP function
int pop(struct node **top)
{
    struct node *temp;
    temp = *top;
    if (isEmpty(temp))
    {
        printf("Stack overflow!");
        exit(1);
    }
    int val = temp->data;
    *top = (*top)->link;
    free(temp);
    temp = NULL;
    return val;
}
void reverse_stack(struct node **top, int n)
{
    struct node *top1 = NULL; // temporary stack1
    // repeat n times
    int popdata;
    for (int i = 0; i < n; i++)
    {
        popdata = pop(top);
        push(popdata, &top1);//top will be empty
    }
    *top = top1;//
}
// isempty fucntion
int isEmpty(struct node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// tos function
int tos(struct node *top)
{
    if (isEmpty(top))
    {
        printf("Stack overflow!");
        exit(1);
    }

    return top->data;
}
// peek() function
int peek(struct node *top)
{
    if (isEmpty(top))
    {
        printf("Stack Underflow.");
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
