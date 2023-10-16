#include <stdlib.h>
#include <stdio.h>

typedef struct Link Link;
struct Link {
    Link *next;
    int value;
};
Link *sll_reverse(Link *sll);
int sll_indexOf_recur(Link *sll, int value)
{
    Link *temp = sll;
    if (sll == NULL)
    {
        printf("there is no element in this linklist.\n");
        return -1;
    }
    if (temp->value == value)
        return 1;
    else
    {
        if (temp->next == NULL)
        {
            if (temp->value == value)
                return 1;
            else
                return -1;
        }
        else
        {
            temp = temp->next;
            int index = sll_indexOf_recur(temp, value);
            if (index == -1) return -1;
           return index  + 1;
        }
    }
}

void assertEqualsInt(int expected, int actual) {
    if (expected != actual) {
        printf("ERROR! (%d != %d)", expected, actual);
        exit(EXIT_FAILURE);
    }
}

int main() {
    Link link0, link1, link2;

    printf("Start\n");

    printf("Test1\n");
    assertEqualsInt(-1, sll_indexOf_recur(NULL, 40));

    printf("Test2\n");
    link0.value = 40;
    link0.next = NULL;
    assertEqualsInt(1, sll_indexOf_recur(&link0, 40));

    printf("Test3\n");
    link0.next = &link1;
    link1.value = 41;
    link1.next = &link2;
    link2.value = 42;  
    link2.next = NULL;
    assertEqualsInt(-1, sll_indexOf_recur(&link0, 30));

    printf("Test4\n");
    assertEqualsInt(3, sll_indexOf_recur(&link0, 42));

    printf("Test5\n");
    assertEqualsInt(1, sll_indexOf_recur(&link0, 40));

    printf("Test6\n");
    assertEqualsInt(2, sll_indexOf_recur(&link0, 41));

    printf("Success\n");
    return 0;
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