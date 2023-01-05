
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
  struct node * next;
};

// Xuat DSLK ra man hinh
void displayLinkedList(struct node * root) {
  struct node * temp = root;
  printf("\nDSSV hien tai: ");
  while (temp != NULL) {
    printf("\n -> %d %s", temp -> id, temp -> name);
    temp = temp -> next;
  }
  printf("\n -> NULL\n\n");
}

// Chen node moi vao dau DSLK
struct node * insertFirst(node * head, int id, char * name) {
  struct node * ptr;
  struct node * temp = (struct node * ) malloc(sizeof(struct node));
  temp -> id = id;
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
  file = fopen(filename, "w");
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
  file = fopen(filename, "r");
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
    last -> next = NULL;
  }
  fclose(file);
  return head;
}

int main() {
  struct node * head = NULL;
  head = insertFirst(head, 90101, "Vo Binh An");
  head = insertFirst(head, 90102, "Truong An Binh");
  head = insertFirst(head, 90103, "Nguyen Minh Chien");
  head = insertFirst(head, 90104, "Ngo Thi Dung");

//  printf("\nDSSV hien tai:\n");
  displayLinkedList(head);
  writeLinkedList("DSSV.txt", head);

  printf("\nDang doc DSSV tu file!!\n");
  struct node * newHead = readLinkedListFromFile("DSSV.txt");
//  printf("\nDSSV hien tai:\n");
  displayLinkedList(newHead);
}
