#include "stdio.h"
#include "stdlib.h"

/*树节点*/
typedef struct Binode
{
    int data;
    struct Binode *left;  /*节点左边的树枝*/
    struct Binode *right; /*节点右边的树枝*/
} Binode, *Node;

void tree_init(Node *, int value); // add a value to tree root
Node tree_assign(Node, int value); // add others values, small on left, big on right
void tree_pre_order(Node);
void tree_in_order(Node);
void tree_post_order(Node);
int tree_max_depth(Node); // levels
int tree_num_leaf(Node);  // 结点为0
int tree_count_order(Node tree);
int tree_has_value(Node tree, int val);
void tree_double_values(Node tree);
int tree_has_even_leaves(Node tree);

int main(void)
{
    Node tree; // node is already a pointer to Binode!!!
    int len, i;
    int arr[] = {9, 11, 6, 3, 8, 12};
    len = sizeof(arr) / sizeof(int);
    tree_init(&tree, 10);
    for (i = 0; i < len; i++)
    {
        tree_assign(tree, arr[i]);
    }
    int nb;
    int lef = tree_num_leaf(tree);
    nb = tree_has_even_leaves(tree);
    printf("the nb is%d, and eve is%d", lef, nb);
    // tree_pre_order(tree);
    // printf("\n");
    // tree_double_values(tree);
    // tree_pre_order(tree);
    // printf("\n");
    //  tree_post_order(tree);
    //  printf("\n");

    // printf("max depth is:%d\n", tree_max_depth(tree));
    //  printf("num of leaf is:%d\n", tree_num_leaf(tree));

    // system("pause");
    return 0;
}
void tree_init(Node *tree, int value)
{
    (*tree) = malloc(sizeof(Binode));
    (*tree)->data = value;
    (*tree)->left = NULL;
    (*tree)->right = NULL;
}
Node tree_assign(Node tree, int value)
{
    if (!tree) // if tree is NULL
    {
        tree = malloc(sizeof(Binode));
        tree->data = value;
        tree->left = NULL;
        tree->right = NULL;
        return tree;
    }
    if (value < tree->data)
    {
        tree->left = tree_assign(tree->left, value);
    }
    else
    {
        tree->right = tree_assign(tree->right, value);
    }
    return tree;
}
void tree_pre_order(Node tree)
{
    if (!tree) // if tree is NULL
        return;
    printf("%d\t", tree->data);
    tree_pre_order(tree->left);
    tree_pre_order(tree->right);
}
void tree_in_order(Node tree) // 6-8-9-11-12 from le most left
{
    if (!tree) // if tree is NULL
        return;
    tree_in_order(tree->left);
    printf("%d\t", tree->data);
    // printf("+1");
    tree_in_order(tree->right);
}
void tree_post_order(Node tree) // 8-6-9-12-11-10???
{
    if (!tree) // if tree is NULL
        return;
    tree_post_order(tree->left);
    tree_post_order(tree->right);
    printf("%d\t", tree->data);
}
int tree_max_depth(Node tree)
{
    int max_left = 0;
    int max_right = 0;
    if (!tree) // if tree is NULL
        return 0;
    max_left = tree_max_depth(tree->left);
    max_right = tree_max_depth(tree->right);
    if (max_left > max_right)
    {
        return 1 + max_left;
    }
    else
    {
        return 1 + max_right;
    }
}
int tree_num_leaf(Node tree)
{
    if (!tree) // if tree is NULL
        return 0;
    if (!tree->left && !tree->right) // if tree left and right is NULL
    {
        return 1;
    }
    else
    {
        return tree_num_leaf(tree->left) + tree_num_leaf(tree->right);
    }
}
int tree_has_even_leaves(Node tree)
{
    if (!tree) // if tree is NULL
        return 1;
    if (!tree->left && !tree->right) // if tree left and right is NULL
    {
        return 0;
    }
    else
    {
        return (tree_has_even_leaves(tree->left) + tree_has_even_leaves(tree->right) + 1) % 2;
    }
}

int tree_count_order(Node tree) // 6-8-9-11-12 from le most left
{
    if (!tree) // if tree is NULL
        return 0;
    return 1 + tree_count_order(tree->left) + tree_count_order(tree->right);
}
int tree_has_value(Node tree, int val)
{
    if (!tree) // if tree is NULL
        return 0;
    if (tree->data == val)
        return 1;
    else
    {
        return (tree_has_value(tree->left, val) || tree_has_value(tree->right, val));
    }
}
void tree_double_values(Node tree)
{
    if (!tree) // if tree is NULL
        return;
    int temp;
    temp = tree->data;
    tree->data = temp * 2;
    tree_double_values(tree->left);
    tree_double_values(tree->right);
}

// from here for nowledgeable
/*int tree_count_nodes(Node *tree) // for nowledgeable
{
    if (!tree) // if tree is NULL
        return 0;
    return 1 + tree_count_nodes((tree)->left) + tree_count_onodes((tree)->right);
}
Node *create_node(int val)
{
    Node *newnode;
    newnode = (Node *)malloc(sizeof(Node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}*/

void log_tree_preorder(Node* tree){
    // ordered way
    // 1. Create an empty stack (say S).
    // 2. Initialize the current node as root.
    // 3. Push the current node to S and set current = current->left until current is NULL
    // 4. If current is NULL and the stack is not empty then:
    // 4.1 Pop the top item from the stack.
    // 4.2 Print the popped item and set current = popped_item->right 
    // 4.3 Go to step 3.
    // 5. If current is NULL and the stack is empty then we are done.
    /*
    Stack *s = create_stack();
    Node *n = tree;
    
    while (n != NULL || !is_empty(s)) {
        while(n != NULL) {
            push(s, n);
            n = n->left;
        }
        
        if(is_empty(s)) {
            continue;
        }
        
        Node *p = pop(s);
        _log(p->data);
        n = p->right;
    }
    */
    
    // BFS order
    Stack *s = create_stack();
    push(s, tree);
    
    while(!is_empty(s)) {
        Node *n = pop(s);
        _log(n->data);
        
        Node *l = n->left;
        Node *r = n->right;
        
        if(r!=NULL) {
            push(s, r);
        }
        
        if(l!=NULL) {
            push(s, l);
        }
        
    }
}