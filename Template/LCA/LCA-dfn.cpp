// #include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
#define int long long

const int maxn=5e5+5;
const int mod=1e9+7;

vector<vector<int>>edge(maxn),ST(maxn,vector<int>(21));
vector<int>dfn,h(maxn),ft(maxn),lg(maxn),f(maxn);

void dfs(int x,int fa){
    h[x]=h[fa]+1;
    f[x]=fa;
    ft[x]=dfn.size();
    dfn.push_back(x);
    for(auto v:edge[x]){
        if(v==fa)continue;
        dfs(v,x);
    }
}

int MIN(int a,int b){
    if(h[f[a]]<h[f[b]])return a;
    else return b;
}

void build_ST(){
    for(int i=0;i<dfn.size();i++)ST[i][0]=dfn[i];
    lg[1]=0;
    for(int i=2;i<=dfn.size();i++)lg[i]=lg[i/2]+1;
    for(int i=1;i<21;i++){
        int len=1<<i;
        for(int j=0;j+len<=dfn.size();j++){
            ST[j][i]=MIN(ST[j][i-1],ST[j+(1<<(i-1))][i-1]);
        }
    }
}

int LCA(int a,int b){
    if(a==b)return a;
    int l=ft[a],r=ft[b];
    if(l>r)swap(l,r);
    l++;
    int k=lg[r-l+1];
    int res=MIN(ST[l][k],ST[r-(1<<k)+1][k]);
    return f[res];
}

void sol(){
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

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T=1;
    // cin>>T;
    while(T--)
    {
        sol();
    }
}