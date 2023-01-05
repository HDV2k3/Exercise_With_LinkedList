#include <stdio.h>
#include <stdlib.h>

//tao node
struct Node {
    int data;
    struct Node* next; 
    Node* head;
    Node* tail;
};

// tao dslk
typedef struct Node* LinkedList;
// kiem tra dslk rong
int isEmpty(LinkedList list) {
    return list == NULL;
}
// chen them node moi vao dau dslk
void InsertFirst(LinkedList* head, int data) {
    struct Node*p = (struct Node*)malloc(sizeof(struct Node));
    p->data = data;
    p->next = NULL;
    if(isEmpty(*head)) {
        *head = p;
    } else {
        p->next = *head;
        *head = p;
    }
}

void AddTail(LinkedList* head,int data)
{
	if(isEmpty(*head))
	{
		InsertFirst(head,data);
	}
	else 
	{
		struct Node* X = *head;
		while (X->next !=NULL)
		{
			X =X->next; // tim node cuoi
		}
		struct Node* p= (struct Node*) malloc(sizeof(struct Node));
		p->data=data;
		p->next=NULL;
		X->next=p;
	}
}
// hien thi cac phan tu dslk ra man hinh
void showLinkedListElement(const LinkedList head) {
    const struct Node* p = head;
    while (p != NULL) {
        printf("%d => ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

void InsertAfter(LinkedList* head ,int data,int x )
{
	struct Node* p = *head;
	while(p->data!=x)
	{
		p=p->next;
		
	}
	if(p==NULL)
	{
		AddTail(head,data);
	}
	else
	{
		struct Node* q= (struct Node*) malloc(sizeof(struct Node));
		q->data=data;
		q->next=p->next;
		p->next=q;
	}
}

void DeleteFirst(LinkedList &l)
{
	if(l==NULL)
	{
		return;
	}
	l = l->next;
}

int RemoveAfterQ(LinkedList &l, Node* q, int& x)
{
	if (q != NULL)
	{
		Node* p = q->next;
		if (p != NULL)
		{
			if (l.tail == p)
				l.tail = q;
			q->next = p->next;
			x = p->data;
			delete p;
			return 1;
		}
		return 0;
	}
	return 0;
}
int main () {
    LinkedList singlyLinkedList = NULL;
    int n;
    puts("Nhap so luong phan tu muon them vao danh sach: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        InsertFirst(&singlyLinkedList, data);
    }
    int X=20;
    int k=40;
    InsertAfter(&singlyLinkedList,k,X);
    puts("Cac node trong danh sach lien ket: ");
    showLinkedListElement(singlyLinkedList);
	DeleteFirst(singlyLinkedList);
	showLinkedListElement(singlyLinkedList);
	Deletetail(singlyLinkedList);
	showLinkedListElement(singlyLinkedList);
	DeleteAfter(singlyLinkedList);
	showLinkedListElement(singlyLinkedList);
    return 0;
}
