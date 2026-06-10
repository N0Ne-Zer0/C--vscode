// #include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define int long long

const int maxn=5e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=1e9+7;

int A[maxn],Bit[maxn];
int N;
//核心操作
inline int lowbit(int x){return -x&x;}
//构建树状数组
void build_Bit()
{
    for(int i=1;i<=N;i++)Bit[i]=A[i];
    for(int i=1;i<=N;i++)
    {
        if(i+lowbit(i)>N)continue;
        Bit[i+lowbit(i)]+=Bit[i];
    }
}
//单点修改
void Add(int x,int v)
{
    while(x<=N)
    {
        Bit[x]+=v;
        x+=lowbit(x);
    }
}
//前缀查询
int sum(int x)
{
    int rt=0;
    while(x)
    {
        rt+=Bit[x];
        x-=lowbit(x);
    }
    return rt;
}

signed main()
{
    
}
