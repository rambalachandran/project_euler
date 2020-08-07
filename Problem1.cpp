#include<iostream>
using namespace std;

int main()
{
    /* Get sum of all the numbers less than 100 that are divisble by 3 or 5 */
    int max_num=1000, divisor_1=3, divisor_2=5, sum_val=0;
    // int quotient_1, quotient_2;
    for(int i=0; i<max_num; i++)
    {
        if(i%divisor_1==0 || i%divisor_2==0)
        {
            sum_val += i;
        }
    }
    // quotient_1 = max_num/divisor_1;
    cout << "The total sum is " << sum_val << "\n";
    // cout << "max_num_ quotient 1: " << quotient_1;
    return 0;
    
}