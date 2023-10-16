#include <stdio.h>
#include <stdlib.h>
//linklist ex for knowledgable 
typedef struct Link
{
    struct Link *next;
    int value;
} Link;
// int sll_length(Link *sll);
int sll_indexOf(Link *sll, int value);
int main()
{
    Link *head;
    Link *temp;
    head = temp;
    int n = 5;
    int i = 0;
    int tab[5] = {1, 2, 3, 4, 5};
    for (i = 0; i < n - 1; i++)
    {
        temp = malloc(sizeof(Link));
        temp->value = tab[i];
        printf("%d\t", temp->value);
        temp = temp->next;
    }
    temp = malloc(sizeof(Link));
    temp->value = tab[n - 1];
    temp->next = NULL;
    printf("%d\t", temp->value);
    free(head);
    head = NULL;
    return 0;
}
Link *creat(int n)
{
}
int sll_indexOf(Link *sll, int value)
{
    Link *temp = sll;
    int index = 1;
    if (sll == NULL)
    {
        printf("there is no element in this linklist.\n");
        return -1;
    }
    else
    {
        while (temp->value != value && temp->next != NULL)
        {
            temp = temp->next;
            index++;
        }
        if (temp->value != value)
        {
            index = -1;
        }
    }
    return index;
}
int sll_indexOf_recur(Link *sll, int value)
{
    Link *temp = sll;

    if (sll == NULL)
    {
        printf("there is no element in this linklist.\n");
        return -1;
    }

    if (temp->value == value)
    {
        return 1;
    }
    else
    {
        if (temp->next == NULL)
        {
            return -1;
        }
        else
        {
            temp = temp->next;
            int foundIndex = sll_indexOf_recur(temp, value);
            if (foundIndex == -1)
            {
                return -1;
            }
            return foundIndex + 1;
        }
    }
}
int sll_nOccs_recur(Link *sll, int val)
{
    Link *temp = sll;
    int count;
    if (sll == NULL)
    {
        printf("there is no element in this linklist.\n");
        return 0;
    }
    if (temp->next == NULL)
    {
        if (temp->value == val)
            return 1;
        else
            return 0;
    }
    else
    {
        temp = temp->next;
        if (temp->value == val)
            return 1 + sll_nOccs_recur(temp, val);
        else
            return 0 + sll_nOccs_recur(temp, val);
    }
}
int sll_sum(Link *sll)
{
    Link *temp = sll;
    if (sll == NULL)
    {
        printf("there is no element in this linklist.\n");
        return 0;
    }
    if (temp->next == NULL)
    {
        return temp->value;
    }
    else
    {
        int v = temp->value;
        temp = temp->next;
        return sll_sum(temp) + v;
    }
}
int sll_product(Link *sll)
{
    Link *temp = sll;
    if (sll == NULL)
    {
        printf("there is no element in this linklist.\n");
        return 1;
    }
    if (temp->next == NULL)
    {
        return temp->value;
    }
    else
    {
        int v = temp->value;
        temp = temp->next;
        return sll_product(temp) * v;
    }
}
int sll_increasing(Link *sll)
{
    Link *temp = sll;
    Link *temp2;
    int check = 1;
    if (sll == NULL)
    {
        printf("there is no element in this linklist.\n");
        return 1;
    }
    do
    {
        temp2 = temp->next;
        if (temp2->value <= temp->value)
        {
            check = 0;
            break;
        }
        temp = temp->next;
    } while (temp->next != NULL);
    return check;
}
void log_sll_reverse(Link *sll)
{
    // Link *temp = sll;
    if (sll == NULL)
    {
        // printf("there is no element in this linklist.\n");
        return NULL;
    }

    log_sll_reverse(sll->next); // recursively call log_reverse
    _log(sll->value);
}
Link *sll_reverse(Link *sll)
{
    Link *prev = NULL;
    Link *current = sll;
    Link *nextdata = NULL;

    while (current != NULL)
    {
        nextdata = current->next;
        current->next = prev;
        prev = current;
        current = nextdata;
    }
    return prev;
}
