#include<iostream>
using namespace std;

unsigned long long int return_largest_factor(unsigned long long int num_to_factor)
{
    unsigned long long int largest_factor;
    // ISSUE: is i<num_to_factor or i<=num_to_factor
    for (unsigned long long int i=3; i<num_to_factor; i+=2)
    {
        // cout<<"Loop value is: "<<i;
        if (num_to_factor%i == 0)
        {
            // cout<<"Loop value is: "<<i;
            if(i<=num_to_factor/i)
            {
                largest_factor = num_to_factor/i;
            }
            else
            {
                largest_factor = i;
            }
            break;
        }
    }
    return largest_factor;
}
 

int main()
{
    unsigned long long int num_to_factor = 600851475143, largest_factor;
    //unsigned long long int num_to_factor = 8462696833;
    int prime_factor=0;
    while(prime_factor !=1)
    {
        largest_factor = return_largest_factor(num_to_factor);
        if (largest_factor<num_to_factor)
        {
            num_to_factor = largest_factor;
        }
        else
        {
            cout << "The largest factor is: "<< largest_factor << "\n";
            prime_factor=1;
        }
    }
    return 0;
}