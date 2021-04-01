#include <stdio.h>

int main(){
    
    long int limit = 4000000;
    
    long int a = 1;
    long int b = 2;

    long int p_sum = (a+b);
    
    while(b<=limit){
        int S = a+b;
        a = b;
        b = S;
        if(b%2==0){
            p_sum+=b;
        }
    }

    printf("%ld ", p_sum);

    return 0;
}
