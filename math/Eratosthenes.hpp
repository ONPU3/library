// エラトステネスの篩
// O(NloglogN)

#pragma once
#include<iostream>
#include<vector>
using namespace std;

vector<bool>Eratosthenes(int N)
{
    vector<bool>isprime(N + 1, true);

    isprime[0] = false;
    isprime[1] = false;
    
    for(int p = 2; p <= N; p++)
    {
        if(!isprime[p])continue;

        for(int q = p * 2; q <= N; q += p)
        {
            isprime[q]=false;
        }
    }

    return isprime;
}
