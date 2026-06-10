// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long

const int maxn=3e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=998244353;

int ans,fac[20];
void dfs(int x,int lst,int len,int sum)
{
    ans=(ans+fac[len]*(sum+x)%mod)%mod;
    for(int i=lst+1;i*i<x;i++)
    {
        if(x%i)continue;
        dfs(x/i,i,len+1,sum+i);
    }
}

void sol()
{
    int n;
    cin>>n;
    fac[0]=1;
    for(int i=1;i<=15;i++)fac[i]=fac[i-1]*i%mod;
    dfs(n,0,1,0);
    cout<<ans;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=1;
    // cin>>T;
    while(T--)sol();
}

