#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Ngay{
	int ngay, thang, nam;
};
typedef  struct sinhvien {
   int MaSV;
	char HoTen[50];
	int GioiTinh;
	Ngay NgaySinh;
	char DiaChi[100];
	char Lop[12];
	char Khoa[7];
}SV;

struct node{
    SV data;
    node * next;
};
typedef struct node NODE;
struct list{
    NODE *pHead;
    NODE *pTail;
};
typedef struct list LIST;
void KhoiTao(LIST &ds){
    ds.pHead = NULL;
    ds.pTail = NULL;
}
int IsEmpty(LIST ds){
    if (ds.pHead == NULL){
        return 1;
    }
    return 0;
}
NODE* CreateNode(SV x) {
    NODE *p;
    p = new NODE;
    if (p==NULL) {
        printf ("KHONG DU BO NHO");
        return NULL;
    }
    p->data=x;
    p->next=NULL;
    return p;
}
void AddLast (LIST &ds, NODE *p){
    if (ds.pHead==NULL) {
        ds.pHead=p;
        ds.pTail=p;
    }
    else {
        ds.pTail->next=p;
        ds.pTail=p;
    }
}
void Nhapsv(LIST &ds, int n){
    char gt [4];
    printf("NHAP THONG TIN SINH VIEN\n");
    for(int i = 0; i < n; i++){
        SV x;
       printf("\nNhap MaSV:");fflush(stdin);
	scanf("%d",&x.MaSV);
	printf("Ho va ten: ");fflush(stdin);
	gets(x.HoTen);
	printf("Gioi tinh 1 nu,0 nam: ");
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
        NODE *p = new NODE;
        p = CreateNode(x);
        AddLast(ds,p);
    }
}
void Xuatsv(LIST ds){
    SV x;
    for(NODE *p = ds.pHead; p!= NULL; p=p->next){
       	printf("%-10s %-20s %d/%d/%d %-25s %-15s %-8s  \n",
		x.MaSV,x.HoTen,x.NgaySinh.ngay,x.NgaySinh.ngay,x.NgaySinh.nam,x.DiaChi,x.Lop,x.Khoa);
    }
}



int main(){
    SV x;
    LIST ds;
    int n;
    printf("NHAP N: ");
    scanf("%d",&n);
    CreateNode(ds);
    Nhapsv(ds,n);
    printf("\nDANH SACH SINH VIEN\n");
    Xuatsv(ds);
   
}