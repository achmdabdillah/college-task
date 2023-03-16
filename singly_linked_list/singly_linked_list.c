#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// TODO validate length of Employee Data
// check if id is already exist or not

bool searchById();
void deleteById();
void deleteList();
void insertStart();
void insertTail();
void printList();
void SortLinkedList();
void printErr();
struct Employee createEmployee();

struct Employee
{
  int employeeId;
  char nama[30];
  char tempatLahir[30];
  char tanggalLahir[30];
  char jabatan[50];
};

struct Node
{
  struct Employee employee;
  struct Node *next;
};

int main ()
{
  struct Node *head = NULL;
  
  bool quit = false;
  int menuNo;

  do {
      printf("============================\n");
      printf("PROGRAM DATA KARYAWAN\n");
      printf("\n");
      printf("Pilihan Menu: \n");
      printf("1. Input data Karyawan\n");
      printf("2. Tampilkan seluruh data\n");
      printf("3. Hapus data berdasarkan ID\n");
      printf("4. Hapus seluruh data\n");
      printf("5. Exit\n");
      printf("Pilihan Anda: ");
      scanf("%d", &menuNo);
      while ((getchar()) != '\n');
      
      if(menuNo == 1) {
        struct Employee emp = createEmployee();
        insertTail (&head, emp);
      }
      else if (menuNo == 2) {
        printf("\n-----------------------------------------");
        printf("\n              DATA KARYAWAN              ");
        printf("\n=========================================\n");
        SortLinkedList(head);
        printList(head);
      }
      else if(menuNo == 3){
        int id;
        printf("Masukkan ID Karyawan : \n");
        scanf("%d", &id);
        while ((getchar()) != '\n');
        deleteById(&head, id);
      }
      else if(menuNo == 4){
        deleteList(&head);
      }
      else if(menuNo == 5){
        quit = true;
      }
  } while (quit != true);
  return 0;
}

void insertStart (struct Node **head, struct Employee employeeData){

  struct Node *newNode = (struct Node *) malloc (sizeof (struct Node));

  newNode->employee = employeeData;
  newNode->next = *head;

  *head = newNode;
  printf ("\nData berhasil dimasukkan\n");
}

void insertTail(struct Node** head, struct Employee employeeData)
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    struct Node *last = *head;
   
    newNode->employee  = employeeData;
  
    newNode->next = NULL;
  
    if (*head == NULL)
    {
       *head = newNode;
       return;
    }  
       
    while (last->next != NULL)
        last = last->next;
   
    last->next = newNode;
    return;    
}

void SortLinkedList(struct Node *head)
    {
    struct Node *node=NULL, *temp = NULL;
    struct Employee tempvar;
    node = head;
    while(node != NULL)
    {
        temp=node; 
        while (temp->next !=NULL)
        {
           if(temp->employee.employeeId > temp->employee.employeeId)
            {
              tempvar = temp->employee;
              temp->employee = temp->next->employee;
              temp->next->employee = tempvar;
            }
         temp = temp->next;
        }
        node = node->next;
    }
}

void printStruct(struct Node *node) {
  printf("Employee ID : %d\n", node->employee.employeeId);
  printf("Name : %s", node->employee.nama);
  printf("Tempat Lahir : %s", node->employee.tempatLahir);
  printf("Tanggal Lahir : %s", node->employee.tanggalLahir);
  printf("Jabatan : %s", node->employee.jabatan);
  printf("-----------------------------------------\n");
}

void printList (struct Node *node) {
  if(node == NULL) {
    printErr("Tidak ada data untuk ditampilkan\n");
    return;
  }

  while (node != NULL)
    {
      printStruct(node);
      node = node->next;
    }
  printf ("\n");
}

bool validateEmployeeId(char id[]) {
  int length = strlen(id) - 1;
  if(length > 0 && length <= 5){
    return true;
  } else {
    printErr("Input salah! tolong masukkan angka dari 1-5\n");
    return false;
  }
}

struct Employee createEmployee () {
  char nama[30], tempatLahir[30], tanggalLahir[30], jabatan[50], employeeId[10];
  
  bool isIdValid = false;
  
  struct Employee employee;
  
  do {
      printf("Input Employee Id : \n");
      fgets(employeeId, 10, stdin);
      isIdValid = validateEmployeeId(employeeId);
  } while (!isIdValid);

  printf("Input nama : \n");
  fgets(nama, 30, stdin);
  
  printf("Input Tempat Lahir : \n");
  fgets(tempatLahir, 30, stdin);

  printf("Input Tanggal Lahir : \n");
  fgets(tanggalLahir, 30, stdin);
  
  printf("Input jabatan : \n");
  fgets(jabatan, 50, stdin);

  employee.employeeId = atoi(employeeId);
  strcpy(employee.nama, nama);
  strcpy(employee.tempatLahir, tempatLahir);
  strcpy(employee.tanggalLahir, tanggalLahir);
  strcpy(employee.jabatan, jabatan); 

  return employee;
} 

bool searchById(struct Node* head, int x) {
  struct Node* current = head;
  while (current != NULL) {
    if (current->employee.employeeId == x){
      return true;
    }
    current = current->next;
  }
  return false;
}

void deleteById(struct Node** head, int employeeId) {
  struct Node *temp = *head, *prev;

  if (temp != NULL && temp->employee.employeeId == employeeId) {
      *head = temp->next;
      free(temp);
      return;
  }

  while (temp != NULL && temp->employee.employeeId != employeeId) {
      prev = temp;
      temp = temp->next;
  }

  if (temp == NULL)
      return;

  prev->next = temp->next;

  free(temp);
}

void deleteList (struct Node **head) {
  struct Node *temp;

  while (*head != NULL)
    {
      temp = *head;
      *head = (*head)->next;

      printf ("\nData dengan ID %d telah dihapus\n", temp->employee.employeeId);
      free (temp);
    }
  return;

}

void printErr (char errMsg[]) {
  printf("\033[1;31m");
  printf("%s\n", errMsg);
  printf("\033[0m");
}