#include"stdio.h"
#include"conio.h"
typedef struct Node
{
	int data;
	Node* left;
	Node* right;
}Node;
typedef Node * Tree;
// tao node
Node* CreateNode(int data)
{
	Node* node=new Node;
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return node;
}

void CreateTree(Tree &root)
{
    root = NULL;
}
//them node vao cay de lam con cua node goc
void InsertNode(Tree &T, Node *p) {
   if (p->data < T->data ) {
      if(T->left)
         InsertNode(T->left,p);
      else
         T->left = p;
   }
   else
   if (p->data > T->data){
      if(T->right)
         InsertNode(T->right,p);
      else
         T->right = p;
   }
}
//thu tuc them node cho cay ban dau
void PushNode(Tree &T,int n)
{
	Tree p = CreateNode(n);
	if(T==NULL)
	{
		T=p;
	}
	else
	{
		InsertNode(T,p);
	}
}

void InputTree(Tree &T)
{
	int n;
	printf("\nNhap vao cac phan tu cua cay nhi phan: || Nhap so 0 de ket thuc nhap!");
	
	do
	{
		int i;
		printf("\nNhap phan tu thu %d ",i++);
		scanf("%d",&n);
		if(n!=0)
		{
			PushNode(T,n);
		}
		}while(n!=0);
}


void NLR(Tree T)
{
	if(T!= NULL)
	{
		printf("%d ",T->data);
		NLR(T->left);
		NLR(T->right);
	}
	return;
}

void LNR(Tree T)
{
	if(T != NULL)
	{
		LNR(T->left);
		printf("%d ",T->data);
		LNR(T->right);
	}
		return;
}

void LRN(Tree T)
{
	if(T != NULL)
	{
		LRN(T->left);
		LRN(T->right);
	    printf("%d ",T->data);
	}
		return;
}
Node *MinValueNode(Node* T)
{
	Node *current=T;
	while(current && current->left!=NULL)
	{
		current=current->left;
	}
	return current;
}
//dem so node cua cay
int CountNode(Tree T)
{
	if(T==NULL)
	{
		return 0;
	}
	else
	{
		return CountNode(T->left)+CountNode(T->right)+1;
	}
}
// dem so node la cua cay
int CountLeaf(Tree T)
{
	if(T==NULL)
	{
		return 0;
	}
	else
	if (T->left == NULL && T->right == NULL){
		return 1;
	}else
	return CountLeaf(T->left)+CountLeaf(T->right);
}

int main()
{
	Tree T =NULL; //khoi tao cay ban dau
	int n;
	InputTree(T);
	printf("\nDuyet cay theo NLR:");
	NLR(T);
	printf("\nDuyet cay theo LNR:");
	LNR(T);
	printf("\nDuyet cay theo LRN:");
	LRN(T);
	printf("\nso node cua cay = %d ",CountNode(T));
	printf("\nso node la cua cay = %d ",CountLeaf(T));
	
	return 0;
}
