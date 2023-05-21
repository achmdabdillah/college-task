#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
int size = 0;
// todo create menu option for: 
// 1. insert data
// 2. delete priority
// 3. sort by

struct Data
{
  int skalaPerbaikan;
  char nama[20];
  char merk[20];
};


// todo get input for object data
struct Data getData () {
  int skalaPerbaikan;
  char nama[50], merk[50];
  
  struct Data data;
  
  printf("Input Skala Perbaikan : \n");
  scanf("%d",  &skalaPerbaikan);

  printf("Input Nama Pemilik : \n");
  fgets(nama, 20, stdin);

  printf("Input Merk Motor : \n");
  fgets(merk, 20, stdin);

  data.skalaPerbaikan = skalaPerbaikan;
  strcpy(data.nama, nama);
  strcpy(data.merk, merk);

  return data;
} 

void swap(struct Data **A, struct Data **B){
    struct Data *temp = *A;
    *A = *B;
    *B = temp;
}
 
// Function to heapify the tree
void heapify(struct Data *array[], int size, int i) {
  if (size == 1) {
    // printf("Single element in the heap");
  } else {
    
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && array[l]->skalaPerbaikan < array[smallest]->skalaPerbaikan)
      smallest = l;
    if (r < size && array[r]->skalaPerbaikan < array[smallest]->skalaPerbaikan)
      smallest = r;

    
    if (smallest != i) {
      swap(&array[i], &array[smallest]);
      heapify(array, size, smallest);
    }
  }
}


void insert(struct Data *array[], struct Data *newData) {
  if (size == 0) {
    array[0] = newData;
    size += 1;
  } else {
    array[size] = newData;
    size += 1;
    for (int i = size / 2 - 1; i >= 0; i--) {
      heapify(array, size, i);
    }
  }
}


void deleteRoot(struct Data *array[], int num) {
  int i;
  for (i = 0; i < size; i++) {
      break;
  }

  swap(&array[i], &array[size - 1]);
  size -= 1;
  for (int i = size / 2 - 1; i >= 0; i--) {
    heapify(array, size, i);
  }
}


void printArray(struct Data *array[], int size) {
  for (int i = 0; i < size; ++i){
    printf("%10d | ", array[i]->skalaPerbaikan);
    printf("%10s |", array[i]->nama);
    printf("%10s |", array[i]->merk);
    printf("\n");
  }
}

void heapSort(struct Data *arr[], int n) {
  int i, j;
  struct Data *temp; 
  for(i=0; i<n; i++)
  {
      for(j = i+1; j<n; j++) {
            if(arr[i]->skalaPerbaikan > arr[j]->skalaPerbaikan) {
              temp = arr[i];
              arr[i] = arr[j];
              arr[j] = temp;
          }
      }
  }
}

void buildHeap(struct Data *arr[], int N)
{
    int startIdx = (N / 2) - 1;
 
    for (int i = startIdx; i >= 0; i--) {
        heapify(arr, N, i);
    }
}
 

int main() {
  struct Data *array[10];

  struct Data a1 = { skalaPerbaikan: 2, nama: "adi", merk: "ADV" };
  struct Data a2 = { skalaPerbaikan: 1, nama: "achmad", merk: "ADV" };
  struct Data a3 = { skalaPerbaikan: 4, nama: "abdil", merk: "ADV" };
  struct Data a4 = { skalaPerbaikan: 5, nama: "yuhu", merk: "ADV" };
  struct Data a5 = { skalaPerbaikan: 3, nama: "testing", merk: "ADV" };
//   struct Data a6 = { skalaPerbaikan: 23, nama: "testing", merk: "ADV" };
//   struct Data a7 = { skalaPerbaikan: 13, nama: "testing", merk: "ADV" };
//   struct Data a8 = { skalaPerbaikan: 53, nama: "testing", merk: "ADV" };

  insert(array, &a1);
  insert(array, &a2);
  insert(array, &a3);
  insert(array, &a4);
  insert(array, &a5);
//   insert(array, &a6);
//   insert(array, &a7);
//   insert(array, &a8);

  printf("Min-Heap array: \n");
  printArray(array, size);
  
  deleteRoot(array, array[0]->skalaPerbaikan);
  deleteRoot(array, array[0]->skalaPerbaikan);
  printf("After delete priority: \n");
  printArray(array, size);


  heapSort(array, size);
  printf("After heap sort: \n");
  printArray(array, size);

//   deleteRoot(array, array[0]->skalaPerbaikan);
//   deleteRoot(array, array[0]->skalaPerbaikan);

  buildHeap(array, size);
  printf("After heapify: \n");
  printArray(array, size);

}