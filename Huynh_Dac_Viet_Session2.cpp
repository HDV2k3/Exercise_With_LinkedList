#include<stdio.h>

 struct Node
{
	int data;
	Node* next;
};

Node* CreateNode(int init_data)
{
	Node* node = new Node;
	node->data = init_data;
	node->next = NULL;      
	return node;
}

struct LinkedList
{
	Node* head;
	Node* tail;
};

void CreateList(LinkedList& l)
{
	l.head = NULL;
	l.tail = NULL;
}

void AddHead(LinkedList& l, Node* node)
{
	if (l.head == NULL)
	{
		l.head = node;
		l.tail = node;
	}
	else
	{
		node->next = l.head;
		l.head = node;
	}
}

void AddTail(LinkedList& l, Node* node)
{
	if (l.head == NULL)
	{
		l.head = node;
		l.tail = node;
	}
	else
	{
		l.tail->next = node;
		l.tail = node;
	}
}

// them vao vi tri bat ki
void InsertAfterQ(LinkedList& l, Node* p, Node* q)
{
	if (q != NULL)
	{
		p->next = q->next;
		q->next = p;
		if (l.tail == q)
			l.tail = p;
	}
	else
		AddHead(l, p);
}

void PrintList(LinkedList l)
{
	if (l.head != NULL)
	{
		Node* node = l.head;
		while (node != NULL)
		{
			printf("%d\t", node->data);
			node = node->next; // chuyen sang node ke tiep
		}
	}
    if (l.head == NULL){
        printf("\ndanh sach rong");

    }
}

int RemoveHead(LinkedList& l, int& x)
{
	if (l.head != NULL)
	{
		Node* node = l.head;
		x = node->data;      
		l.head = node->next;
		delete node;         
		if (l.head == NULL)
			l.tail = NULL;
		return 1;
	}
	return 0;
}

int RemoveAfterQ(LinkedList& l, Node* q, int& x)
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

Node* GetNode(LinkedList& l, int index)
{
	Node* node = l.head;
	int i = 0;
	while (node != NULL && i != index)
	{
		node = node->next;
		i++;
	}
	if (i == index && node != NULL)
		return node;
	return NULL;
}

// xoa toan bo danh sach
void DestroyList(LinkedList& l)
{
	int x;
	Node* node = l.head;
	while (node != NULL)
	{
		RemoveHead(l, x);
		node = l.head;
	}
	l.tail = NULL;
}

Node* SearchNode(LinkedList l, int x)
{
    Node* node = l.head;
    while(node != NULL && node->data !=x){
        node = node->next;
    }
    if(node != NULL){
        return node;
    }
    
    return NULL;
}

int Length(LinkedList l)
{
	int count = 0;
	Node* node = l.head;
	while (node != NULL)
	{
		count++;
		node = node->next;
	}
	return count;
}

int lengthList(LinkedList list) {
    int count=0;
    if(list.head != NULL) {
        Node* node = list.head;
        while (node!= NULL)
        {
            count++;
            node= node->next;
        }
    }
    return count;
}

void SortList(LinkedList list) {
    int length = lengthList(list);
    // printf("da chay sap xep %d", length);
    if(list.head != NULL){
        Node* node1 = list.head;
        for(int i=0;i<length;i++){
            Node* node2 = list.head;
            for(int j=0;j<length-1;j++){
                if(node2->next != NULL){
                    if(node2->data > node2->next->data){
                        int temp;
                        temp = node2->data;
                        node2->data = node2->next->data;
                        node2->next->data = temp;
                    }
                }
                node2 = node2->next;
            }
        }
    }
    
}



void nhapN(int &n) {
    printf("nhap so phan tu:");
    scanf("%d", &n);
}

void nhapDSSoNguyen(LinkedList& l, int n){
    for(int i=0;i<n;i++){
        int tam;
        printf("nhap so thu %d: ", i);
        scanf("%d", &tam);
        AddHead(l,CreateNode(tam));
    }
}



int main() {
    LinkedList list;
    CreateList(list);
    int n, a[100];
    nhapN(n);
    nhapDSSoNguyen(list,n);
    PrintList(list);
    int x,y;
    printf("\nnhap them phan tu x vao dau: ");
    scanf("%d", &x);
    AddHead(list,CreateNode(x));
    PrintList(list);
    printf("\nnhap them phan tu x vao cuoi: ");
    scanf("%d", &x);
    AddTail(list, CreateNode(x));
    PrintList(list);
    RemoveHead(list,y);
    printf("\nsau khi xoa phan tu dau: \n");
    PrintList(list);
    RemoveAfterQ(list,GetNode(list,3), y);
    printf("\nsau khi xoa phan sau vi tri 3: \n");
    PrintList(list);
    printf("\nnhap gia tri muon tim: ");
    scanf("%d", &x);
    printf("phan tu can tim: %d\n ", SearchNode(list,x)->data);
	SortList(list);
	printf("\n----sau khi sap xep---\n");
	PrintList(list);
    DestroyList(list);
	printf("\n----sau khi xoa tat ca---\n");
    PrintList(list);

    return 0;
}

