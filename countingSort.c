#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int size;

    printf("Hello\nPlease enter the size: ");
    scanf("%d", &size);

    arr=(int*)malloc(size*sizeof(int));

    // array input
    printf("Please enter %d elements in array: ", size);
    for(int i=0; i<size; i++)
       scanf("%d", &(*(arr+i)));

    // max number needed to set range of count[]
    int max;
    printf("Enter max number: ");
    scanf("%d", &max);

    // count[]
    int *count;
    count = (int*)malloc((max+1)*sizeof(int));

    // filling count
    for(int i=0; i<size; i++)
       // count[arr[i]]++;
       *(count + *(arr+i)) = *(count + *(arr+i))+1;

    // making count into position
    for(int i=1; i<=max; i++)
        *(count+i) = *(count+i) + *(count+i-1);

    // filling output array
    int output[size];
    for(int i=size-1; i>=0; i--){
        // output[count[arr[i]] - 1] = arr[i];
        *(output + *(count + *(arr+i)) - 1) = *(arr + i);
        // count[arr[i]]--;
        *(count + *(arr+i)) =  *(count + *(arr+i)) - 1;
    }
        
    // printing
    for(int i=0; i<size; i++)
       printf("%d ", *(output+i));
}
