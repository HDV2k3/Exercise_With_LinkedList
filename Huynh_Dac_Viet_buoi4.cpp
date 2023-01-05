#include"stdio.h"
#include <conio.h>
#include <math.h>
#include <string.h>
#include <malloc.h>
//dinh nghi benh nhan
typedef struct BENHNHAN
{
int stt;
char hoten[41];
int tuoi;
}Data;
//dinh nghia quan ly con tro queue
typedef struct node{
Data info;
struct node* next;
}Node;
typedef Node* QUEUE;

void Init(QUEUE &Q){
Q=NULL;
}
//kiem tra queue rong
int IsEmpty(QUEUE Q){
return(Q==NULL);
}
//khoi tao node
QUEUE createNode(Data x){
QUEUE p=new Node;
p->info=x;
p->next=NULL;
return p;
}
//them vao  queue
int InSert(QUEUE &Q,Data x){
QUEUE p=createNode(x);
if(p==NULL) return 0;
if(IsEmpty(Q)){
Q=p;
}else{
QUEUE i=Q;
while(i->next!=NULL){
i=i->next;
}
i->next=p;
return 1;
}
}
//xoa
int Remove(QUEUE &Q,Data &x){
Node *p=Q;
if(p==NULL) return 0;
if(IsEmpty(Q)){
printf("danh Sach rong\n");
}else{
Q=p->next;
x=p->info;
delete p;
return 1;
}
}
//nhap thong tin benh nhan
void Nhap1Bn(BENHNHAN &x)
{
printf("Nhap Ho va ten: ");
fflush(stdin); gets(x.hoten);
printf("Nhap tuoi: ");
scanf("%d",&x.tuoi);
}




void Xuat1Bn(BENHNHAN x)
{
printf("\nSTT:%d\tHo_va_ten:%s\tTuoi:%d", x.stt, x.hoten, x.tuoi);
}

void output(QUEUE Q){
if(IsEmpty(Q)){
printf("\nDanh Sach Rong");
}else{
for(QUEUE i=Q;i!=NULL;i=i->next){
Xuat1Bn(i->info);
}
}
}
//danh sach cac muc
void menu(int &chon)
{
printf("\n\n\t\tMENU\n");
printf("1- THEM 1 BENH NHAN\n");
printf("2- GOI BENH NHAN TIEP THEO SE KHAM\n");
printf("3- CHO BIET SO LUONG NGUOI DA KHAM\n");
printf("4- CHO BIET SO LUONG NGUOI CHUA KHAM\n");
printf("5- DANH SACH BENH NHAN CHO KHAM\n");
printf("0- Thoat\n");
printf("chon : ");
scanf("%d", &chon);
}
int main()
{
QUEUE Q;
Data x;
Init(Q);
int chon, STT=0,So_nguoi_da_kham=0;
do
{
menu(chon);
switch(chon)
{
case 1:
printf("\n\n\t\t======== THEM 1 BENH NHAN VAO QUEUE ===========\n\n");
Nhap1Bn(x);
x.stt=++STT;
InSert(Q,x);
break;
case 2:
printf("\n\n\t\t======== LAY BENH NHAN TIEP THEO SE KHAM ===========\n\n");
if(Remove(Q,x)==0){
printf("\nDanh Sach Rong");
}else{
Xuat1Bn(x);
So_nguoi_da_kham++;
}
break;
case 3:
printf("\n\n\t\t======== CHO BIET SO LUONG NGUOI DA KHAM   : ");
printf("%d",So_nguoi_da_kham);
break;
case 4:
printf("\n\n\t\t======== CHO BIET SO LUONG NGUOI CHUA KHAM : ");
printf("%d",STT-So_nguoi_da_kham);
break;
case 5:
printf("\n\n\t\t======== DANH SACH BENH NHAN CHO KHAM ===========\n\n");
output(Q);
break;
default: chon = 0;
}
}while(chon != 0);
getch();
}

