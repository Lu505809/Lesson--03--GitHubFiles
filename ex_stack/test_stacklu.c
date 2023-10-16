#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
struct node
{
    int data;
    struct node *link;
} *top = NULL;
void push(int data); // push function/add
int pop();
int isEmpty();
void print();
int tos();
int peek();
void reverse_tack(int *stack, int *top);

int main()
{
    /*int size=5;
     int *stack = (int*) malloc(size * sizeof(int));*/

    int choice, data;
    while (choice!=5)
    {
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.print the top of stack(TOS)\n");
        printf("4.print all the elements of stack\n");
        printf("5.quit\n");
        printf("please entre your chocie:\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("entre the elment to be pushed:\n");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            data = pop();
            printf("deleted element is %d\n", data);
            break;
        case 3:
            printf("the top of stack TOS is %d\n", tos());
            break;
        case 4:
            print();
            break;
        case 5:
           break;//programm stopped no need to brak;
        default:
            printf("wrong choice.\n");
            break;
        }
    }

    return 0;
}
void push(int data)
{
    struct node *newNode;
    newNode = malloc(sizeof(newNode));
    if (newNode == NULL)
    {
        printf("Stack overflow!");
        exit(1); // exit with faillure status
    }
    newNode->data = data;
    newNode->link = NULL;

    newNode->link = top;
    top = newNode;
}
// POP function
int pop()
{
    struct node *temp;
    temp= top;
    if (isEmpty())
    {
        printf("Stack overflow!");
        exit(1);
    }
    int val = temp->data;
    top = top->link;
    free(temp);//free not working!
    temp = NULL;
    return val;
}
// isempty fucntion
int isEmpty()
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
int tos()
{
    if (isEmpty())
    {
        printf("Stack overflow!");
        exit(1);
    }

    return top->data;
}
// peek() function
int peek()
{
    if(isEmpty())
    {
        printf("Stack Underflow.");
        exit(1);
    }
    return top->data;
}
void print()
{
    struct node *temp =top;
    printf("the stack elements are:");
    while (temp != NULL) //==while(temp)
    {
        printf("%d", temp->data);
        temp = temp->link;
    }
    printf("\n");
}