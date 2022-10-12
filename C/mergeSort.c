#include <stdio.h>

void Merge(int a[], int low, int mid, int high){
    int b[high+1-low];
    int i = low; int j = mid+1; int k = 0;

    while(i <= mid && j <= high){
        if(a[i] < a[j]){
            b[k] = a[i];
            i++; k++;
        }
        else{
            b[k] = a[j];
            j++; k++;
        }
    }
    while(i <= mid){
        b[k] = a[i];
        i++; k++;
    }
    while(j <= high){
        b[k] = a[j];
        j++; k++;
    }
    // copy b[] to respective cells of a[]
    for(i=0, j=low; j<=high; i++, j++)
    a[j]= b[i];
}

void MergeSort(int a[], int low, int high){
    if(low>=high)
    return;

    int mid = (low+high)/2;
    MergeSort(a, low, mid);
    MergeSort(a, mid+1, high);
    Merge(a, low, mid, high);
}
 void display(int a[]){
     for(int i=0; i<6; i++)
     printf("%d ", a[i]);
 }
int main(){
    int a[6] = {2, 4, 6, 2, 7, 3};
    MergeSort(a, 0, 5);
    display(a);
}
