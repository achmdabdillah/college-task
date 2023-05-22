#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
int size = 0;

struct Data
{
  int skalaPerbaikan;
  char nama[20];
  char merk[20];
};


struct Data createData () {
  struct Data data;
  int skalaPerbaikan;
  char nama[100], merk[100];
  
  printf("Input Skala Perbaikan : \n");
  scanf("%d",  &skalaPerbaikan);

  printf("Input Nama Pemilik : \n");
  scanf("%s",  nama);

  printf("Input Merk Motor : \n");
  scanf("%s",  merk);

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
  bool quit = false;
  int menuNo;

  struct Data data1 = { skalaPerbaikan: 2, nama: "adi", merk: "ADV" };
  struct Data data2 = { skalaPerbaikan: 1, nama: "achmad", merk: "ADV" };
  struct Data data3 = { skalaPerbaikan: 4, nama: "abdil", merk: "ADV" };
  struct Data data4 = { skalaPerbaikan: 5, nama: "yuhu", merk: "ADV" };
  struct Data data5 = { skalaPerbaikan: 3, nama: "testing", merk: "ADV" };
  insert(array, &data1);
  insert(array, &data2);
  insert(array, &data3);
  insert(array, &data4);
  insert(array, &data5);

  do {
      printf("==============================\n");
      printf("PROGRAM ANTRIAN PRIORITAS\n\n"); 
      printf("Pilihan Menu: \n");
      printf("1. Insert kedalam antrian\n");
      printf("2. Keluar dari antrian\n");
      printf("3. Lihat antrian berdasarkan skala prioritas\n");
      printf("4. Exit\n");
      printf("Pilihan Anda: ");
      scanf("%d", &menuNo);
      while ((getchar()) != '\n');

      if (menuNo == 1) {
        printf("Insert data: \n");
        struct Data newData = createData();
        insert(array, &newData);
        printArray(array, size);
      } else if (menuNo == 2){
        printf("Motor dengan merk %s milik Bapak/Ibu %s telah selesai diperbaiki: \n",array[0]->merk, array[0]->nama);
        deleteRoot(array, array[0]->skalaPerbaikan);
        printArray(array, size);
      } else if (menuNo == 3){
        printf("Daftar prioritas pengerjaan :\n");
        heapSort(array, size);
        printArray(array, size);
        buildHeap(array, size);
      } else if (menuNo == 4){
        quit = true;
      }
  } while (!quit);
}