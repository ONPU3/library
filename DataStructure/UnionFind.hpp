#pragma once

// UnionFind.hpp
// 経路圧縮 + union by size
// O(N + Qα(N))
// 計算量詳細 https://info.atcoder.jp/entry/algorithm_lectures/unionfind_complexity

#include <vector>
#include <numeric>
#include <algorithm>

struct UnionFind
{
    std::vector<int> parent, sz;
    int group_count;

    UnionFind(int N)
    {
        init(N);
    }
    
    void init(int N)
    {
        parent.resize(N);
        std::iota(parent.begin(), parent.end(), 0);
        sz.assign(N, 1);
        group_count = N;
    }

    int root(int a)
    {
        if(parent[a] == a)return a;
        return parent[a] = root(parent[a]);
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
        if(sz[a] < sz[b])std::swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        group_count--;
    }

    int size(int a)
    {
        return sz[root(a)];
    }
};
