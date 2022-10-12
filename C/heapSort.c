#include <stdio.h>
#include <stdlib.h>

void displayHeap(int *arr, int size){
    for(int i=1; i<=size; i++)
        printf("%d ", arr[i]);
}
void swap(int *arr, int x, int y){
    arr[x] += arr[y];
    arr[y] = arr[x] - arr[y];
    arr[x] = arr[x] - arr[y];
}
void heapify(int *arr, int i, int size){
    int li = 2*i; // left child
    int ri = li+1; //right child
    int largest = i; // assume parent is largest

    // setting largest
    if(li<=size && arr[li] > arr[largest])
        largest = li;
    if(ri<=size && arr[ri] > arr[largest])
        largest = ri;

    if(largest != i) // largest has updated ie parent was not the largest
    {
        swap(arr, i, largest);
        heapify(arr, largest, size);
    }
    // else return as no further changes
}
void buildHeap(int *arr, int size){ // heapify an array
    for(int i = size/2; i>0; i--)
        heapify(arr, i, size);
}

void heapSort(int *arr, int size){   // heapsort is keyword so heapSort used
    // heapify the random array inside Heap h1
    buildHeap(arr, size);
    printf(" Heap : \n");
    displayHeap(arr, 6);
    printf("(Note - Heap does not mean descending order!)\n");

    // sort by deleting the 1st element and swapping it with last and so on
    for(int i=size; i>1; i--){ // In heap array os filled from index 1 to size. And if size-1 elements are sorted the remaining element is automatically sorted.
        swap(arr, 1, i);
        heapify(arr, 1, i-1); // heapify the 1st element of arr of size = i-1
    }
}

int main() {
    int size = 100;
    int *arr = (int*)malloc(size*sizeof(int));
    arr[1] = 20;
    arr[2] = 70;
    arr[3] = 50;
    arr[4] = 30;
    arr[5] = 40;
    arr[6] = 10;
    heapSort(arr, 6);
    printf(" HeapSort : \n");
    displayHeap(arr, 6);
    printf("\n");
}
