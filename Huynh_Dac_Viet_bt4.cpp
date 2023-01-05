#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* CreateNode(int x) {
    Node* node = new Node;
    node->data = x;
    node->left = node->right = NULL;
    return node;
}


void CreateTree(Node* &root) {
    root = NULL;
}


int isEmpty(Node* t) {
    return t!=NULL;
}


int InsertLeft(Node* p, Node* node) {
    if(p==NULL) {
        return-1;
    }else{
        if(p->left!=NULL) {
            return -1;
        }
        else{
            if (p->left==NULL)
            {
                p->left=node;
                return 1;
            }
            
        }
    }
    return -1;
}

int InsertRight(Node* p, Node* node) {
    if(p==NULL) {
        return-1;
    }else{
        if(p->right!=NULL) {
            return -1;
        }
        else{
            if (p->right==NULL)
            {
                p->right=node;
                return 1;
            }
            
        }
    }
    return -1;
}

void PreOrder(Node* node) {
    if(node != NULL) {
        printf("%d\t",node->data);
        PreOrder(node->left);
        PreOrder(node->right);
    }
}



void InOrder(Node* node) {
    if(node != NULL) {
        InOrder(node->left);
        printf("%d\t",node->data);
        InOrder(node->right);
    }
}



void PostOrder(Node* node) {
    if(node != NULL) {
        PostOrder(node->left);
        PostOrder(node->right);
        printf("%d\t",node->data);
    }
}





void ClearTree(Node* root)
{
    if (root)
    {
        ClearTree(root->left);
        ClearTree(root->right);
        delete root;
    }
}



Node *FindNode(Node* root, int x)
{
    if (root)
    {
        if (root->data == x) 
            return root;
        if (x < root->data)
            return FindNode(root->left, x); 
        return FindNode(root->right, x); 
    }
    return NULL;
}


void AddNode(Node* &root, Node *node)
{
    if (root!=NULL)
    {
        if (root->data == node->data) 
            return;
        if (node->data < root->data) 
            AddNode(root->left, node);
        else
            AddNode(root->right, node); 
    }
    else
    {
        root = node;
    }
}

void AddMany2(Node* &root, int a[], int n){
    for(int i=0;i<n;i++) {
    AddNode(root,CreateNode(a[i]));
    }
}

void nhapN(int &n) {
    printf("nhap so luong so: ");
    scanf("%d", &n);
}


void nhapMang(int a[], int n) {
    for(int i=0;i<n;i++){
        printf("nhap so thu %d: ", i);
        scanf("%d", &a[i]);
    }
}

void xuatMang(int a[], int n) {
    for(int i=0;i<n;i++){
        printf("%d\t ", a[i]);
    }
}


int main() {

    int n, a[100];
    Node* root;
    CreateTree(root);
    nhapN(n);
    nhapMang(a,n);
    AddMany2(root,a,n);
    PreOrder(root);
    return 0;
}

