#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// delete the duplicates in array;
void printarray(int *array, int len);
int findmax(int *array, int size);
int sumarray(int *array, int size);
void reverseorder(int *array, int size);
void swap(int *array, int size, int pos1, int pos2);
void sortarray(int *tab, int *tab2, int size);
int deletedup(int *tab, int *tab3, int l);
int *insertFirst(int *tab, int *size, int newnb);
int *insertEnd(int *tab, int *size, int newnb);
int *insertPos(int *tab, int *size, int newnb, int pos);
int *deleteFirst(int *tab, int *size);
int *deleteEnd(int *tab, int *size);
int *deletePos(int *tab, int *size, int pos);
int main()
{
    int n;
    printf("Enter size of the array \n");
    scanf("%d", &n);
    srand(time(NULL));
    int *A = (int *)malloc(n * sizeof(int)); // dynamically allocated array
    if (A == NULL)
    {
        printf("Memory allocation failed.\n");
        return 0; // Return NULL to indicate failure
    }
    for (int i = 0; i < n-1; i++)
    {
        A[i] = rand() % 100;// get rand value of the array
    }
    A[n - 1] = A[2];//creat a duplicated value at the end
    printf("the 1st array A is:\n");
    printarray(A, n); // print the 1starray
    reverseorder(A, n);
    printf("the reverse array A is:\n");
    printarray(A, n); // print the reverse array
    int max, sum;
    max = findmax(A, n);
    sum = sumarray(A, n);
    printf("the max value of the array Ais %d\n", max);
    printf("the sum of the array A is %d\n", sum);
    int pos1 = 2, pos2 = 4;
    swap(A, n, pos1, pos2);
    printf("after change the positioin %d and %d tha array A is:\n", pos1, pos2);
    printarray(A, n); // the reverse array change the position
    /*new arry B to store the deleted duplicated array*/
    int tab3[n]; // tab3 is the new array size will be equal or smaller than l1
    int n1=n;
    int *B = (int *)malloc(n * sizeof(int)); // dynamically allocated array B
    if (B == NULL)
    {
        printf("Memory allocation failed.\n");
        return 0; // Return NULL to indicate failure
    }
    n1 = deletedup(A, B, n);
    B = (int *)realloc(B, n1 * sizeof(int));
    if (B == NULL)
    {
        printf("Memory allocation failed.\n");
        return 0; // Return NULL to indicate failure
    }
    printf("the array after delete duplicate is array B:\n");
    printarray(B, n1); // the reverse array after delete the duplicate

    /*new arry C to store the deleted duplicated array*/
    int *C = (int *)malloc(n1 * sizeof(int)); // dynamically allocated array C
    if (C == NULL)
    {
        printf("Memory allocation failed.\n");
        return 0; // Return NULL to indicate failure
    }
    sortarray(B, C, n1);
    printf("the array B after sorted is C:\n");
    printarray(C, n1); // the arry after sorted
                        /* insert at first*/
    int *D;
    int newnb = 66;
    D = insertFirst(C, &n1, newnb); // insert un nb at the begining to the array C
    printf("the array C after insert at beginging:\n");
    printarray(D, n1); // the arry after insert begining
                        /* insert at end*/
    int *E;
    E = insertEnd(D, &n1, newnb);
    printf("the array D after insert at END:\n");
    printarray(D, n1); // the arry after insert end
                        /* insert at position*/
    int *F;
    int pos3 = 3;
    // int *insertPos(int *tab, int *size, int newnb,int pos)
    F = insertPos(E, &n1, newnb, pos3);
    printf("the array E after insert at position%d is:\n", pos3);
    printarray(F, n1); // the arry after insert at position
                        // int *deletefirstposition,
    int *F1;
    F1 = deleteFirst(F, &n1);
    printf("the array F after delete begining is:\n");
    printarray(F1, n1);
    // int *delete end position,
    int *F2;
    F2 = deleteEnd(F1, &n1);
    printf("the array F1 after delete end is:\n");
    printarray(F2, n1);

    // int *delete at position,
    int *F3;
    int pos4 = 2;
    F3 = deletePos(F2, &n1, pos4);
    printf("the array F2 after delete at position%d is:\n", pos4);
    printarray(F3, n1);
    free(A);
    free(B);
    free(F3);
    A = NULL;
    B = NULL;
    F3 = NULL;
    return 0;
}
void printarray(int *array, int len)
{
    // printf("the array is:");
    for (int i = 0; i < len; i++)
    {
        printf("%d \t", *(array + i)); // or A[i]
    }
    printf("\n");
}
int findmax(int *array, int size)
{
    int max = *array;
    for (int i = 0; i < size; i++)
    {
        if (*(array + i) > max)
            max = *(array + i);
    }
    return max;
}
void reverseorder(int *array, int size)
{
    for (int i = 0; i < (size / 2); i++)
    {
        int temp;
        temp = *(array + i);
        *(array + i) = *(array + size - 1 - i);
        *(array + size - 1 - i) = temp;
    }
}
int sumarray(int *array, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + *(array + i);
    }
    return sum;
}
void swap(int *array, int size, int pos1, int pos2)
{
    int temp;
    temp = *(array + pos1);
    *(array + pos1) = *(array + pos2);
    *(array + pos2) = temp;
}
int deletedup(int *tab, int *tab3, int l) // n as new array size;
{
    int n = 0;
    for (int i = 0; i < l; i++)
    {
        int duplicate = 0;
        for (int j = 0; j < n; j++)
        {
            if (*(tab + i) == *(tab3 + j))
            {
                duplicate = 1;
                break;
            }
        }
        if (!duplicate)
        {
            *(tab3 + n) = *(tab + i);
            n++;
        }
    }
    return n;
}
void sortarray(int *tab, int *tab2, int size)
{
    int temp;
    for (int i = 0; i < 10; i++)
    {
        *(tab2 + i) = *(tab + i);
        for (int j = i; j < size; j++)
        {
            if (*(tab2 + i) > *(tab + j))
            {
                temp = *(tab2 + i);
                *(tab2 + i) = *(tab + j);
                *(tab + j) = temp;
            }
        }
    }
}
int *insertFirst(int *tab, int *size, int newnb)
{
    *size = *size + 1;
    int *newtab = (int *)realloc(tab, (*size) * sizeof(int));
    if (newtab == NULL)
    {
        printf("Memory reallocation failed.\n");
        free(tab);   // Free the original array
        return NULL; // Exit with an error code
    }
    for (int i = *size - 1; i > 0; i--)
    {
        *(newtab + i) = *(newtab + i - 1); // only change the values
    }
    *newtab = newnb;
    return newtab;
}
int *insertEnd(int *tab, int *size, int newnb)
{
    *size = *size + 1;
    int *newtab = (int *)realloc(tab, (*size) * sizeof(int));
    if (newtab == NULL)
    {
        printf("Memory reallocation failed.\n");
        free(tab);   // Free the original array
        return NULL; // Exit with an error code
    }
    *(newtab + *size - 1) = newnb;
    return newtab;
}
int *insertPos(int *tab, int *size, int newnb, int pos)
{
    *size = *size + 1;
    int *newtab = (int *)realloc(tab, (*size) * sizeof(int));
    if (newtab == NULL)
    {
        printf("Memory reallocation failed.\n");
        free(tab);   // Free the original array
        return NULL; // Exit with an error code
    }
    for (int i = *size - 1; i > pos; i--)
    {

        *(newtab + i) = *(newtab + i - 1); // only change the values
    }
    *(newtab + pos) = newnb;
    return newtab;
}
int *deleteFirst(int *tab, int *size)
{
    *size = *size - 1;
    int temp = tab[*size];
    int *newtab = (int *)realloc(tab, (*size) * sizeof(int));
    if (newtab == NULL)
    {
        printf("Memory reallocation failed.\n");
        free(tab);   // Free the original array
        return NULL; // Exit with an error code
    }
    for (int i = 0; i < *size; i++)
    {
        *(newtab + i) = *(tab + i + 1); // only change the values
    }
    *(newtab + *size - 1) = temp;
    return newtab;
}
int *deleteEnd(int *tab, int *size)
{
    *size = *size - 1;
    int *newtab = (int *)realloc(tab, (*size) * sizeof(int));
    if (newtab == NULL)
    {
        printf("Memory reallocation failed.\n");
        free(tab);   // Free the original array
        return NULL; // Exit with an error code
    }
    return newtab;
}
int *deletePos(int *tab, int *size, int pos)
{
    *size = *size - 1;
    int temp = tab[*size];
    int *newtab = (int *)realloc(tab, (*size) * sizeof(int));
    if (newtab == NULL)
    {
        printf("Memory reallocation failed.\n");
        free(tab);   // Free the original array
        return NULL; // Exit with an error code
    }
    for (int i = pos; i < *size; i++)
    {
        *(newtab + i) = *(newtab + i + 1); // only change the values
    }
    *(newtab + *size - 1) = temp;
    return newtab;
}