#include<iostream>
using namespace std;
#include<math.h>

void find_smallest_largest_factors(int num_to_factor,
        int (&factor_vals)[2])
{
    if(num_to_factor%2==0)
    {
        if(num_to_factor ==2)
        {
            factor_vals[0]=1;
            factor_vals[1]=2;
            
        }
        else
        {
            factor_vals[0]=2;
            factor_vals[1]=num_to_factor/2;
        }
        
    }
    else
    {
        int composite_test=0;
        for (int i=3;i<num_to_factor/2; i+=2)
        {
            if(num_to_factor%i==0)
            {
                composite_test=1;
                factor_vals[0]=i;
                factor_vals[1]=num_to_factor/i;

                break;
            }
        }
        if (composite_test == 0)
        {
            factor_vals[0]=1;
            factor_vals[1]=num_to_factor;
        }
    }    
}

int get_number_of_primes_below_num(int input_num)
{
    int num_of_primes = 0;
    int temp_factor_vals[2] = {0};
    for (int i=2; i<=input_num; i++)
    {
        find_smallest_largest_factors(i,
                temp_factor_vals);
        if(temp_factor_vals[1]==i)
        {
            num_of_primes += 1;
        }
    }
    return num_of_primes;
}

int get_arr_of_primes_below_num(
        int input_num,
        int * &prime_num_val_arr // pass pointer by reference
        // int * *prime_num_arr //pass pointer by pointer
        )
{
    int num_of_primes = get_number_of_primes_below_num(input_num);
    prime_num_val_arr = new int [num_of_primes]; //pass by reference
    // *prime_num_arr = new int [num_of_primes]; //pass by pointer
    int temp_factor_vals[2] = {0};
    int x_counter = 0;
    for (int i=2; i<=input_num; i++)
    {
        find_smallest_largest_factors(i,
                temp_factor_vals);
        if(temp_factor_vals[1]==i)
        {
            prime_num_val_arr[x_counter] =i;
            x_counter += 1;
        }
    }
    // cout << num_of_primes<<x_counter;
    return num_of_primes;
}

void add_prime_cnt(
    int input_prime_num,
    int num_of_primes,
    int * &prime_num_val_arr,
    int * &prime_num_cnttemp_arr
    )
{
    for(int i=0; i<num_of_primes; i++)
    {
        if (prime_num_val_arr[i]==input_prime_num)
        {
            prime_num_cnttemp_arr[i] += 1;
            break;
        }
    }
}

void get_prime_factors(
        int input_num,
        int num_of_primes,
        int * &prime_num_val_arr,
        int * &prime_num_cnttemp_arr
        )
{
    int prime_factors = 0;
    int temp_factor_vals[2] = {0};
    int num_to_factor = input_num;
    while (prime_factors !=1)
    {
        find_smallest_largest_factors(num_to_factor,
                temp_factor_vals);
        if(temp_factor_vals[1]==num_to_factor)
            {
                add_prime_cnt(
                    temp_factor_vals[1],
                    num_of_primes,
                    prime_num_val_arr,
                    prime_num_cnttemp_arr);
                prime_factors = 1;
            }
        else
        {
            add_prime_cnt(
                    temp_factor_vals[0],
                    num_of_primes,
                    prime_num_val_arr,
                    prime_num_cnttemp_arr);
            num_to_factor = temp_factor_vals[1];
        }        
    }    
}
void get_max_prime_cnt(
            int num_of_primes,
            int * &prime_num_cnttemp_arr,
            int * &prime_num_cntmax_arr
            )
{
    for(int i=0; i<num_of_primes; i++)
    {
        if(prime_num_cntmax_arr[i]<prime_num_cnttemp_arr[i])
        {
            prime_num_cntmax_arr[i]=prime_num_cnttemp_arr[i];
        }
    }
}


int get_min_divisble_num(
    int num_of_primes,
    int * &prime_num_val_arr,
    int * &prime_num_cntmax_arr
    )
{
    int min_divisible_num=1;
    for(int i=0; i<num_of_primes; i++)
    {
        min_divisible_num *= pow(prime_num_val_arr[i],
                                prime_num_cntmax_arr[i]);
    }
    return min_divisible_num;
}


void get_max_cnt_of_primes_below_num(
        int input_num,
        int num_of_primes,
        int * &prime_num_val_arr,
        int * &prime_num_cntmax_arr
        )
{
    int *prime_num_cnttemp_arr = new int[num_of_primes];
    for (int i=2; i<=input_num; i++)
    {   
        std::fill_n(prime_num_cnttemp_arr, num_of_primes, 0);        
        get_prime_factors(
            i, 
            num_of_primes,
            prime_num_val_arr,
            prime_num_cnttemp_arr
            );
        get_max_prime_cnt(
            num_of_primes,
            prime_num_cnttemp_arr,
            prime_num_cntmax_arr
            );
    }

}

int main()
{
    int input_num, num_of_primes;
    int *prime_num_val_arr, *prime_num_cntmax_arr;
    int min_divisible_num;
    cout << "Provide input integer:  ";
    cin >>input_num;
    num_of_primes = get_arr_of_primes_below_num(
        input_num,
        prime_num_val_arr);
    prime_num_cntmax_arr = new int[num_of_primes];
    std::fill_n(prime_num_cntmax_arr, num_of_primes, 1);
    get_max_cnt_of_primes_below_num(
        input_num,
        num_of_primes,
        prime_num_val_arr,
        prime_num_cntmax_arr);
    
    min_divisible_num = get_min_divisble_num(
                            num_of_primes,
                            prime_num_val_arr,
                            prime_num_cntmax_arr
                            );
    cout << "Min Divisble Num: "<< min_divisible_num << "\n";    
    return 0;
}