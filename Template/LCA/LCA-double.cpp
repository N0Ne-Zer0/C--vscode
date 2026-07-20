// #include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
#define int long long

const int maxn=5e5+5;
const int mod=1e9+7;

vector<vector<int>>edge(maxn),f(maxn,vector<int>(21));
vector<int>h(maxn);

void dfs(int x,int fa)
{
    f[x][0]=fa;
    h[x]=h[fa]+1;
    for(int i=1;i<21;i++)
    {
        f[x][i]=f[f[x][i-1]][i-1];
    }
    for(auto v:edge[x])
    {
        if(v==fa)continue;
        dfs(v,x);
    }
}

int LCA(int a,int b)
{
    if(h[a]>h[b])swap(a,b);
    int gap=h[b]-h[a];
    int w=0;
    while(gap)
    {
        if(gap&1)b=f[b][w];
        gap>>=1;
        w++;
    }
    if(a==b)return a;
    for(int i=20;i>=0;i--)
    {
        if(f[a][i]==f[b][i])continue;
        a=f[a][i];
        b=f[b][i];
    }
    return f[a][0];
}

void sol()
{
    int N,M,S;
    cin>>N>>M>>S;
    for(int i=1;i<N;i++)
    {
        int u,v;
        cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(S,0);
    while(M--)
    {
        int a,b;
        cin>>a>>b;
        cout<<LCA(a,b)<<'\n';
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T=1;
    // cin>>T;
    while(T--)
    {
        sol();
    }
}