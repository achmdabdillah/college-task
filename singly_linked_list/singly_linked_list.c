#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool searchById();
void deleteById();
void deleteList();
void insertStart();
void insertTail();
void printList();
void SortLinkedList();
void printErr();
int getCount();
struct Employee createEmployee();

struct Employee
{
  char employeeId[10];
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
        int count = getCount(head);
        if(count >= 5){
          printErr("Maksimal data yang dapat dinput adalah 5, Silakan Hapus data terlebih dahulu");
        } else {
          struct Employee emp = createEmployee(head);
          insertTail (&head, emp);
        }
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

bool validateLength (char type[], char data[]) {
  int maxLen = 0;
  int dataLen = strlen(data) - 1;

  if(strcmp(type, "id") == 0){
    maxLen = 5;
  }

  if(strcmp(type, "nama") == 0){
    maxLen = 30;
  }

  if(strcmp(type, "tempat lahir") == 0){
    maxLen = 30;
  }

  if(strcmp(type, "jabatan") == 0){
    maxLen = 50;
  }

  if(dataLen > maxLen){
    printf("\033[1;31m");
    printf("Input %s maksimal %d karakter!\n", type, maxLen);
    printf("\033[0m");
    return false;
  } 
  return true;

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
           if(atoi(temp->employee.employeeId) > atoi(temp->next->employee.employeeId))
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
  printf("Employee ID : %s", node->employee.employeeId);
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


struct Employee createEmployee (struct Node * head) {
  char nama[80], tempatLahir[80], tanggalLahir[80], jabatan[100], employeeId[10];
  
  bool isIdValid, isNamaValid, isTempatLahirValid, isJabatanValid = false;
  
  struct Employee employee;
  
  do {
      printf("Input Employee Id : \n");
      fgets(employeeId, 10, stdin);
      isIdValid = validateLength("id", employeeId);

      if(searchById(head, employeeId)){
        printErr("ID Sudah digunakan, Silakan gunakan ID lain");
        isIdValid = false;
      };
  } while (!isIdValid);

  do {
      printf("Input nama : \n");
      fgets(nama, 80, stdin);
      isNamaValid = validateLength("nama", nama);
  } while (!isNamaValid);

  do {
      printf("Input Tempat Lahir : \n");
      fgets(tempatLahir, 80, stdin);
      isTempatLahirValid = validateLength("tempat lahir", tempatLahir);
  } while (!isTempatLahirValid);

  printf("Input Tanggal Lahir : \n");
  fgets(tanggalLahir, 80, stdin);
  
  do {
      printf("Input jabatan : \n");
      fgets(jabatan, 100, stdin);
      isJabatanValid = validateLength("jabatan", jabatan);
  } while (!isJabatanValid);

  strcpy(employee.employeeId, employeeId);
  strcpy(employee.nama, nama);
  strcpy(employee.tempatLahir, tempatLahir);
  strcpy(employee.tanggalLahir, tanggalLahir);
  strcpy(employee.jabatan, jabatan); 

  return employee;
} 

bool searchById(struct Node* head, char id[]) {
  struct Node* current = head;
  while (current != NULL) {
    if (strcmp(current->employee.employeeId, id) == 0){
      return true;
    }
    current = current->next;
  }
  return false;
}

void deleteById(struct Node** head, char employeeId[]) {
  struct Node *temp = *head, *prev;

  if (temp != NULL && strcmp(temp->employee.employeeId, employeeId) == 0) {
      *head = temp->next;
      free(temp);
      return;
  }

  while (temp != NULL && strcmp(temp->employee.employeeId, employeeId) != 0) {
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

      printf ("\nData dengan ID %s telah dihapus\n", temp->employee.employeeId);
      free (temp);
    }
  return;

}
int getCount(struct Node* head) {
    int count = 0; // Initialize count
    struct Node* current = head; // Initialize current
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void printErr (char errMsg[]) {
  printf("\033[1;31m");
  printf("%s\n", errMsg);
  printf("\033[0m");
}