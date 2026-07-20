// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
#define int long long

const int maxn=5e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=1e9+7;

template<typename T>
struct FenwickTree
{
    int n,bit;
    vector<T>BIT;
    FenwickTree(int _n):BIT(_n+1),n(_n)
    {
        bit=1;
        while((bit<<1)<=n)bit<<=1;
    }

    inline int lb(int x){return -x&x;}

    inline void add(int x,const T &v)
    {
        for(int i=x;i<=n;i+=lb(i))
        {
            BIT[i]=BIT[i]+v;
        }
    }

    inline T sum(int x)
    {
        T res=0;
        for(int i=x;i>0;i-=lb(i))
        {
            res=res+BIT[i];
        }
        return res;
    }

    inline T rangeSum(int l,int r)
    {
        return sum(r)-sum(l-1);
    }

    inline T select(const T& k) //返回第一个前缀和大于等于k的下标
    {
        int idx=0;
        T cur{};
        for(int i=bit;i;i>>=1)
        {
            if(idx+bit>n||cur+BIT[idx+bit]>k)continue;
            idx+=bit;
            cur=cur+BIT[idx];
        }
        return idx;
    }
};

signed main()
{
    
}
