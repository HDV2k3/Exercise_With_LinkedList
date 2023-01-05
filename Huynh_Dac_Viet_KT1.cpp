#include"stdio.h"

typedef struct HinhChuNhat
{
	int CD;
	int CR;
	int DT;	
}HCN;
struct Node{
	HCN data;
	Node* next;
};
typedef struct Node NODE;
struct LinkedList {
	NODE* head;
	NODE* tail;
};
typedef struct LinkedList LIST;
void CreateList(LinkedList &l)
{
	l.head=NULL;
	l.tail=NULL;
}

Node* CreateNode(HCN init_data)
{
	Node* node = new Node;
	node->data = init_data;
	node->next = NULL;
	return node;
}

void InputData(HCN &hcn)
{
	printf("\nNhap chieu rong:");
	scanf("%d",&hcn.CR);
	printf("\nNhap chieu dai:");
	scanf("%d",&hcn.CD);
	hcn.DT=hcn.CD*hcn.CR;
}


void AddHead(LIST &l,Node* node)
{
	if(l.head==NULL)
	{
		l.head=l.tail=node;
	}
	else 
	{
		node->next=l.head;
		l.head=node;
	}
}

void AddTail(LIST &l,Node* node)
{
	if(l.head==NULL)
	{
		l.head=l.tail=node;
	}
	else
	{
		l.tail->next=node;
		l.tail=node;
	}
}

void DeleteFisrt(LIST &l)
{
	if(l.head==NULL)
	{
		printf("\danh sach rong:");
		
	}
	else if (l.head==l.tail)
	{
		delete l.head;
		l.head=l.tail=NULL;
	}
	else 
	{
		Node *temp = l.head;
		l.head=l.head->next;
		delete temp;
	}
}
void RemoveTail(LIST &l)
{
   if (l.head==NULL)
     printf("\ndanh sach rong:");
   else if (l.head == l.tail)
   {
      delete l.head;
      l.head = l.tail = NULL;
   }
   else
   {
      Node *temp = l.head;
      while (temp->next != l.tail)
         temp = temp->next;
      delete l.tail;
      l.tail = temp;
   }
}

void ShowList(LIST l)
{
	printf("\n------- danh sach hinh chu nhat------");
	if(l.head!=NULL)
	{
		Node* node=l.head;
		while (node!=NULL)
		{
			printf("\nrong = %d ,dai = %d, dien tich = %d \n",node->data.CR,node->data.CD,node->data.DT);
			node= node->next;
		}
	}
	if(l.head==NULL)
	{
		printf("\ndanh sach rong:");
	}
}
Node* SearchNode(LIST l, int x)
{
    Node* node = l.head;
    while(node != NULL && node->data.DT !=x){
        node = node->next;
    }
    if(node != NULL){
        return node;
    }
    
    return NULL;
}
void nhapN(int &n) {
    printf("nhap so luong hinh chu nhat:");
    scanf("%d", &n);
}

void nhapMangHCN(HCN a[], int n) {
    for(int i=0;i<n;i++) {
        printf("nhap hinh chu nhat thu %d: ", i);
        InputData(a[i]);
    }
}

void AddMany(LIST& l, HCN a[], int n) {
    for(int i=0;i<n;i++) {
        AddTail(l , CreateNode(a[i]));
    }
}

void nhapDSHCN(LIST& l, int n){
    for(int i=0;i<n;i++){
        HCN tam;
        InputData(tam);
        AddHead(l,CreateNode(tam));
    }
}

int main() {
    int n, x;
    HCN a[100];
    HCN c;
    LinkedList LIST;
    CreateList(LIST);
    nhapN(n);
    nhapDSHCN(LIST,n);
    ShowList(LIST);
    InputData(c);
    AddHead(LIST,CreateNode(c));
    ShowList(LIST);
  	InPutData(c);
    AddTail(LIST,CreateNode(c));
    ShowList(LIST);
    printf("\n----them nhieu hinh chu nhat vao danh sach----\n");
   	nhapN(n);
   	nhapMangHCN(a,n);
    AddMany(LIST,a,n);
    printf("\n----danh sach sau khi them-----\n");
    ShowList(LIST);
    printf("nhap dien tich x muon tim: ");
    scanf("%d", &x);
    Node* b= SearchNode(LIST,x);
    printf("hinh chu nhat do la: ");
    if(b==NULL){
        printf("khong tim thay x trong danh sach");
    }else
    printf("rong =%d, dai= %d, dien tich= %d \n", b->data.CR, b->data.CD, b->data.DT);
    return 0;
}
