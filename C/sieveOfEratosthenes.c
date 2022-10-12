#include <stdio.h>

int main() {
    int prime[101]={0}; // what is value of cell if we dont initialize

    for(int i=2; i*i<101; i++){
        if(prime[i]==0)
        for(int j=i*i; j<101; j+=i){
            prime[j]=1;
        }
    }
    for(int i=2; i<101; i++)
    if(!prime[i])
    printf("%d ", i);
}
