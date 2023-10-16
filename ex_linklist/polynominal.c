// ex plynominal

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// #include <string.h>
#include <time.h>
// #define SIZE 7
struct node
{
    int expo;
    float coeff;
    struct node *link;
};
struct node *poly_creat(struct node *head, int n);                  // creat
struct node *poly_insert(struct node *head, float coeff, int expo); // insert
void print_poly_ssll(struct node *head);                            // print after simplierfier
struct node *poly_add(struct node *head1, struct node *head2);      // add 2
struct node *poly_mult(struct node *head1, struct node *head2);     // multy 2
void print_poly_simp(struct node *head);
int main()
{ // struct node* poly_creat(struct node* head);

    struct node *head1 = NULL;
    struct node *head2 = NULL;
    // struct node *head3 = NULL; // test insert value
    struct node *head4 = NULL; // test add value
    struct node *head5 = NULL; // test mult value
    head1 = poly_creat(head1, 3);
    printf("\nThe 1st polynomial is: ");
    print_poly_ssll(head1);
    head2 = poly_creat(head2, 4);
    printf("\nThe 2nd polynomial is: ");
    print_poly_ssll(head2);
    head4 = poly_add(head1, head2);
    printf("\nThe add polynomial is: ");
    print_poly_ssll(head4);
    head5 = poly_mult(head1, head2);
    printf("\nThe multy polynomial is: ");
    print_poly_ssll(head5);
    //printf("\nThe simpliefied multy polynomial of head5 is: ");
    //print_poly_simp(head5);
    free(head1);
    free(head2);
    // free(head3);
    free(head4);
    free(head5);
    return 0;
}

struct node *poly_creat(struct node *head, int n)
{
    int i, expo;
    float coeff;
    if (n == 0)
        return NULL;
    for (i = 0; i < n; i++)
    {
        printf("Enter the expo %d: ", i);
        scanf("%d", &expo);
        printf("Enter the coeff %d: ", i);
        scanf("%f", &coeff);
        head = poly_insert(head, coeff, expo);
    }
    return head;
}
struct node *poly_insert(struct node *head, float coeff, int expo)
{
    struct node *temp;
    struct node *newp = malloc(sizeof(struct node));
    newp->coeff = coeff;
    newp->expo = expo;
    newp->link = NULL;
    if (head == NULL || expo > head->expo)
    {
        newp->link = head;
        head = newp;
    }
    else
    {
        temp = head;
        while (temp->link != NULL && temp->link->expo > expo) // arrange in descending order,
        {
            temp = temp->link;
        }
        newp->link = temp->link;
        temp->link = newp;
    }
    return head;
}
struct node *poly_add(struct node *head1, struct node *head2)
{
    struct node *ptr1 = head1;
    struct node *ptr2 = head2;
    struct node *head3 = NULL;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->expo == ptr2->expo)
        {
            head3 = poly_insert(head3, ptr1->coeff + ptr2->coeff, ptr1->expo);
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        }
        else if (ptr1->expo > ptr2->expo)
        {
            head3 = poly_insert(head3, ptr1->coeff, ptr1->expo);
            ptr1 = ptr1->link;
        }
        else if (ptr1->expo < ptr2->expo)
        {
            head3 = poly_insert(head3, ptr2->coeff, ptr2->expo);
            ptr2 = ptr2->link;
        }
    }
    while (ptr1 != NULL) // when the 2polynominal is the not the same length, we need to arrive to the end!!
    {
        head3 = poly_insert(head3, ptr1->coeff, ptr1->expo);
        ptr1 = ptr1->link;
    }
    while (ptr2 != NULL)
    {
        head3 = poly_insert(head3, ptr2->coeff, ptr2->expo);
        ptr2 = ptr2->link;
    }

    return head3;
}
struct node *poly_mult(struct node *head1, struct node *head2)
{
    printf("\n");
    struct node *ptr1 = head1;
    struct node *ptr2 = head2;
    struct node *head3 = NULL;
    // Check if first or second polynomial is NULL
    if (head1 == NULL || head2 == NULL)
    {
        printf("there is empty polynomial in the liste!\n");
        return NULL;
    }

    while (ptr2 != NULL)
    {
        while (ptr1 != NULL)
        {
            head3 = poly_insert(head3, ptr1->coeff * ptr2->coeff, ptr1->expo + ptr2->expo);
            ptr1 = ptr1->link;
        }
        ptr2 = ptr2->link;
        ptr1 = head1; // need to put the ptr1 back to head position
    }
 // Improvements: Adding the like terms (terms with same exponents) for simplification  
    struct node* ptr3 = head3;
    struct node* temp = NULL;

    while(ptr3->link != NULL)
    {
        if(ptr3->expo == ptr3->link->expo)
        {
            ptr3->coeff = ptr3->coeff + ptr3->link->coeff;
            temp = ptr3->link;
            ptr3->link = ptr3->link->link;
            free(temp);
            temp = NULL;
        }
        else
        {
            ptr3 = ptr3->link;
        }
    }
    return head3;
}
void print_poly_ssll(struct node *head)
{

    if (head == NULL)
    {
        printf("the polynominal is empty!\n ");
        return;
    }
    else
    {
        struct node *temp = head;
        while (temp != NULL)
        {
            printf("(%.1f*X^%d)", temp->coeff, temp->expo);
            temp = temp->link;
            if (temp != NULL)
                printf(" + ");
            else
                printf("\n");
        }
    }
}
void print_poly_simp(struct node *head)
{
    struct node *temp = NULL;
    struct node *ptr = head;
    while (ptr->link != NULL)
    {
        if (ptr->expo == ptr->link->expo)
        {
            ptr->coeff = ptr->coeff + ptr->link->coeff;
            temp = ptr->link;
            ptr->link = ptr->link->link;
            free(temp);
            temp = NULL;
        }
        else
        {
            ptr = ptr->link;
        }
    }
    print_poly_ssll(head);
    printf("\n");
}