#include <stdio.h>
#include <stdlib.h>
/* This data is not always stored in a structure, but it is sometimes for ease of use */
//表头结点（又称伪结点）位于表的最前端，本身不带数据，仅标志表头。
//置表头结点的目的是统一空表与非空表、表头和表中位置的操作形式，简化链表操作的实现。
typedef struct student
{
    int score;
    struct student *next;
} LinkList;
void deletelast(LinkList *list);
LinkList *creat(int n)
{
    LinkList *head, *node, *end;
    head = (LinkList *)malloc(sizeof(LinkList)); // 表头结点 head only have pointer, no value
    end = head;
    for (int i = 0; i < n; i++)
    {
        node = (LinkList *)malloc(sizeof(LinkList));
        printf("please entre the score:\n");
        scanf("%d", &node->score);
        end->next = node;
        end = node;
    }
    end->next = NULL;
    return head;
}
int main()
{
    LinkList *h;
    int n = 5;
    h = creat(n);
    /*while (h->next != NULL)
    {
        h = h->next;
        printf("%d\t", h->score);
    }*/
    deletelast(h);
      while (h->next != NULL)
    {
        h = h->next;
        printf("%d\t", h->score);
    }
    return 0;
}

/*void deletelast(LinkList *list,int n)
{
    LinkList*t=list, *temp;
int i=0;
while (i<n && t!= NULL)
    { 
        temp=t;
        t=t->next;
        i++;
    }
    if (t!=NULL)
    {
        temp->next=t->next;
         free(t);
    }
    else
    {
        printf("the node is not exist!\n");
    }
    
}*/
void deletelast(LinkList *list)
{
    LinkList*t=list, *temp;
    temp=t;
while (t->next!= NULL)
    { 
        temp=t;
        t=t->next;
    }
        temp->next=NULL;
         free(t);
    
    
}
