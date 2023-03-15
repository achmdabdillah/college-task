#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// TODO create menu that contains following option: 'Insert', 'Show All Data', 'Delete data by id', 'Delete all Data', 'Quit' 
// TODO sort data based on Employee ID
// TODO validate length of Employee Data
// TODO create table to show all data

bool searchById();
void deleteById();
void deleteList();
void insertStart();
void insertTail();
void display();
struct Employee createEmployee();

struct Employee
{
  int employeeId;
  char nama[30];
  char ttl[30];
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
  
  int maxData = 2;

  bool quit = false;
  int inp;
  do {
  struct Employee emp = createEmployee();
    
    // Need '&' i.e. address as we need to change head
    insertTail (&head, emp);
    printf("quit ?\n");
    scanf("%d",&inp);
    while ((getchar()) != '\n');
    quit = (inp == 1);
  } while(!quit);
    
  display(head);

  searchById(head, 1);

  deleteById(&head, 2);

  display(head);

  deleteList(&head);

  display(head);
  return 0;
}

void insertStart (struct Node **head, struct Employee employeeData)
{

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

void display (struct Node *node)
{
  if(node == NULL) {
    printf("LINKED LIST IS EMPTY!");
    return;
  }

  // as linked list will end when Node is Null
  while (node != NULL)
    {
      printf("----------------\n");
      printf ("Employee ID:%d\n", node->employee.employeeId);
      printf ("Name %s\n", node->employee.nama);
      printf ("TTL %s\n", node->employee.ttl);
      printf ("Jabatan %s\n", node->employee.jabatan);
      printf("----------------\n");
      node = node->next;
    }
  printf ("\n");
}

void printErr (char errMsg[]) {
  printf("\033[1;31m");
  printf("%s\n", errMsg);
  printf("\033[0m");
}

bool validateEmployeeId(int id) {
  if(id >= 1 && id <= 5){
    return true;
  } else {
    printErr("Input salah! tolong masukkan angka dari 1-5\n");
    return false;
  }
}

struct Employee createEmployee () {
  char nama[30], ttl[30], jabatan[50], employeeId[5];
  
  bool isIdValid = false;
  
  struct Employee employee;
  
  // input employee data
  do {
      printf("Input Employee Id : \n");
      fgets(employeeId, 5, stdin);
      isIdValid = validateEmployeeId(atoi(employeeId));
  } while (!isIdValid);

  printf("Input nama : \n");
  fgets(nama, 30, stdin);
  
  printf("Input TTL : \n");
  fgets(ttl, 30, stdin);
  
  printf("Input jabatan : \n");
  fgets(jabatan, 50, stdin);

  /* Employee specification */
  employee.employeeId = atoi(employeeId);
  strcpy(employee.nama, nama);
  strcpy(employee.ttl, ttl);
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

      free (temp);
      printf ("\n%d deleted\n", temp->employee.employeeId);
    }
  return;

}
