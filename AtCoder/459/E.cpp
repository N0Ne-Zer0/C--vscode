// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define int long long

const int maxn=1e6+5;
const int MAX=0x7fffffffffffffff;
const int mod=998244353;

vector<int>P(maxn),C(maxn),D(maxn),R(maxn),S[maxn];
int fac[maxn],invfac[maxn],ans=1;

int qp(int x,int y)
{
    if(y==0)return 1;
    if(x==0||x==1)return x;
    int ans=1;
    while(y)
    {
        if(y&1)ans=ans*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return ans;
}

void inifac()
{
    fac[0]=1;
    for(int i=1;i<maxn;i++)fac[i]=fac[i-1]*i%mod;
    invfac[maxn-1]=qp(fac[maxn-1],mod-2);
    for(int i=maxn-2;i>=0;i--)invfac[i]=invfac[i+1]*(i+1)%mod;
}
int Co(int x,int y)
{
    if(y<0)return 0;
    int tem=1;
    for(int i=x-y+1;i<=x;i++)tem=i%mod*tem%mod;
    return tem*invfac[y]%mod;
}

void dfs(int x)
{
    for(auto i=0u;i<S[x].size();i++)
    {
        dfs(S[x][i]);
        R[x]+=R[S[x][i]];
    }
    R[x]+=C[x];
    if(R[x]<D[x])
    {
        ans=0;
        return;
    }
    ans=ans*Co(R[x],D[x])%mod;
    R[x]-=D[x];
}

void sol()
{
    int N;
    inifac();
    cin>>N;
    for(int i=2;i<=N;i++)cin>>P[i];
    for(int i=1;i<=N;i++)cin>>C[i];
    for(int i=1;i<=N;i++)cin>>D[i];
    for(int i=2;i<=N;i++)S[P[i]].push_back(i);
    dfs(1);
    cout<<ans<<'\n';
}

signed main()
{
    int T=1;
    // cin>>T;
    while(T--)
    {
        sol();
    }
}