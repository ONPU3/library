#pragma once

// エラトステネスの篩
// O(NloglogN)

#include <vector>

std::vector<bool> Eratosthenes(int N)
{
    std::vector<bool> isprime(N + 1, true);

    isprime[0] = false;
    isprime[1] = false;
    
    for(int p = 2; p * p <= N; p++)
    {
        if(!isprime[p])continue;

        for(int q = p * p; q <= N; q += p)
        {
            isprime[q] = false;
        }
    }

    return isprime;
}
