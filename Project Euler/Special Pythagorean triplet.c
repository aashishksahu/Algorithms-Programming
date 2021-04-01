#include<stdio.h>
#include<math.h>

int is_trip(int a, int b, int c){
    return ((pow(a,2)+pow(b,2))==pow(c,2))? 1: 0;
}

int main(){
    /*
        There are 3 loops here, and it sucks,
        I tried "Progressions of whole and fractional numbers"
        by Michael Stifel but it didn't give me the right
        answer
    */
    for(int i = 5; i<500; i++){
        for(int j = 4; j<i; j++){
            for(int k = 3; k<j; k++){
                if(is_trip(k,j,i) && i+j+k==1000){
                printf("%d x %d x %d = %d\n", i,j,k, (i*j*k));
                    return 0;
                }
            }
        }
    }
}
