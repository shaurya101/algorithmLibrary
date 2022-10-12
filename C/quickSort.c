// QUICKSORT WITH FIRST ELEMENT AS PIVOT

#include <stdio.h>
#include <stdlib.h>

void display(int *arr, int size){
    for(int i=0; i<size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void swap(int *arr, int i, int j){
    if(i!=j){   // if i==j then after swap the element will always become 0 using this method of swap. Also no need to swap an element by itself
        arr[i] += arr[j]; // stores i+j
        arr[j] = arr[i] - arr[j]; //stores i
        arr[i] -= arr[j]; // stores j
    }
}

int partition(int *arr, int low, int high){
    int pivot = arr[low];
    int i = low+1;
    int j = high;
    while(i<=j){
        while(arr[i]<= pivot && i<=high)
            i++;
        while(arr[j] > pivot)
            j--;
        if(i<j)
            swap(arr, i, j);
    }
    swap(arr, low, j); // no need put condition here because if order is already correct, j will become equal to low and arr[low]it will swap itself.
    display(arr, 5);
    printf("\n");
    return j;
}

void quickSort(int *arr, int low, int high){
    if(low<high){
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex-1);
        quickSort(arr, pivotIndex+1, high);
    }
}

int main() {
    int *arr = (int*)malloc(10*sizeof(int));
    for(int i = 0; i<5; i++)
        arr[i] = 5-i;
    printf("Original array :\n");
    display(arr, 5);
    quickSort(arr, 0, 4);
    printf("Sorted array:\n");
    display(arr, 5);
}
