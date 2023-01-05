#include"stdio.h"

struct Node
{
	int data;
	Node *next;
};

Node *CreateNode(int init_data)
{
	Node* node = new Node;
	node->data=init_data;
	node->next=NULL;
	return node;
}

struct LinkedList
{
	Node* head;
	Node* tail; 
};
typedef struct LinkedList LIST;

void CreateList(LIST &l)
{
	l.head=l.tail=NULL;
}
void AddHead(LIST &l,Node* node)
{
	if(l.head==NULL)
	{
		l.head=node;
		l.tail=node;
	}
	else
	{
		node->next=l.head;
		l.head=node;
	}
}




void NhapN(int &n)
{
	printf("\nNhap so phan tu:");
	scanf("%d",&n);
}

// void GanDSVaoMang(int a[],LIST l,int n){
// 	Node* node =l.head;
// 	for(int i=0;i<n;i++)
// 	{
// 		if(node!=NULL)
// 		{
// 			a[i]=node->data;
// 			node=node->next;
// 		}
// 	}
// }
//cau a
void NhapDSDSNguyen(LIST &l,int n)
{
	for(int i=0;i<n;i++)
	{
		int tam;
		printf("Nhap phan tu thu %d:",i);
		scanf("%d",&tam);
		AddHead(l,CreateNode(tam));
	}
}
//cau b
void PrinList(LIST l)
{
	if(l.head!=NULL)
	{
		Node *node=l.head;
		while(node!=NULL)
		{
			printf("%d\t",node->data);
			node=node->next;
			}	
	}
	if(l.head==NULL)
	{
		printf("\n danh sach rong!");
	}
}
//cau c
Node* SearchNode(LIST l,int x)
{
	while(l.head!=NULL&&l.head->data!=x)
	{
		l.head=l.head->next;
	}
	return l.head;
}
//cau c
int InsertAfterX(LIST& l,Node* p,Node* q)
{
	if(q!=NULL)
	{
		p->next=q->next;
		q->next=p;
		if(l.tail==q)
		{
			l.tail->next = p;
			l.tail=p;	
		}
			
		
	}
	else 
	AddHead(l,p);
}
// cau d
int lendth(LIST l)
{
	int count =0;
	Node* node =l.head;
	while(node!=NULL)
	{
		count++;
		node = node->next;
	}
	return count;
}
//cau e
int OfK(LIST l,int k)
{
	int count=0;
	while(l.head!=NULL)
	{
		if(k==count)
		return l.head->data;
		count++;
		l.head=l.head->next;
	}
}
// cau f
int MaxValue(LIST l)
{
	int max = l.head->data;
	while(l.head!=NULL){
		if(l.head->data>max)
		max=l.head->data;
		l.head=l.head->next;
	}
	return max;
}
//cau g
void DeleteK(LIST& l ,int x)
{
	Node* temp = SearchNode(l,x);
	Node* p =l.head;
	while(p->next!=NULL){
		if(p->next->data==temp->data)
		{
		Node* node2= p->next->next;
		p->next = node2;  
		delete(temp);
		}
		p=p->next;
	}
	
}    
// cau h
void SortList(LIST& l)
{
	for(Node* p=l.head;p->next!=NULL;p=p->next)
	{
		for(Node* q=p->next;q!=NULL;q=q->next)
		if(p->data>q->data)
		{
			int temp = p->data;
			p->data=q->data;
			q->data=temp;
		}
	}
}

int main()
{
	LinkedList LIST;
	CreateList(LIST);
	int n,a[100];
	NhapN(n);
	NhapDSDSNguyen(LIST,n);
	PrinList(LIST);
	int x,y,k;
	printf("\nNhap gia tri muon tim:");
	scanf("%d",&x);
	printf("\nphan tu can tim : %d ",SearchNode(LIST,x)->data);
	printf("\nNhap phan tu can them:");
	scanf("%d",&y);
	InsertAfterX(LIST,CreateNode(y), SearchNode(LIST,x));
	PrinList(LIST);

	printf("\n so node co tren danh sach = %d ",lendth(LIST));
	printf("\nGia tri cua node can tim:");
	scanf("%d",&k);
	printf("\nGia tri cua node  = %d ",OfK(LIST,k));
	printf("\nGia tri lon nhat = %d ",MaxValue(LIST));
	printf("\nNhap phan tu can xoa:");
	scanf("%d",&y);
	DeleteK(LIST,y);
	PrinList(LIST);
	printf("\ndanh sach sau khi sap xep:");
	SortList(LIST);
	PrinList(LIST);
	return 0;
}
