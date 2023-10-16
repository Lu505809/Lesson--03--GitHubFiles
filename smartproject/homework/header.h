typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void insert_at_end(struct Node **pheadNode, int value);
void print_list(struct Node *headNode);