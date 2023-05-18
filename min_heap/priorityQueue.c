#include <stdio.h>
int size = 0;
void swap(int *a, int *b) {
  int temp = *b;
  *b = *a;
  *a = temp;
}

// todo create object data
// todo get input for object data


// Function to heapify the tree
void heapify(int array[], int size, int i) {
  if (size == 1) {
    printf("Single element in the heap");
  } else {
    
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && array[l] < array[smallest])
      smallest = l;
    if (r < size && array[r] < array[smallest])
      smallest = r;

    
    if (smallest != i) {
      swap(&array[i], &array[smallest]);
      heapify(array, size, smallest);
    }
  }
}


void insert(int array[], int newNum) {
  if (size == 0) {
    array[0] = newNum;
    size += 1;
  } else {
    array[size] = newNum;
    size += 1;
    for (int i = size / 2 - 1; i >= 0; i--) {
      heapify(array, size, i);
    }
  }
}


void deleteRoot(int array[], int num) {
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


void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i)
    printf("%d ", array[i]);
  printf("\n");
}


int main() {
  int array[10];

  insert(array, 3);
  insert(array, 4);
  insert(array, 9);
  insert(array, 5);
  insert(array, 2);
  insert(array, 1);
  insert(array, 20);

  printf("Min-Heap array: ");
  printArray(array, size);

  deleteRoot(array, array[0]);
  deleteRoot(array, array[0]);

  printf("After deleting an element: ");

  printArray(array, size);
}