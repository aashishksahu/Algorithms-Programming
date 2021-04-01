#include <stdio.h>
#include<math.h>

int main()
{
    
    int n = 100;
    int sq = (n*(n+1)*(2*n+1))/6;
    int su = pow((n*(n+1))/2, 2);

    printf("%d", abs(sq-su));
    
    return 0;
}
