// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
#define int long long

const int maxn=3e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=998244353;
const int INF=1e9;


void sol()
{
    int n,x,y,z;
    cin>>n>>x>>y>>z;
    int ans=MAX;
    ans=min(ans,(n+x+y-1)/(x+y));
    int r=x*z,res;
    if(r>=n)res=(n+x-1)/x;
    else
    {
        n-=x*z;
        res=z;
        res+=(n+x+10*y-1)/(x+10*y);
    }
    ans=min(ans,res);
    cout<<ans<<'\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=1;
    cin>>T;
    while(T--)sol();
}
