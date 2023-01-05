#include"stdio.h"
#include <stdlib.h>
#include <string.h>
struct Node
{
	int data;
	Node *left;
	Node *right;
};
Node *T;
void CreateEmptyTree(){
	T = NULL;
}
//int LeftOf(Node* T,int value  )
//{
//    return value < T->data;
//}
// 
//int RightOf(Node* T,int value )
//{
//    return value > T->data;
//}
// tao node
Node* CreateNode(int data)
{
	Node* node=new Node;
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return node;
}

Node *Insert(Node* T,int value)
{
	if(T==NULL) return CreateNode(value);
	if(value < T->data)
	{
		T->left=Insert(T->left,value);
	}
	else
	{
		T->right=Insert(T->right,value);
	}
	return T;
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

Node *Remove(Node* T,int value)
{
if(T == NULL){
		return T;
	}
	if(T->data > value){
		T->left = Remove(T->left, value);
	}else if(T->data < value){
		T->right = Remove(T->right, value);
	}else{
		Node *p = T;
		if(T->left == NULL){
			T=T->right;
			delete p;
		}else if(T->right== NULL){
			T=T->left;
			delete p;
		}else{
			Node *temp = MinValueNode(T->right);
			T->data = temp->data;
			T->right = Remove(T->right, temp->data);
		}
	}
	return T;
}
Node *Search(Node* T, int value )
{
     if ( T != NULL )
     if(T->data == value){
			return T;
		}
		if(T->data > value){
			return Search(T->left,value);
		}else{
			return Search(T->right,value);
		}
		return NULL;
	}



void NLR(Node *T)
{
	if(T != NULL)
	{
		printf("%d ",T->data);
		NLR(T->left);
		NLR(T->right);
	}
}
void LNR(Node *T)
{
	if(T != NULL)
	{
		LNR(T->left);
		printf("%d ",T->data);
		LNR(T->right);
	}
		return;
}

void LRN(Node *T)
{
	if(T != NULL)
	{
		LRN(T->left);
		LRN(T->right);
	    printf("%d ",T->data);
	}
		return;
}
//Node* MaxValueNode(Node *T, int Max)
//{
//    if (T==NULL)
//    {
//        return T;
//    }
//    if (T->left != NULL)
//		Max = (Max > T->left->data)? Max : T->left->data;
//    if (T->right != NULL)
//        Max = (Max > T->right->data)? Max : T->right->data;
//    Max = (Max > T->data) ? Max : T->data;
//    MaxValueNode(T->left,Max);
//    MaxValueNode(T->right,Max);
//}
int MaxValue( Node* T)
{  

 	 Node* current = T;
    while (current->right != NULL)
        current = current->right;
     
    return (current->data);
}
 int MinValue(Node* T)
{
    Node* current = T;
    while (current->left != NULL) {
        current = current->left;
    }
    return (current->data);
}
//Node *CheckBTS(Node *T)
//{
//    if (T==NULL)
//    {
//        return T;
//    }
//    Node* Left = CheckBTS(T->left);
//    int MaxL, MaxR;
//    if (T->left != NULL && T->right != NULL)
//    {
//        MaxValueNode(T->left, MaxL);
//        MaxValueNode(T->right, MaxR);
//        if (!(MaxL < T->data && T->data < MaxR))
//            return T;
//    }
//    else if (T->left == NULL && T->right != NULL)
//    {
//        MaxValueNode(T->right, MaxR);
//        if (!(T->data < MaxR))
//            return T;
//    }
//    else if (T->left != NULL && T->right == NULL)
//    {
//        MaxValueNode(T->left, MaxL);
//        if (!(MaxL < T->data))
//            return T;
//    }
//    Node* Right = CheckBTS(T->right);
//   return Left+Right;
//}
//void PrintCheck(Node T)
//{
//    int check = CheckBTS(T);
//    if (check == 0)
//        printf("\nsuccessfully <3 ");
//    else
//        printf("\n not successfully :(( ");
//}
//int isFullTree (Node* T)
//{
//    if (T == NULL)
//        return true;
//    if (T->left == NULL && T->right == NULL)
//        return true;
//    if ((T->left) && (T->right))
//        return (isFullTree(T->left) && isFullTree(T->right));
//    return false;
//}
//Node *FindParent( Node* T,int val, int parent)
//{
//    if (T == NULL)
//        return T;
//    if (T->data == val) {
//       printf("%d",parent);
//    }
//    else {
//        FindParent(T->left,val,T->data);
//        FindParent(T->right,val,T->data);
//    }
//}
// 

int main()
{
	CreateEmptyTree(); //khoi tao cay ban dau
		int choice;
	int x;
	do
	{
	printf("\n========Menu========\n");
	printf("\n-1.Insert:");
	printf("\n-2.Search:");
	printf("\n-3.Remove:");
	printf("\n-4.PrintNLR:");
	printf("\n-5.PrintfLNR:");
	printf("\n-6.PrintfLRN:");
//	printf("\n-7.PrintCheck:");
//	printf("\n-7.CheckFullTree:");
//	printf("\n-8.FindParent:");
	printf("\n-7.FindMaxValue:");
	printf("\n-8.FindMinValue:");
	printf("\n-9.Exit!");
	printf("\n===== By HDV =======\n");
	scanf("%d",&choice);
	switch(choice)	
	{
		case 1:
			{
			
				printf("\nInput your number to insert: "); scanf("%d", &x);
				T = Insert(T, x);
				printf("\nInput successfully!");
			}
				break;
		case 2:	
				{
				printf("\nInput your number to find: "); scanf("%d", &x);
				Node *tmp = Search(T, x);
				if(tmp !=NULL){
					printf("\nFind successfully!");
					printf("\nValue: %d", tmp->data);
					if(tmp->right != NULL)
						printf("\nRight-child value: %d", tmp->right->data);
					else
						printf("\nRight-child value: NULL");
					if(tmp->left != NULL)
						printf("\nLeft-child value: %d", tmp->left->data);
					else
						printf("\nLeft-child value: NULL");
				}else{
					printf("\ndoes not exist %d",x);
				}
		}
				break;			
				
		case 3:
			{
			
				printf("\nInput your number to Remove: "); scanf("%d", &x);
				T= Remove(T,x);
				printf("\nRemove successfully!");
			}
				break;
		case 4:
		{
			printf("NLR: ");
			NLR(T);
			}
				break;	
		case 5:
			{
				printf("LNR: ");
				LNR(T);
			}
			break;
		case 6:
			{
				printf("LRN: ");
				LRN(T);
			}
//		case 7:
//			{
//				printf("Check BTS true or false: ");
//				PrintCheck(T);
//			}
//		case 7:
//			{
//				printf("Check BTS isFullTree: %c ",isFullTree(T));
//			}
//		case 8:
//		{
//			printf("\nInput your number to FindParent: "); scanf("%d", &x);
//			T=FindParent(T,x,-1);
//			printf("\nsuccessfully! ");
//			}
		case 7:
		{
			printf("\nMaxValue: %d ",MaxValue(T));
			
			}
		case 8:
			{
				printf("\nMinValue: %d ",MinValue(T));
				
			}
		case 9:
				break;
			default:
				printf("\nWrong input!");
				break;
				
		}
	}while(choice!=9);
	return 0;
}




