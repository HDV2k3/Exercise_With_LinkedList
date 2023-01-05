#include<stdio.h>
#include<stdlib.h>
#define COUNT 5

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};
int max(int a, int b);
int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return 1+max(height(N->left), height(N->right));
}
 
int max(int a, int b)
{
    return (a > b)? a : b;
}
struct Node* newNode(int key)
{
    struct Node* node = (struct Node*)
                        malloc(sizeof(struct Node));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 0;
    return(node);
}

struct Node *rightR(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;
 
    x->right = y;
    y->left = T2;

    y->height = height(y);
    x->height = height(x);
 
    return x;
}
 
struct Node *leftR(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;
 
    
    y->left = x;
    x->right = T2;
 
  
    x->height = height(x);
    y->height = height(y);
 
  
    return y;
}
 
int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
 
struct Node* insert(struct Node* node, int key)
{
    
    if (node == NULL)
        return(newNode(key));
 
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else 
        return node;

    node->height = height(node);
 
    int balance = getBalance(node);
 
    if (balance > 1 && key < node->left->key)
        return rightR(node);

    if (balance < -1 && key > node->right->key)
        return leftR(node);
 
    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftR(node->left);
        return rightR(node);
    }
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightR(node->right);
        return leftR(node);
    }
    return node;
}
 
 void preOrder(struct Node *node)
 {
     if(node != NULL)
     {
         printf("%d ", node->key);
         preOrder(node->left);
         preOrder(node->right);
     }
 }
 struct Node*  minValueNode(struct Node* node)
{
    struct Node* current = node;  
    while (current->left != NULL)
        current = current->left;
    return current;
}

 Node* deleteNode(Node* node, int key)
{
    if (node == NULL)
        return node;
    if ( key < node->key )
        node->left = deleteNode(node->left, key);
    else if( key > node->key )
        node->right = deleteNode(node->right, key);
    else
    {
        
        if( (node->left == NULL) || (node->right == NULL) )
        {
             Node *temp = node->left ? node->left : node->right;
            if (temp == NULL)
            {
                temp = node;
                node = NULL;
            }
            else 
             *node = *temp; 
            free(temp);
        }
        else
        {
            struct Node* temp = minValueNode(node->right);
            node->key = temp->key;
            node->right = deleteNode(node->right, temp->key);
        }
    }
    if (node == NULL)
      return node;
    node->height = 1 + max(height(node->left),height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && getBalance(node->left) >= 0)
        return rightR(node);
    if (balance > 1 && getBalance(node->left) < 0)
    {
        node->left =  leftR(node->left);
        return rightR(node);
    }

    if (balance < -1 && getBalance(node->right) <= 0)
        return leftR(node);
 
    if (balance < -1 && getBalance(node->right) > 0)
    {
        node->right = rightR(node->right);
        return leftR(node);
    }
 
    return node;
}

void print2DUtil(Node* node, int space)
{
	// Neu NULL thi khong in
	if (node == NULL)
		return;
	
	// Tang khoang cach giua cac muc
	space += COUNT;
	
	// Xu ly node con ben phai truoc (de quy)
	print2DUtil(node->right, space);
	
	// In node hien tai sau khoang cach COUNT
	//printf("\n"); de tang so khoa`ng cach dong
	for (int i = COUNT; i < space; i++)
		printf(" ");
	
	printf("%d(%d)  \n",node->key,node->height);
	
	// Xu ly node con ben trai (de quy)
	print2DUtil(node->left, space);
}

// bat dau in cay AVL, BST ra man hinh
void print2D(Node* node)
{
	// gia tri khoang cach cua node root la 0
	print2DUtil(node, 0);
}

int main()
{
  struct Node *node = NULL;
    int choice;
    int x;
    do
    {
        printf("\n========Menu========\n");
        printf("\n-1.Insert:");
        printf("\n-2.Delete:");
        printf("\n-3.Print PreOrder:");
        printf("\n-4.PrintAVL2D:");
        printf("\n-5.Exit!\n");
        scanf("%d",&choice);
            switch (choice)
            {
            case 1:
            {
                printf("\nInput your number to insert: "); scanf("%d", &x);
				node=insert(node,x);
				printf("\nInput successfully!");
            }
                break;
            case 2:
            {
                printf("\nInput your number to delete: "); scanf("%d", &x);
				node=deleteNode(node,x);
				printf("\ndelete successfully!");
            }
            break;
            case 3:
            	{
            		printf("\nPrint PreOrder:");
            		preOrder(node);
				}
            case 4:
            {
            	printf("\nHinh cua cay avl:");
                print2D(node);
            }
            case 5:

                break;
            default:
                printf("\nThoat !");
                break;
            }
    } while (choice!=5);
        
  return 0;
}
