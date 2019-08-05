#include<iostream>
#include<vector>

using namespace std;

vector<int> fibonacci(int n)
{
    /*returns a vector of fibonacci series upto n */

    // initialise sum, next and pre
    int sum = 1, next = 1, pre = 0;

    // initialise a vector to store the values
    vector <int> series;

    // logic
    // initially add next and pre with values as declared above
    // copy next to pre
    // copy the sum to next
    // repeat the above in a lopp till n
    
    for(int i = 1; i<=n; i++)
    {
        sum = (next + pre);
        pre = next;
        next = sum;
        if (sum>4000000)
        {
            cout<<"limit exceeded!";
            break;
        }
        series.push_back(sum);
    }

    return series;
}


int main()
{
    // initialise vector to hold the series
    vector <int> fibonacci_series;
    int sum = 0, n;

    cout<<"how long should be the series: ";
    cin>>n;

    // calculate the series
    fibonacci_series = fibonacci(n);

    cout<<"\nthe series: "<<endl;

    // printing the series and summing the even numbers in the series
    for (auto i = fibonacci_series.begin(); i!=fibonacci_series.end(); i++)
    {
        cout<<*i<<" ";

        // if number in the series is even add it to the overall sum
        if (*i%2==0)
        {
            sum+=*i;
        }
    }

    cout<<"\nSum of even digits: "<<sum<<endl;
    
    return 0;
}