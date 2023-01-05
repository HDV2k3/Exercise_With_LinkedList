#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
// tao cau truc cong viec
typedef struct CongViec {

	char TenCviec[31]; // ten cong viec
	int ThoiHan; // thoi han deadline
	int LoiNhuan; // loi nhuan sau khi hoan thanh cong viec 
			
} CV;


// Tim gia tri nho nhat giua hai so
int min(int num1, int num2)
{
	return (num1 > num2) ? num2 : num1; // toan tu neu num1>num2 thi ta se tra ve gia tri tu phai sang trai
}

//tra ve loi nhuan toi da cho cong viec da lam
void SapXepLoiNhuanGiamDan(CV arr[],int n)
{
	 for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i].LoiNhuan < arr[j].LoiNhuan){
                // Hoan vi 2 so arr[i] va arr[j]
               CV tam = arr[i];
                arr[i] = arr[j];
                arr[j] = tam;        
            }
        }
    }
}

void LichThucHienCv(CV arr[], int n)
{
	// sap xep tat ca cac cong viec theo thu tu co loi nhuan giam dan
		SapXepLoiNhuanGiamDan(arr,n);
	int result[n]; 
	bool slot[n]; 
	for (int i = 0; i < n; i++)
	{
		slot[i] = false;
	}
	for (int i = 0; i < n; i++) {
		for (int j = min(n,arr[i].ThoiHan) - 1; j >= 0; j--) {
		
			if (slot[j] == false) {
				result[j] = i; 	
				slot[j] = true; 
				break;
			}
		}
	}
	// in ra ket qua
	for (int i = 0; i < n; i++)
		if (slot[i])
			printf("%s ", arr[result[i]].TenCviec);
}
void NhapTT1Cv(CV &x)
{
	int i;
	printf("\n Nhap ten cong viec thu %d can dung den thuat toan :",i++);
//	scanf("%s",&x.TenCviec); fflush(stdin);
	fflush(stdin);
	gets(x.TenCviec);
	printf("\n Nhap thoi han cua cong viec :");
	scanf("%d",&x.ThoiHan);
	printf("\n Nhap loi nhuan :");
	scanf("%d",&x.LoiNhuan);
	
}
void XuatTt(CV x)
{
	printf("-> Cong Viec:%s \t            \tThoi Han:%d \t  Loi Nhuan:%d \n ",x.TenCviec,x.ThoiHan,x.LoiNhuan);
}
void NhapSL(int &n)
{
	do{
		printf("Nhap so cong viec can chon de tinh loi nhuan :");
		scanf("%d",&n);
	}while(n<0||n>MAX);
	
}


void NhapMang(CV arr[], int n){
    for(int i = 0; i < n; i++)
	{
        NhapTT1Cv(arr[i]);
    }
}
void XuatMang(CV arr[], int n){
    for(int i = 0; i < n; i++){
       XuatTt(arr[i]);
    }
}

int main()
{
	CV arr [MAX];
	int n;
	NhapSL(n);
	NhapMang(arr,n);
	XuatMang(arr,n);
	printf("sau day la nhung co viec co loi nhuan toi da \t  \n");

	// goi ham thuc hien 
	LichThucHienCv(arr,n);
	return 0;
}
