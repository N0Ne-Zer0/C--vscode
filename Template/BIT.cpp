// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
#define int long long

const int maxn=5e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=1e9+7;

int A[maxn],Bit[maxn];
int N;

inline int lb(int x)
{
    return -x&x;
}

inline void add(vector<int>&BIT,int x,int v=1)
{
    for(size_t i=x;i<BIT.size();i+=lb(i))
    {
        BIT[i]+=v;
    }
}

inline int search(const vector<int>&BIT,int x)
{
    int res=0;
    for(int i=x;i>0;i-=lb(i))
    {
        res+=BIT[i];
    }
    return res;
}


void build_Bit()
{
    for(int i=1;i<=N;i++)Bit[i]=A[i];
    for(int i=1;i<=N;i++)
    {
        if(i+lb(i)>N)continue;
        Bit[i+lb(i)]+=Bit[i];
    }
}

signed main()
{
    
}
