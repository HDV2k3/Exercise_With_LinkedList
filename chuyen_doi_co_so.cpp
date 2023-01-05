#include <stdio.h>

struct Node{
    int data;
	Node* next;
};

struct Queue{
	Node *head, *tail;
};

void Init( Queue &q ){
	q.head = q.tail = NULL;
}

Node *createNode( int x ){
	Node *p = new Node;
	if(!p) return NULL;
	p->next = NULL;
	p->data = x;
	return p;
}

void Push(Queue &q, Node *p ){
  
	if(q.head == NULL) q.head = q.tail = p;
	else{
		q.tail->next = p;
		q.tail = p;
	}
}

int Top(Queue q ){
  
	if(q.head != NULL){
		return q.head->data;
	}
	else return 0;
}


int Pop(Queue &q ){
	if(q.head != NULL){
		Node *p = q.head;
		q.head = q.head->next;
		return p->data;
		delete p;
	}
	return 0;
}

void PopAll(Queue &q) {
    if(q.head != NULL) {
        Node* node = q.head;
        while (node!= NULL)
        {
            Pop(q);
            node = node->next;
        }
        
    }
    
}

void nhapN(int &n) {
    printf("nhap so phan tu:");
    scanf("%d", &n);
}

void nhapDSSoNguyen(Queue& q, int n){
    for(int i=0;i<n;i++){
        int tam;
        printf("nhap so thu %d: ", i);
        scanf("%d", &tam);
        Push(q,createNode(tam));
    }
}

int SearchQueue(Queue q, int x) {
    if(q.head != NULL ) {
        Node* node = q.head;
        while(node!=NULL ) {
            if(x==node->data) {
                return node->data;
            }
            node = node->next;
        }
        return -1;
    }
    return -1;
}

int lengthList(Queue list) {
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

void SortList(Queue q) {
    int length = lengthList(q);
    if(q.head != NULL){
        Node* node1 = q.head;
        for(int i=0;i<length;i++){
            Node* node2 = q.head;
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

void printQueue(Queue q) {
    if(q.head == NULL) {
        printf("QUEUE RONG");
    }
    if(q.head != NULL) {
        Node* node = q.head;
        printf("\ndanh sach queue: ");
    while (node != NULL)
    {
        printf("%d\t", node->data);
        node = node->next;
    }
    }
    
    
    
}

long decimalToBinary(int decimalnum)
{
    long binarynum = 0;
    int rem, temp = 1;
 
    while (decimalnum!=0)
    {
        rem = decimalnum%2;
        decimalnum = decimalnum / 2;
        binarynum = binarynum + rem*temp;
        temp = temp * 10;
    }
    return binarynum;
}


void QueueTPtoNP(Queue &q){
    if(q.head != NULL) {
        Node* node = q.head;
        while (node != NULL)
        {
            node->data = decimalToBinary(node->data);
            fflush(stdin);
            node = node->next;
        }
        
    }
    if (q.head == NULL){
        printf("\ndanh sach rong\n");

    }
}


int main () {
    int x, ganTim;
    Queue q;
    int n;
    Init(q);
    nhapN(n);
    nhapDSSoNguyen(q,n);
    printQueue(q);
    QueueTPtoNP(q);
    printf("\nsau khi chuyen nhi phan: \n");
    printQueue(q);
    printf("\n hien thang dau tien: %d", Top(q));
    printf("\n danh sach sau khi xoa thang dau tien: ");
    if(Pop(q) != 0) {
        printf("\nxoa thanh cong\n");
    }
    printQueue(q);
    printf("\n nhap so can tim: ");
    scanf("%d", &x);

    ganTim=SearchQueue(q,x);
    if(ganTim == -1) {
        printf("khong tim thay");
    }else{
        printf("so do la %d", ganTim);
    }
    printf("\nhien thi sau khi sap xep tang dan\n");
    SortList(q);
    printQueue(q);
    PopAll(q);
    printf("\nhien thi sau khi xoa tat ca\n");
    printQueue(q);
    return 0;
    
}
