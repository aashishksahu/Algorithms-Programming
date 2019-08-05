/*
   Problem 6
   
    The sum of the squares of the first ten natural numbers is,

    12 + 22 + ... + 102 = 385
    The square of the sum of the first ten natural numbers is,

    (1 + 2 + ... + 10)2 = 552 = 3025
    Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.

    Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
 */

#include<iostream>

using namespace std;

int main()
{
    // range of the series is 1 to 100
    int n = 100, difference, sum_of_squares, square_of_sum;

    // calculating the sum of squares of the first n terms
    sum_of_squares = ((n*(n+1)*(2*n+1))/6);
    
    // calculating the square of sum of the first 100 numbers
    square_of_sum = (((n*(n+1))/2) * ((n*(n+1))/2));

    // the difference between the sum of the squares and the square of the sum
    difference = (square_of_sum - sum_of_squares);

    cout<<"sum of squares of 100 natural numbers: "<<sum_of_squares
    <<"\nsquare of sum of 100 natural numbers: "<<square_of_sum
    <<"\n Difference: "<<difference<<endl;

    return 0;

}