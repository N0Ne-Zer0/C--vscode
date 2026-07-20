// #include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
#define int long long

const int maxn=5e5+5;
const int mod=1e9+7;

vector<vector<int>>edge(maxn),ST(maxn*2,vector<int>(21));
vector<int>euler,h(maxn),ft(maxn),lg(maxn*2);

void dfs(int x,int fa)
{
    h[x]=h[fa]+1;
    ft[x]=euler.size();
    euler.push_back(x);
    for(auto v:edge[x])
    {
        if(v==fa)continue;
        dfs(v,x);
        euler.push_back(x);
    }
}

int MIN(int a,int b)
{
    if(h[a]<h[b])return a;
    else return b;
}

void build_ST()
{
    for(int i=0;i<euler.size();i++)ST[i][0]=euler[i];
    lg[1]=0;
    for(int i=2;i<=euler.size();i++)lg[i]=lg[i/2]+1;
    for(int i=1;i<21;i++)
    {
        int len=1<<i;
        for(int j=0;j+len<=euler.size();j++)
        {
            ST[j][i]=MIN(ST[j][i-1],ST[j+(1<<(i-1))][i-1]);
        }
    }
}

int LCA(int a,int b)
{
    int l=ft[a],r=ft[b];
    if(l>r)swap(l,r);
    int k=lg[r-l+1];
    return MIN(ST[l][k],ST[r-(1<<k)+1][k]);
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
    build_ST();
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