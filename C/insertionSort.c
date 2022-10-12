#include <stdio.h>

int main() {
    int arr[]={5, 2, 7, 8, 2, 4, 0, 3};
    int length = sizeof(arr)/sizeof(arr[0]); //length of array in C

    for(int i=1; i<length; i++){
        int current = arr[i];
        int j = i-1;
        while(arr[j]>current && j>=0){
            arr[j+1]=arr[j];
            j--;
            // for java include the below condition to avoid IndexOutOfBounds exception and we can exclude the j>=0 condition in while loop
            // if(j<0)
            // break;
        }
        arr[j+1]=current;
    }

    for(int i=0; i<length; i++)
    printf("%d ", arr[i]);
}
