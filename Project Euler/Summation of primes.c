// Sometimes the naive approach is faster
#include <stdio.h>
#include <math.h>

int check_prime(long int n){
    for (long int i = 8; i<=sqrt(n); i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

int main(){
    
    long int n = 2000000;
    
    long int p_sum = (2+3+5+7);
    
    for (long int i = 8; i<n; i++){ 
        
        if (!(i%2==0 || i%3==0 || i%5==0 || i%7==0) && check_prime(i)){
            p_sum+=i;
        }
    }
    printf("%ld ", p_sum);

    return 0;
}


/*
// Sieve of Eratosthenes, either my implementation
// is wrong or the algorithm actually isn't a good idea
// for this situation because it took almost 2hrs to finish 
#include <iostream>
#include <algorithm>
#include<vector>

int main(){
    
    long int n = 2000000;
    
    long int p_sum = (2+3+5+7);
    
    std::vector <long int> comp;
    
    for (long int i = 8; i<n; i++){ 
        
        printf("i = %d\n", i);
        
        if (i%2==0 || i%3==0 || i%5==0 || i%7==0)
            continue;
        
        if (std::find(comp.begin(), comp.end(), i)==comp.end()){
            
            p_sum+=i;
            long int j = i;
            while (j<=n){
                j+=i;
                comp.push_back(j);
            }
        }
    }
    printf("%d ", p_sum);

    return 0;
}
*/
