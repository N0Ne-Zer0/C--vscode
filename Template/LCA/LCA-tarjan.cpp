// #include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<bitset>
#include<cmath>
using namespace std;
#define int long long

const int maxn=5e5+5;
const int mod=1e9+7;

vector<vector<int>>edge(maxn);
vector<vector<pair<int,int>>>query(maxn);
bitset<maxn>vis;
vector<int>F(maxn),ans(maxn);

int Find(int x)
{
    if(x==F[x])return x;
    return F[x]=Find(F[x]);
}
void merge(int x,int fa)
{
    F[Find(x)]=Find(fa);
}

void Tarjan_DFS(int x,int fa=0)
{
    vis[x]=1;
    for(auto [y,id]:query[x])
    {
        if(!vis[y])continue;
        ans[id]=Find(y);
    }
    for(auto v:edge[x])
    {
        if(v==fa)continue;
        Tarjan_DFS(v,x);
    }
    merge(x,fa);
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
    for(int i=1;i<=M;i++)
    {
        int a,b;
        cin>>a>>b;
        query[a].push_back({b,i});
        query[b].push_back({a,i});
    }
    for(int i=1;i<=N;i++)F[i]=i;
    Tarjan_DFS(S);
    for(int i=1;i<=M;i++)
    {
        cout<<ans[i]<<'\n';
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