/*
    to check whether a number is prime or not
 */

#include<iostream>
#include<cmath>

using namespace std;


bool isPrime(int num)
{
    // Function checks if a number is prime or not
    // Check if the number is perfect square
    // if it is a perfect square it is not prime
    if((float)pow(sqrt(num), 2) != float(num))
    {
        return false;
    }

    // if the number is either of 2,3,5 or 7 than it is a prime
    if(num==2 || num==3 || num==5 || num==7)
    {
        return true;
    }

    // if num is divisible by 2,3,5 or 7 it is not a prime number
    if((num%2==0 || num%3==0 || num%5==0 || num%7==0))
    {
        return false;
    }
    else
    {
        // if it is not divisible by 2,3,5 or 7 and number > 10
        if(num>10)
        {   
            // divide the number by the range(2, num/2)
            for(int i=2; i<(num/2); i++)
            {
                // if divisible by any number in the range, number is not prime
                if(num%i==0)
                {
                    return false;
                }
            }
            // if it is not evenly divisible by any number in the range the number is prime
            return true;
        }
        
        
    }
    // this is just to avoid warnings
    return NULL;
}


int main()
{
    
    bool status = isPrime(29);

    cout<<status;

    return 0;
}