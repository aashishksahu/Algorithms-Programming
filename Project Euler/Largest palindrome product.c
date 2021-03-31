#include <stdio.h>
#include <math.h>

int isPalindrome(long int num){
    long int n = num;
    long int copy = 0;
    
    while(n!=0){
        copy = (copy*10)+(n%10);
        n/=10;
    }
    
    if(copy==num){
        return 1;
    }
    
    return 0;
}

void getPalindromeNumbers(){
    
    long int pal = 0;
    long int prod = 1;
    
    for(long int i = 999; i>99; i--){
        for(long int j = 999; j>99; j--){
            prod = i*j;
            
            if(isPalindrome(prod) && pal<prod){
                pal = prod;
            }
        }
    }
    printf("%ld\n", pal);
}

int main()
{
    getPalindromeNumbers();
    return 0;
}
