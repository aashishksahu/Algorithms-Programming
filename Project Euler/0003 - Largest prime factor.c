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

long int factorise(long int num){
    long int n = num;
    long int i = 2;
    long int mul = 1;
    long int max_num = 2;
    
    while(n!=1){
        if(n%i==0 && is_prime(i)){
            mul*=i;
            n/=i;
            if(max_num<i){
                max_num=i;
            }
            if(mul==num){
                return i; 
            }
            i=1;
        }
        i++;
    }
    
}

int main()
{
    printf("%ld\n", factorise(600851475143));
    return 0;
}
