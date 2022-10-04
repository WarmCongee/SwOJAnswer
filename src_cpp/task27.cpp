//
// Created by warmcongee on 22-10-4.
//
#include <iostream>
#include <vector>
#include <algorithm>

long long const MOD = 1000000007;

long long quick_pow(long long a, long long n)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 1)
        return (quick_pow(a, n - 1)% MOD) * (a% MOD) % MOD;
    else
    {
        long long temp = quick_pow(a, n / 2) % MOD;
        return (temp% MOD) * (temp% MOD) % MOD;
    }
}

int main(){
    int n = 0;
    std::cin>>n;

    long long num_max = (1L<<n) -1;
    long long temp = quick_pow((num_max-1)% MOD, (num_max-1)/2);
    temp = ((temp% MOD) * (num_max% MOD)) % MOD;
    std::cout<<temp;

    return 0;
}