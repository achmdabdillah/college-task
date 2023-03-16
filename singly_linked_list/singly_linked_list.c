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
struct Employee createEmployee();

struct Employee
{
  int employeeId;
  char nama[30];
  char tempatLahir[30];
  char tanggalLahir[30];
  char jabatan[50];
};

// Define and Declare Singly Linked List of Struct Employee
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
        // Need '&' i.e. address as we need to change head
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

  // dynamically create memory for this newNode
  struct Node *newNode = (struct Node *) malloc (sizeof (struct Node));

  // assign data value
  newNode->employee = employeeData;
  // change the next node of this newNode to current head of Linked List
  newNode->next = *head;

  //re-assign head to this newNode
  *head = newNode;
  printf ("\n%d Inserted\n", newNode->employee.employeeId);
}

void insertTail(struct Node** head, struct Employee employeeData)
{
    /* 1. allocate node */
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
  
    struct Node *last = *head;  /* used in step 5*/
   
    /* 2. put in the data  */
    newNode->employee  = employeeData;
  
    /* 3. This new node is going to be the last node, so make next 
          of it as NULL*/
    newNode->next = NULL;
  
    /* 4. If the Linked List is empty, then make the new node as head */
    if (*head == NULL)
    {
       *head = newNode;
       return;
    }  
       
    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;
   
    /* 6. Change the next of last node */
    last->next = newNode;
    return;    
}

void SortLinkedList(struct Node *head)
    {
    printf("\nWORKING\n");
    struct Node *node=NULL, *temp = NULL;
    struct Employee tempvar;//temp variable to store node data
    node = head;
    //temp = node;//temp node to hold node data and next link
    while(node != NULL)
    {
        temp=node; 
        while (temp->next !=NULL)//travel till the second last element 
        {
           if(temp->employee.employeeId > temp->employee.employeeId)// compare the data of the nodes 
            {
              tempvar = temp->employee;
              temp->employee = temp->next->employee;// swap the data
              temp->next->employee = tempvar;
            }
         temp = temp->next;    // move to the next element 
        }
        node = node->next;    // move to the next node
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
    printf("Tidak ada data untuk ditampilkan\n");
    return;
  }

  // as linked list will end when Node is Null
  while (node != NULL)
    {
      printStruct(node);
      node = node->next;
    }
  printf ("\n");
}

void printErr (char errMsg[]) {
  printf("\033[1;31m");
  printf("%s\n", errMsg);
  printf("\033[0m");
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
  
  // input employee data
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

  /* Employee specification */
  employee.employeeId = atoi(employeeId);
  strcpy(employee.nama, nama);
  strcpy(employee.tempatLahir, tempatLahir);
  strcpy(employee.tanggalLahir, tanggalLahir);
  strcpy(employee.jabatan, jabatan); 

  return employee;
} 

bool searchById(struct Node* head, int x) {
  struct Node* current = head; // Initialize current
  while (current != NULL) {
    if (current->employee.employeeId == x){
      printf("ADA");
      return true;
    }
    current = current->next;
  }
  printf("ORA ADA");
  return false;
}

void deleteById(struct Node** head, int employeeId) {
  // Store head node
  struct Node *temp = *head, *prev;

  // If head node itself holds the key to be deleted
  if (temp != NULL && temp->employee.employeeId == employeeId) {
      *head = temp->next; // Changed head
      free(temp); // free old head
      return;
  }

  // Search for the key to be deleted, keep track of the
  // previous node as we need to change 'prev->next'
  while (temp != NULL && temp->employee.employeeId != employeeId) {
      prev = temp;
      temp = temp->next;
  }

  // If key was not present in linked list
  if (temp == NULL)
      return;

  // Unlink the node from linked list
  prev->next = temp->next;

  free(temp); // Free memory
}

void deleteList (struct Node **head) {
  struct Node *temp;

  // if there are no nodes in Linked List can't delete
  while (*head != NULL)
    {
      temp = *head;
      // move head to next node
      *head = (*head)->next;

      printf ("\nData dengan ID %d telah dihapus\n", temp->employee.employeeId);
      free (temp);
    }
  return;

}
