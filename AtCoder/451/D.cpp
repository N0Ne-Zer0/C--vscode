// #include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<bitset>
#include<cmath>
using namespace std;
#define endl '\n'
#define int long long

const int maxn=3e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=998244353;
const int INF=1e9;

int LEN(int x)
{
    int res=0;
    while(x)
    {
        res++;
        x/=10;
    }
    return res;
}

vector<int>good,fac_10(100);
vector<int>len(100);
bitset<INF>vis;
void DFS(int x,int curLen)
{
    if(vis[x])return;
    good.push_back(x);
    vis[x]=1;
    for(int i=0;(1<<i)<=INF;i++)
    {
        if(curLen+len[i]>9)break;
        int X=x*fac_10[len[i]]+(1<<i);
        int L=curLen+len[i];
        DFS(X,L);
    }
}

void sol()
{
    int N;
    cin>>N;
    for(int i=0;(1<<i)<=INF;i++)
    {
        len[i]=LEN(1<<i);
    }
    fac_10[0]=1;
    for(int i=1;i<10;i++)fac_10[i]=fac_10[i-1]*10;
    for(int i=0;(1<<i)<=INF;i++)
    {
        int X=1<<i;
        int L=len[i];
        DFS(X,L);
    }
    sort(good.begin(),good.end());
    // cout<<good.size();
    cout<<good[N-1];
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