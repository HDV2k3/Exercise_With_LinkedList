#include"stdio.h"
#include"conio.h"
#include"math.h"
typedef struct Node
{
	int data;
	Node* left;
	Node* right;
}Node;


Node *Insert(Node *p,int x)
{
	if(p==NULL){
	
	Node *temp=new Node;
	temp->data=x;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
	}
	else
	{
		if(x<p->data)
		{
			p->left=Insert(p->left,x);
			
		}
		else
		{
			p->right=Insert(p->right,x);
		}
	}
}


int CountLV(Node *T,int &LVL,int &LVR)
{
	if(T!=NULL)
	{
		int left=CountLV(T->left,LVL,LVR)+1;
		int right=CountLV(T->right,LVL,LVR)+1;
	
	if(left>right)
	{
		return left;
	}
	else
	{
		return right;
	}
}
}

int AVL(Node *T,int &LVL,int &LVR)
{
	if(T!=NULL)
	{
		int left=CountLV(T->left,LVL,LVR)+1;
		int right=CountLV(T->right,LVL,LVR)+1;
		if(left-right>1||left-right<1)
		{
			return -1;
		}
		else
		{
			return AVL(T->left,LVL,LVR) && AVL(T->right,LVL,LVR);
		}
	}
}
void preOrder( Node *p)
 {
     if(p != NULL)
     {
         printf("%d ", p->data);
         preOrder(p->left);
         preOrder(p->right);
     }
 }

int main()
{
	Node *p=NULL; //khoi tao cay ban dau
	int x,n;
	int dem=0;
	int LVL=0;
	int LVR=0;
	printf("Nhap n:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
	 p=Insert(p,x);
	}
	printf("NLR:");
	preOrder(p);
	if(AVL(p,LVL,LVR)==-1)
	{
		printf("khong phai cay nhi phan tim kiem can bang! ");
	}
	else
	{
		printf("\ndung la cay nhi phan");
		
	}


	return 0;
}
