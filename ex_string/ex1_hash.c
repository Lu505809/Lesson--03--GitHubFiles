#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
typedef struct Entry
{
    char *key;
    float value;
    struct Entry *next;
} Entry;
Entry *add_entry_to_the_end(Entry *head, char *key, float value);
Entry *get_value_by_key(Entry *head, char *key_to_search);
void print_list(Entry *head);
int simple_hash(char *key, int hashmap_size);
Entry *get_hashmap_entry(Entry *hashmap, int array_size, char *key_to_search);
Entry *new_hash_map(int size);
void add_entry_to_hashmap(Entry *hashmap, int array_size, char *key, int value);
int main()
{ // test function by hash

    int hashmap_size = 9;
    Entry *hashmap = new_hash_map(hashmap_size);

    add_entry_to_hashmap(hashmap, hashmap_size, "age", 22);
    add_entry_to_hashmap(hashmap, hashmap_size, "name", 33); // should collide
    add_entry_to_hashmap(hashmap, hashmap_size, "city", 44); // should collide

    Entry *result = get_hashmap_entry(hashmap, hashmap_size, "name");
    printf("entry %p, key: %s, value %d \n", result, result->key, result->value);
    // test function by loop/linklist
    /*Entry *Node1, *Node2;
    Node1 = (Entry *)malloc(sizeof(Entry));
    Node2 = (Entry *)malloc(sizeof(Entry));

    Node1->key = "appel";
    Node1->value = 1.5;
    Node1->next = Node2;

    Node2->key = "banana";
    Node2->value = 1.8;
    Node2->next = NULL;
    int size;
    size = 10;
    int hash_key1;
    hash_key1 = simple_hash(Node2->key, size);
    printf("the hash value of key1 is: %d\n", hash_key1);
    // Node1 = add_entry_to_the_end(Node1, "orange", 4.5);

    /*Entry *search = NULL;
    search = get_value_by_key(Node1, "banana");
    if (search == NULL)
    {
        printf("no value find\n");
    }
    else
    {
        printf("the value is: %g\n", search->value);
    }
    print_list(Node1);
    free(Node1);
    free(Node2);*/
    return 0;
}
Entry *add_entry_to_the_end(Entry *head, char *key, float value)
{
    Entry *current;
    current = (Entry *)malloc(sizeof(Entry));
    Entry *i = head;
    current->key = key;
    // strncpy(current->key, key, strlen(key)+1);//copy the key valye to current key
    current->value = value;
    current->next = NULL;

    if (head == NULL)
    { /* The list is empty */
        head = current;
    }
    while (i->next != NULL)
    { /* Go to the end of the list */
        i = i->next;
    }
    i->next = current;
    return head;
}
void print_list(Entry *head) // print from the head to the end
{
    Entry *i;
    for (i = head; i != NULL; i = i->next)
    {
        printf("the key is: %s\t", i->key);
        printf("the value is: %g\n", i->value);
    }
}
Entry *get_value_by_key(Entry *head, char *key_to_search)
{
    Entry *i;
    i = head;
    if (!head) // if tree is NULL
    {
        printf("empty list\n");
        return NULL;
    }
    while (i != NULL)
    {
        if (strcmp(i->key, key_to_search) == 0) // equal value
            return i;
        else
            i = i->next;
    }
    return i;
}
// now we start the hash function
int simple_hash(char *key, int hashmap_size)
{
    int hash_value = 0;
    while (*key != '\0')
    {
        hash_value += (int)(*key);
        key++;
    }
    // printf("the total valus is%d\n", hash_value);
    hash_value = hash_value % hashmap_size;
    return hash_value;
}

Entry *new_hash_map(int size)
{
    /*Entry *hashmap;
    hashmap = (Entry *)malloc(size * sizeof(Entry));
    if (hashmap == NULL)
    {
        printf("Memory allocation failed.\n");
        return NULL; // Exit with an error code}
    }

    return hashmap;*/
    return (Entry *)calloc(sizeof(Entry), size);
}
// need to add the collison
void add_entry_to_hashmap(Entry *hashmap, int array_size, char *key, int value)
{
    int hash = simple_hash(key, array_size);
    if (hashmap[hash].key == NULL)
    {
        // Allocate memory for the key and copy it
        // hashmap[hash].key = (char *)malloc(strlen(key) + 1);
        // strcpy(hashmap[hash].key, key);--pointer to pinter, no need strcpy
        hashmap[hash].key = key;
        hashmap[hash].value = value;
        hashmap[hash].next = NULL;
    }
    else
    {
        printf("Collision detected for key: %s\n", key);
        // else we need to loop on all collision entry to add at the end
        Entry *iterator = &hashmap[hash];
        while (iterator->next != NULL)
        {
            iterator = iterator->next;
        }
        Entry *new_entry = (Entry *)calloc(sizeof(Entry), 1);
        iterator->next = new_entry;
        new_entry->key = key;
        new_entry->value = value;
        new_entry->next = NULL;
    }
}
// need to add the collison
Entry *get_hashmap_entry(Entry *hashmap, int array_size, char *key_to_search)
{
    int hash = simple_hash(key_to_search, array_size);
    if (hashmap[hash].next == NULL)
    { // no collision
        return &hashmap[hash];
    }

    Entry *iterator = &hashmap[hash];
    while (iterator != NULL)
    {

        if (strcmp(iterator->key, key_to_search) == 0)
        { // if key is found return entry
            return iterator;
        }
        iterator = iterator->next;
    }
    return NULL;
}
