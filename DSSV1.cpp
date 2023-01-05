#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Ngay{
	int ngay, thang, nam;
};

struct SinhVien{
	int MaSV;
	char HoTen[50];
	int GioiTinh;
	Ngay NgaySinh;
	char DiaChi[100];
	char Lop[12];
	char Khoa[7];
};

struct Node{
	SinhVien data;
	Node *next;
};

struct List{
	Node *First, *Last;
};

void init(List &l){
	l.First=l.Last=NULL;
}

Node *getNode(SinhVien x){
	Node *p=new Node;
	if(p==NULL)
	{
		return NULL;
	}
	p->data=x;
	p->next=NULL;
	return p;
}

void TimMaSV(List l){
	Node *p;
	int n;
	int count=0;
	printf("\nNhap MaSV can tim:");
	scanf("%d",&n);
	p=l.First;
	while ((p!=NULL))	
		{
		if (strcmp(n,p->data.MaSV)==0)
		count++;
		p=p->next;
		}	
	if(count!=0)
	{
		printf("\nDa tim thay!");
		XuatDSSV(p->data);
	}
	else 
	{
		printf("\nkhong tim thay sinh vien:");
	}
	
}

void addLast(List &l, Node *new_ele){
	if(l.First==NULL)
		l.First=l.Last=new_ele;
	else{
		l.Last->next=new_ele;
		l.Last=new_ele;
	}
}

void inserLast(List &l, SinhVien x){
	Node *new_ele=getNode(x);
	if(new_ele!=NULL)
		addLast(l,new_ele);
}

void NhapSV(List &l, int n){
	SinhVien x;
	printf("\nNhap MaSV:");fflush(stdin);
	scanf("%d",&x.MaSV);
	printf("Ho va ten: ");fflush(stdin);
	gets(x.HoTen);
	printf("Gioi tinh(NAM/Nu): ");
	gets(gt);
	if(strcmp(strupr(gt),"NAM")==0)
	{
		x.GioiTinh=0;
	}
	else
		{
			x.GioiTinh=1;
		}
	printf("Ngay thang nam sinh: ");
	scanf("%d/%d/%d",&x.NgaySinh.ngay,&x.NgaySinh.thang,&x.NgaySinh.nam);
	printf("Dia chi: ");
	fflush(stdin);
	gets(x.DiaChi);
	printf("Lop: ");
	gets(x.Lop);fflush(stdin);
	printf("Khoa: ");fflush(stdin);
	gets(x.Khoa);
	printf("\n ");
}

void NhapDSSV(List &l){
	printf("Bat dau nhap danh sach sinh vien(Nhap MaSV=0 de dung): \n");
	SinhVien x;
	while(NhapSV(l,x));
		inserLast(l,x);
	printf("\n Ket thuc viec nhap DSSV\n");
}

void XuatSV(SinhVien x){
	char gt[4],ns[22],tam[10];
	if(x.GioiTinh==0)
		{
			strcpy(gt,"NAM");
		}
	else
		{
			strcpy(gt,"Nu");
		}
	itoa(x.NgaySinh.ngay,tam,10);
	strcpy(ns,tam);
	itoa(x.NgaySinh.thang,tam,10);
	strcat(ns,"/");
	strcpy(ns,tam);
	itoa(x.NgaySinh.nam,tam,10);
	strcat(ns,"/");
	strcpy(ns,tam);
	printf("%-10s %-20s %-15s %-15s %-25s %-15s %-8s \n",
		x.MaSV,x.HoTen,gt,ns,x.DiaChi,x.Lop,x.Khoa);
}

void intieude(){
	printf("%-10s %-20s %-15s %-15s %-25s %-15s %-8s \n",
		"MaSV","Ho va ten","Gioi Tinh","NgaySinh","Dia Chi","Lop","Khoa");
	for(int i=1; i<=111; i++)
		printf("-");
	printf("\n");
}

void XuatDSSV(List l){
	intieude();
	for(Node *p=l.First;p!=NULL;p=p->next)
	{
		XuatSV(p->data);
	}
}

int main(){
	List l;
	int n;
	printf("Nhap n sinh vien:");
	scanf("%d",&n);
	init(l);
	getNode(l);
	NhapDSSV(l);
	XuatDSSV(l);
	TimMaSV(l);

}
























