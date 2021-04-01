#include <stdio.h>
#include <math.h>

int is_prime(long int num){
    int prime = 1;
    
    for(int i=2; i<=(int)sqrt(num); i++){
        if(num%i==0){
            prime = 0;
        }
    }
    return prime;
}

int main()
{
    int i = 1;
    long int n = 2;
    
    while(1){
        if(is_prime(n)){
            if(i==10001){
                printf("10001th Prime Number = %ld\n", n);
                break;
            }
            i++;
        }
        n++;
    }

    return 0;
}
