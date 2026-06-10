// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long

const int maxn=3e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=1e9+7;

pair<int,int> a[maxn];
bool fg[maxn],fg1[maxn];

void sol()
{
    int n,k,m;
    cin>>n>>k>>m;
    for(int i=1;i<=n;i++)
    {
        int c,v;
        cin>>c>>v;
        a[i]={-v,c};
    }
    sort(a+1,a+1+n);
    int i=1,ans=0;
    while(m&&k&&i<=n)
    {
        if(fg[a[i].second]==0)
        {
            k--;
            m--;
            ans-=a[i].first;
            fg[a[i].second]=1;
            fg1[i]=1;
        }
        i++;
    }
    i=1;
    while(k&&i<=n)
    {
        if(fg1[i]==0)
        {
            k--;
            ans-=a[i].first;
        }
        i++;
    }
    cout<<ans<<'\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=1;
    // cin>>T;
    while(T--)sol();
}
