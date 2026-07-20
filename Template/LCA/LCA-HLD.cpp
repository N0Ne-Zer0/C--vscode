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
vector<int>F(maxn),head(maxn),sz(maxn),hs(maxn),h(maxn),dfn;

void dfs1(int x,int fa=0)
{
    F[x]=fa;
    sz[x]=1;
    head[x]=x;
    h[x]=h[fa]+1;
    int HS=0,SZ=0;
    for(auto v:edge[x])
    {
        if(v==fa)continue;
        dfs1(v,x);
        sz[x]+=sz[v];
        if(sz[v]>SZ)
        {
            SZ=sz[v];
            HS=v;
        }
    }
    hs[x]=HS;
}
void dfs2(int x,int fa=0)
{
    dfn.push_back(x);
    if(hs[x])
    {
        head[hs[x]]=head[x];
        dfs2(hs[x],x);
    }
    for(auto v:edge[x])
    {
        if(v==fa)continue;
        if(v==hs[x])continue;
        dfs2(v,x);
    }
}

int LCA(int a,int b)
{
    while(head[a]!=head[b])
    {
        if(h[head[a]]>h[head[b]])swap(a,b);
        b=F[head[b]];
    }
    return h[a]>h[b]?b:a;
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
    dfs1(S);
    dfs2(S);
    for(int i=1;i<=M;i++)
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