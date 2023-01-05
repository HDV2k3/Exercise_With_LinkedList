#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
//--------------------
typedef struct Node{
	int value;
	Node *next;
}NODE;
//--------------------
typedef struct List{
	NODE *head;
	NODE *tail;
}LIST;
//--------------------
void initList(LIST &ds){
	ds.head=NULL;
	ds.tail=NULL;
}
//--------------------
int isEmpty(LIST ds){
	if(ds.head==NULL) return 1;
	else return 0;
}
//--------------------
NODE* createNode(int x){
	NODE *p;
	p=new NODE;
	if(p==NULL){
		cout<<"Khong du bo nho";
		return NULL;
	}
	p->value=x;
	p->next=NULL;
	return p;	
}
//---------------------
void insertFirst(LIST &ds, NODE *p){
	if(ds.head==NULL){
		ds.head=p;
		ds.tail=p;
	}
	else{
		p->next=ds.head;
		ds.head=p;
	}
}
//----------------------
void insertLast(LIST &ds, NODE *p){
	if(ds.head==NULL){
		ds.head=p;
		ds.tail=p;
	}
	else{
		ds.tail->next=p;
		ds.tail=p;
	}		
}
//----------------------
void insertAfter(LIST &ds, NODE *q, NODE*p){
	if(q!=NULL){
		p->next=q->next;
		q->next=p;
		if(q==ds.tail) ds.tail=p;
	}
	else{
		insertFirst(ds,p);
	}
}
//----------------------
void deleteFirst(LIST &ds){
	NODE *p=new NODE;
	p=ds.head;
	ds.head=ds.head->next;
	p->next=NULL;
	delete p;
}
//-----------------------
void deleteLast(LIST &ds){
	for(NODE *p=ds.head;p!=NULL;p=p->next){
		if (p->next==ds.tail){
			delete ds.tail;
			p->next=NULL;
			ds.tail=p;
		}
	}
	
}
//-----------------------
void deleteAll(LIST &ds){
	NODE *p=ds.head;
	while(p!=NULL){
		deleteFirst(ds);
		p=ds.head;	
	}	
	ds.tail=NULL;
}
//-----------------------
void showList(LIST ds){
	NODE *p=ds.head;
	while(p!=NULL){
		cout<<p->value<<" ";
		p=p->next;
	}
	cout<<"\n";
}
//-----------------------
NODE* findItem(LIST ds, int x){
	NODE *p=ds.head;
	while((p!=NULL) && (p->value!=x)){
		p=p->next;
	}
	return p;
}
//-----------------------
int length(LIST ds){
	int count=0;
	NODE *p=ds.head;
	while(p!=NULL){
		count++;
		p=p->next;
	}
	return count;
}
//------------------------
void insertAscending(LIST &ds, int x){
	NODE *p=ds.head;
	//neu ds rong thi chen x vao dau ds
	if(p==NULL){
		insertFirst(ds,createNode(x));
	}
	else{
		//neu phan tu dau cua ds lon hon x thi chen x vao dau ds
		if(p->value>x){
			insertFirst(ds,createNode(x));
		}
		else{
			NODE *q=p->next;
			while(q!=NULL && q->value<x){
				p=q;
				q=q->next;
			}
			if(q==NULL){
				insertLast(ds,createNode(x));
			}
			else{
				insertAfter(ds,p,createNode(x));
			}
		}
	}
}
//-------------------------
void sortList(LIST &ds){
	int temp;
	for(NODE *p=ds.head;p!=NULL;p=p->next){
		for(NODE *q=p->next;q!=NULL;q=q->next){
			if(p->value>q->value){
				temp=p->value;
				p->value=q->value;
				q->value=temp;
			}
		}
	}
}
//-------------------------
void addManyAscending(LIST &ds, int a[], int n){
	int i;
	for(i=0;i<n;i++){
		insertAscending(ds,a[i]);
	}	
}
//-------------------------
void addMany(LIST &ds, int a[], int n){
	int i;
	for(i=0;i<n;i++){
		insertLast(ds,createNode(a[i]));
	}	
}
//-------------------------
int main(){
	int a[]={9, 5, 1, 3, 7};
	LIST ds;
	initList(ds);
	//addManyAscending(ds,a,5);
	addMany(ds,a,5);
	showList(ds);
	insertAscending(ds,4);
	showList(ds);
}

