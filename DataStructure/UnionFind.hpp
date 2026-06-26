// UnionFind.hpp
// UnionFind - O(N + Qα(N))
// 計算量詳細 https://info.atcoder.jp/entry/algorithm_lectures/unionfind_complexity

#pragma once
#include<iostream>
#include<vector>
using namespace std;

struct UnionFind
{
    vector<int>par, sz;
    int groups;

    UnionFind(int N)
    {
        init(N);
        groups = N;
    }

    void init(int N)
    {
        par.resize(N);
        iota(par.begin(), par.end(), 0);
        sz.assign(N, 1);
    }

    int root(int a)
    {
        if(par[a] == a)return a;
        return par[a] = root(par[a]);
    }

    bool same(int a, int b)
    {
        return root(a) == root(b);
    }

    void merge(int a, int b)
    {
        a = root(a);
        b = root(b);
        if(a == b)return;
        if(sz[a] < sz[b])swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
        groups--;
    }

    int size(int a)
    {
        return sz[root(a)];
    }
};
