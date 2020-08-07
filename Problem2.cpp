#include<iostream>
using namespace std;

int main()
{
    int fib1=1, fib2=2, max_num=4000000, fib_temp;
    int sum_val=0;
    while(fib2<max_num)
    {
        fib_temp=fib2;
        fib2 += fib1;
        fib1 = fib_temp;
        if (fib1%2==0)
        {
            sum_val += fib1;
        }
        //cout << fib2 <<" ";
    }
    cout << "Sum val is: "<< sum_val << "\n";
    return 0;
}