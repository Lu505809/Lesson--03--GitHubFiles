#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// #include <string.h>
#include <time.h>
// #define SIZE 7
struct node
{
    int number;
    char name[50];
    int grade;
    struct node *link;
};
struct node *poly_creat(struct node *head, int n);              // creat
struct node *poly_delete_number(struct node *head, int number); // insert bu number
struct node *poly_insert_begin(struct node *head, int number, char name[], int grade);
void print_poly_ssll(struct node *head);                // print after simplierfier
void poly_search_number(struct node *head, int number); // search function by number
void sort_list(struct node *head);
struct node *poly_add(struct node *head1, struct node *head2); // part c, add 2 list
int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    int size = 5; // define 5 empployee in the list;
    // create the first employee list;
    head1 = poly_creat(head1, size);
    int choice, data;
    while (choice != 5)
    {
        printf("1.Inserting a new entry into the records.\n");
        printf("2.Deleting an existing entry from the records\n");
        printf("3.Displaying the records.\n");
        printf("4.Searching within the records.\n");
        printf("5.quit\n");
        printf("please entre your chocie:\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Please entre the data of employee that you want to add:\n");
            int nb, grade;
            char name[50];
            printf("Enter the employee number:");
            scanf("%d", &nb);
            printf("Enter the employee name:");
            scanf("%s", &name);
            printf("Enter the employee grade(1 to 5): ");
            scanf("%d", &grade);
            head1 = poly_insert_begin(head1, nb, name, grade);
            printf("\nthe record after insert is:\n");
            print_poly_ssll(head1);
            break;
        case 2:
            printf("\n please entre the number of employee you want to delete:\n");
            int nb2;
            scanf("%d", &nb2);
            head1 = poly_delete_number(head1, nb2);
            printf("\nthe list after delete is:\n");
            print_poly_ssll(head1);
            break;
        case 3:
            printf("\nthe employee data is:\n");
            print_poly_ssll(head1);
            break;
        case 4:
            printf("\n please entre the number of employee you want to search:\n");
            int nb3;
            scanf("%d", &nb3);
            poly_search_number(head1, nb3);
            break;
        case 5:
            break; // programm stopped no need to brak;
        default:
            printf("wrong choice.\n");
            break;
        }
    }

    // Part B,sort the employee data by grade;
    sort_list(head1);
    printf("\nthe list after sort is:\n");
    print_poly_ssll(head1);

    // Part C,combine 2 records;
    int size2 = 4;
    printf("\nwe neeed to creat a new list:\n");
    head2 = poly_creat(head2, size2); // creat the 2nd record,
    struct node *head3 = NULL;        // new record with 2 data;
    head3 = poly_add(head1, head2);
    printf("\nthe new list of the 2 list are:\n");
    print_poly_ssll(head3);

    free(head1);
    free(head2);
    free(head3);
    head1 = NULL;
    head2 = NULL;
    head3 = NULL;
    return 0;
}
struct node *poly_add(struct node *head1, struct node *head2)
{
    struct node *ptr1 = head1;
    struct node *ptr2 = head2;
    struct node *head3 = NULL;
    int nb, grade;
    char name[50];
    while (ptr1 != NULL)
    {
        nb = ptr1->number;
        grade = ptr1->grade;
        strncpy(name, ptr1->name, strlen(ptr1->name));
        head3 = poly_insert_begin(head3, nb, name, grade);
        ptr1 = ptr1->link;
    }
    while (ptr2 != NULL)
    {
        nb = ptr2->number;
        grade = ptr2->grade;
        strncpy(name, ptr2->name, strlen(ptr2->name));
        head3 = poly_insert_begin(head3, nb, name, grade);
        ptr2 = ptr2->link;
    }
    return head3;
}
void sort_list(struct node *head)
{
    if (head == NULL || head->link == NULL)
    {
        printf("empty list!\n");
        return;
    }
    int tt;
    struct node *temp;
    struct node *last = NULL;
    struct node *current;
    do
    {
        tt = 0;
        current = head;
        while (current->link != last)
        {
            if (current->grade < current->link->grade)
            {
                int temp = current->grade;
                current->grade = current->link->grade;
                current->link->grade = temp;
                tt = 1;
            }
            current = current->link;
        }
        last = current;
    } while (tt);
}
struct node *poly_creat(struct node *head, int n)
{
    int i, number, grade;
    char name[50];
    if (n == 0)
        return NULL;
    for (i = 0; i < n; i++)
    {
        printf("Enter the employee number of %d: ", i);
        scanf("%d", &number);
        printf("Enter the employee name of %d: ", i);
        scanf("%s", &name);
        printf("Enter the employee grade(1 to 5) of %d: ", i);
        scanf("%d", &grade);
        head = poly_insert_begin(head, number, name, grade);
    }
    return head;
}
struct node *poly_insert_begin(struct node *head, int number, char name[], int grade)
{
    // struct node *temp;
    struct node *newp = malloc(sizeof(struct node));
    newp->number = number;
    strncpy(newp->name, name, strlen(name));
    newp->grade = grade;
    newp->link = NULL; // add at the begining
    newp->link = head;
    head = newp;
    return head;
}
struct node *poly_delete_number(struct node *head, int number)
{
    struct node *temp;
    struct node *temp1;
    temp = head;
    temp1 = temp;
    if (temp->number != number && temp->link != NULL)
    {
        temp1 = temp;
        temp = temp->link;
    }
    if (temp->link == NULL)
    {
        if (temp->number == number)
        {
            temp1->link = NULL; // delete last node
            free(temp);
        }
        else
        {
            printf("this number is not exist!\n");
        }
        return NULL;
    }
    else
    {
        temp1->link = temp->link;
        free(temp);
    }

    return head;
}
void print_poly_ssll(struct node *head)
{

    if (head == NULL)
    {
        printf("the employ list is empty!\n ");
        return;
    }
    else
    {
        struct node *temp = head;
        while (temp != NULL)
        {
            printf("the employee's number is: %d\n", temp->number);
            printf("the name is: %s\n", temp->name);
            printf("the grade is: %d\n", temp->grade);
            printf("\n");
            temp = temp->link;
        }
    }
}
void poly_search_number(struct node *head, int number)
{
    struct node *temp;
    struct node *temp1;
    temp = head;
    if (temp->number != number && temp != NULL)
    {
        temp = temp->link;
    }
    if (temp == NULL)
    {
        printf("this employee number is not exist!\n");
    }
    else
    {
        printf("the employee's number is: %d\n", temp->number);
        printf("the employee's name is: %s\n", temp->name);
        printf("the employee's grade is: %d\n", temp->grade);
        printf("\n");
    }
}
