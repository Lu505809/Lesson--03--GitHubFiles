#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
char **split_str(char *str, char separator)
{
    if (str == NULL)
    {
        return NULL;
    }
    int num_s = 1;
    int i=0, j=0, k=0;
    // count the number of separator
    for (i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] == separator)
        {
            num_s++;
        }
    }
    // printf("%d", num_s);
    char **strings;
    strings = (char **)malloc(num_s * sizeof(char *)); // worst case is every char is separator
    if (strings == NULL)
    {
        fprintf(stderr, "Memory allocation failed1\n");
        return NULL;
    }
    for (i = 0, j = 0; str[i] != '\0'; ++i) // i for str loop, j for new string array loo
    {
        if (str[i] == separator)
        {
            strings[j] = (char *)malloc((i - k + 1) * sizeof(char)); // define size of the new string will be 50;

            if (strings[j] == NULL)
            {
                fprintf(stderr, "Memory allocation failed2\n");
                return NULL;
            }
            strncpy(strings[j], str + k, i - k); // copy the value from k, and the size is(i-k)
            strings[j][i - k] = '\0';            // Null-terminate the part
            k = i + 1;                           // Update start index for the next string
            j++;                                 // Move j to next string
        }
        // check the str arrive to the last position,we need to put the end to string,
        if (str[i + 1] == '\0')
        {
            strings[j] = (char *)malloc((i - k + 2) * sizeof(char)); // define size of the new string will be 50;
            if (strings[j] == NULL)
            {
                fprintf(stderr, "Memory allocation failed\n");
                return NULL;
            }
            strncpy(strings[j], str + k, i - k + 1); // copy the value from k, and the size is(i-k)
            strings[j][i - k + 1] = '\0';            // Null-terminate the part
        }
    }
    return strings;
}

int main()
{
    char *str1 = "howzarezyou";
    char **newstr;
    newstr = split_str(str1, 'z');
    int i = 1;
    while (newstr != NULL)
    {
        printf("string%d:%s \n", i, *newstr);
        newstr++;
        i++;
    }
    return 0;
}

/*
typedef struct Position
{
    float x;
    float y;
} Position;
Position *average_position(Position *positions, int n_values)
{
    Position *average;
    average = (Position *)malloc(sizeof(Position));
    float sum_x = 0;
    float sum_y = 0;
    for (int i = 0; i < n_values; i++)
    {
        sum_x = sum_x + positions[i].x;
        sum_y = sum_y + positions[i].y;
    }
    average->x = (sum_x / n_values);
    average->y = (sum_y / n_values);
    return average;
}
int main()
{
    Position tab[2];
    tab[0].x = 1.1;
    tab[0].y = 2.2;
    tab[1].x = 1.5;
    tab[1].y = 3.5;
    Position *average;
    average = average_position(tab, 2);
    printf("x_average is %f, y_average is %f", average->x, average->y);
    free(average);
    return 0;
}*/

// string
/*int are_string_equals(char *str1, char *str2);
int main()
{
    char *str1 = "hello chicken";
    char str2[] = "hello hooman";
    // int r1, r2;
    // r1 = strlen(str1); // get length of string
    // r2 = strcmp(str1, str2);
    // printf("the str1 length is %d\n, the differences of 2strint is%d");
    // printf("%s", strcat(str1, str2));
    while ((*str1) != '\0')
    {
        printf("%c\t", (*str1));
        str1++;
    }
    printf("\n");
    printf("%d", are_string_equals(str1, str2));
    return 0;
}
int are_string_equals(char *str1, char *str2)
{
    while ((*str1) != '\0' && (*str2) != '\0')
    {
        if ((*str1) != (*str2))
        {
            return 0;
        }
        str1++;
        str2++;
    }
    if ((*str1) == '\0' && (*str2) == '\0')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}*/
