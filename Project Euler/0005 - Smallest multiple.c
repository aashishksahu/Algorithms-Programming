#include <stdio.h>
#include <math.h>

long int gcd(long int a, long int b){
    long int R;
    
    while(1){
        
        if(a>b){
            R = a%b;
        }else{
            R = b%a;
        }
        a=b;
        if(R==0){
            return b;
        }
        b=R;
    }
}

long int getLCM(long int a, long int b){
    // printf("%d, %d -> %d\n", a,b, ((a*b)/gcd(a, b)));
    return (a*b)/gcd(a, b);
}

long int main()
{
    long int arr[20] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    
    long int lcm = arr[0];
    
    for (long int i = 1; i<(sizeof(arr)/sizeof(arr[0])); i++){
        lcm = getLCM(lcm,arr[i]);
    }
    
    printf("%ld\n",lcm);
    return 0;
}
