/*
Kiem tra Thuc hanh CTDL GT
--- Thoi gian: 90 phut
--- SV duoc phep: 
     + Tham khao tai lieu giay, www,... 
     + Thuc hien cac cau khong theo thu tu 1 2 3 (Cau 1 phai lam truoc tien)
--- SV khong duoc phep: trao doi thong tin 

Cho code ban dau nhu sau: DSLK DSSV co moi node gom id (MSSV gom 5 so) va name,
va cac ham:
+ Them vao dau DSLK
+ Luu DSLK vao file
+ Doc DSLK tu file

SV hay bo sung cac chuc nang can co de quan ly DSSV nhu sau: (moi cau 1d; toi da 7d)
1. Bo sung cac thong tin cua SV trong DSSV: them d1, d2, d3 (d1, d2, d3 diem cac mon hoc 1 2 3, dang so nguyen, tu 0 den 100)
2. Cai tien ham displayLinkedList: them hang tieu de (STT     MSSV      Ho va ten  D1  D2  D3  DTB)
3. Bo sung ham Nhap thong tin 1 SV tu ban phim (Noi dung nhap gom: MSSV, Ho va ten, D1, D2, D3)
4. Bo sung ham Xuat thong tin SV co diem TB >=50
5. Bo sung ham Xuat thong tin SV co id la X (X nhap tu ban phim), luu thanh file "TTSV_X.txt"
6. Bo sung ham Them SV Y sau SV co id la X (X, Y nhap tu ban phim)
7. Bo sung ham Xoa SV co id la X (X nhap tu ban phim)

Diem cong:
8. Bo sung ham Sap xep DSSV theo id giam dan
9. Bo sung ham Sap xep DSSV theo dtb tang dan
10. Bo sung ham Xuat ra DSSV co diem TB cao nhat cua moi mon hoc
(Vi du: 
+ Mon d1 diem cao nhat la 9; Mon d2 diem cao nhat la 8; Mon d3 diem cao nhat la 7; 
thi xuat ra DSSV co (sv->d1==MaxD1||sv->d2==MaxD2||sv->d3==MaxD3)
)
*/

/*
Thong tin SV thuc hien
	Name: 
	Copyright: 
	Author: 
	Date: 
	Description: 
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct node {
  unsigned int id;
  char name[100];
  int d1, d2, d3;
  struct node * next;
};

// Xuat DSLK ra man hinh
void displayLinkedList(struct node * root) {
  struct node * temp = root;
  printf("\nDSSV hien tai: ");
  printf("\nSTT            Ho va Ten    Dien1    diem2     Diem3");
  int i=1;
  while (temp != NULL) {
    printf("\n ->%d  \t%d  \t%s  \t%d  \t%d  \t%d",i++, temp -> id, temp -> name, temp->d1, temp->d2, temp->d3);
    temp = temp -> next;
  }
  printf("\n -> NULL\n\n");
}

// Chen node moi vao dau DSLK
struct node * insertFirst(node * head, int id, char * name, int d1, int d2, int d3) {
  struct node * ptr;
  struct node * temp = (struct node * ) malloc(sizeof(struct node));
  temp -> id = id;
  temp->d1 = d1;
  temp->d2 = d2;
  temp->d3 = d3;
  strcpy(temp -> name, name);
  temp -> next = NULL;

  if (head == NULL) {
    head = temp;
  } else {
    temp -> next = head;
    head = temp;
  }
  return head;
}

// Ghi DSLK vao file
void writeLinkedList(char filename[], node * head) {
  struct node * temp = head;
  FILE * file;
  file = fopen(filename, "wb");
  if (file == NULL) {
    fprintf(stderr, "\nKhong the doc ghi file'\n");
    exit(1);
  }

// Ghi all node cua DSLK vao file
  while (temp != NULL) {
    fwrite(temp, sizeof(struct node), 1, file);
    temp = temp -> next;
  }
  if (fwrite != 0) {
    printf("DSSV duoc luu thanh cong!!!\n");
  } else {
    printf("Loi ghi file\n");
  }
  fclose(file);
}

// Doc DSLK tu file
struct node * readLinkedListFromFile(char filename[]) {

  struct node * temp = (struct node * ) malloc(sizeof(struct node));;
  struct node * head; // Tro den node dau tien cua DSLK trong file
  struct node * last; // Tro den node cuoi cung cua DSLK trong file
  last = head = NULL;

  FILE * file;
  file = fopen(filename, "rb");
  if (file == NULL) {
    fprintf(stderr, "\nKhong the doc file'\n");
    exit(1);
  }

  // doc node tu dau file, theo dung cach no duoc luu
  while (fread(temp, sizeof(struct node), 1, file)) {
    if (head == NULL) {
      head = last = (struct node * ) malloc(sizeof(struct node));
    } else {
      last -> next = (struct node * ) malloc(sizeof(struct node));
      last = last -> next;
    }
    last -> id = temp -> id;
    strcpy(last -> name, temp -> name);
    last->d1 = temp->d1;
    last->d2 = temp->d2;
    last->d3 = temp->d3;
    last -> next = NULL;
  }
  fclose(file);
  return head;
}

void nhap1Sv(struct node* &sv) {
//	struct node * sv = new node;
//	struct node * sv2 = new node;
	printf("nhap id:");
	scanf("%d", &sv->id);
	printf("nhap ho va ten: ");fflush(stdin);
	gets(sv->name);
	printf("nhap d1:");fflush(stdin);
	scanf("%d", &sv->d1);
	printf("nhap d2:");
	scanf("%d", &sv->d2);
	printf("nhap d3:");
	scanf("%d", &sv->d3);
//	insertFirst(sv2,sv->id, "heheh",23,44,55);
//	return sv2;
}

// ham xuat sinh vien dtb> 50

void xuatDTBLon5(struct node* head) {
	if(head!=NULL) {
		struct node* node = head;
		printf("xuat cac sinh vien dtb > 50:");
		while(node!=NULL) {
			float tong;
			tong = node->d1+node->d2+node->d3;
			if(tong/3>50){
				printf("\n -> %d   %s   %d    %d   %d", node -> id, node -> name, node->d1, node->d2, node->d3);
			}
			node=node->next;
		}
	}
}

//5. Bo sung ham Xuat thong tin SV co id la X (X nhap tu ban phim), luu thanh file "TTSV_X.txt"

void xuatIDX(struct node* head, int x) {
	if(head!=NULL) {
		struct node* node = head;
		printf("xuat sinh vien %s: ", x);
		while(node!=NULL) {
			
			if(x==node->id){
				writeLinkedList("TTSV_X.txt", node);
				printf("\n -> %d   %s   %d    %d   %d", node -> id, node -> name, node->d1, node->d2, node->d3);
				break;
			}
			node=node->next;
		}
		return;
	}
}

//6. Bo sung ham Them SV Y sau SV co id la X (X, Y nhap tu ban phim)

int AddAfterX(struct node* head, int x, struct node* y)
{
	if(head != NULL) {
		struct node* node =head;
		
		while(x!=node->id) {
			node=node->next;
		}
			y->next = node->next;
			node->next = y;
			return 1;
	}
		
		return 0;
}
//7. Bo sung ham Xoa SV co id la X (X nhap tu ban phim)
void RemoveX (struct node* head, int x) {
	if(head != NULL) {
		struct node* node = head;
		if(x==head->id){
			head = node->next;
			delete node;
			return;
		}
		while(node->next!= NULL) {
			if(x==node->next->id) {
				struct node* node2 = node->next;
				struct node* node3 = node2->next;
				node->next= node3;
				delete node2;
				return;
			}
			node=node->next;
		}
	}
}



int main() {
  struct node * head = NULL;
  struct node * sv = new node;
  head = insertFirst(head, 90101, "Vo Binh An", 66,277,88);
  head = insertFirst(head, 90102, "Truong An Binh", 4,5,6);
  head = insertFirst(head, 90103, "Nguyen Minh Chien",78,88,98);
  head = insertFirst(head, 90104, "Ngo Thi Dung",78,58,48);

//  printf("\nDSSV hien tai:\n");
  displayLinkedList(head);
  writeLinkedList("DSSV.txt", head);

  printf("\nDang doc DSSV tu file!!\n");
  struct node * newHead = readLinkedListFromFile("DSSV.txt");
//  printf("\nDSSV hien tai:\n");
  displayLinkedList(newHead);
//    printf("\nnhap 1 sinh vien:\n");
//	nhap1Sv(sv);
//	printf("sinh vien vua nhap");
//	printf("\n -> %d   %s   %d    %d   %d", sv -> id, sv -> name, sv->d1, sv->d2, sv->d3);
  	xuatDTBLon5(newHead);
  	int x;
  	printf("\nnhap id muon tim:");
  	scanf("%d", &x);
  	xuatIDX(newHead, x);
  	printf("\nban muon them vao sau id sinh vien nao:");
  	scanf("%d", &x);
  	printf("\nnhap 1 sinh vien muon them:\n");
	nhap1Sv(sv);
  	AddAfterX(newHead,x,sv);
  	displayLinkedList(newHead);
  	printf("\nnhap id muon xoa:");
  	scanf("%d", &x);
  	RemoveX(newHead,x);
  	displayLinkedList(newHead);
}
