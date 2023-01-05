#include"stdio.h"
#include"string.h"

typedef struct MatHang
{
    /* data */char TenMh[41];
    char MaMh[31];
    float Gia;
}MH;

typedef struct Node
{
    /* data */MH data;
    Node* next;
}NODE;

NODE* CreateNode(MH x)
{
    NODE* node=new node;
    node->data=x;
    node->next=NULL;
    return node;
}
void Init(NODE* phead)
{
    phead=NULL;
}
void IsEmpty(NODE* phead)
{
    return phead==NULL;
}

void AddFirst(NODE* &phead,MH x)
{
    NODE* p=CreateNode(x);
    p=phead->next;
    p=phead;
}

NODE* AddTail(NODE* &phead,MH x)
{
    NODE* p=phead;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    NODE* temp=new node;
    temp->data=x;
    temp->next=NULL;
    p->next=NULL;
    return phead;
}

void DeleteF(NODE* phead)
{
    NODE* p=phead;
    if(IsEmpty(phead))
    {
        printf("\nlist is NULL!";)
    }
    else
    {
        phead=phead->next;
        p=phead;
        delete(p);
    }
}

NODE* DeleteT(NODE* phead,MH x)
{
    NODE* p=phead;
    while(p->next->next!=NULL)
    {
        p=p->next;
    }
    delete(p->next);
    p->next=NULL:
    return phead;
}
int Count(NODE* phead)
{
    int count=0;
    for(NODE* p=phead;phead!=NULL;phead=phead->next)
    {
        count++;
    }
    return count;
}

NODE* SearchMa(NODE* &phead,MH x)
{
    while (phead!=NULL&&phead->data.MaMh!=x)
    {
        /* code */phead=phead->next;
    }
    return phead;
    
}
