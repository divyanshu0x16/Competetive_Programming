#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

//To start we need to find the last non-leaf node, which is parent of (n-1)th index
//Index at (n/2)-1
void heapify(int array[], int size, int i){
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;

    if (l < size && array[l] > array[largest])
        largest = l;
    if (r < size && array[r] > array[largest])
        largest = r;

    //If it is already max, we go to next node in reverse level order traversal
    //Else we heapify the affected the sub-tree
    if (largest != i){
        swap(&array[i], &array[largest]);
        heapify(array, size, largest);
    }
}

void deleteRoot(int arr[], int* n){
    int lastelement = arr[*n-1];
    arr[0] = lastelement;
    *n = *n-1;
    arr = realloc(arr, (*n)*sizeof(int));
    heapify(arr, *n, 0);
}

void buildHeap(int arr[], int n){
    int firstNonLeaf = (n/2)-1;

    //We perform reverse order traversal here
    for (int i = firstNonLeaf; i >= 0; i--){
        heapify(arr, n, i);
    }
    
}

void insertNodeHeapify(int ar[], int n, int i){
    int parent = (i-1)/2;

    if (ar[parent] > 0){
        if (ar[i] > ar[parent])
        {
            swap(&ar[i], &ar[parent]);
            insertNodeHeapify(ar, n, parent);
        }
    }
}

void insertNode(int arr[], int* n, int value){
    *n = *n+1;
    arr = realloc(arr, (*n)*sizeof(int));

    arr[*n-1] = 6;
    insertNodeHeapify(arr, *n, *n-1);
}

void printHeap(int arr[], int n) 
{ 
    printf("Array representation of Heap is:\n"); 
  
    for (int i = 0; i < n; ++i) 
        printf("%0d ",arr[i]); 
    printf("\n"); 
}


int main(){
    int a[3];
    a[0] = 4; a[1] = 2; a[2] = 3;

    int size = sizeof(a)/sizeof(a[0]);
    qsort((void*)a, size, sizeof(a[0]), cmpfunc);
    printHeap(a, size);

    int N = 3;
}

