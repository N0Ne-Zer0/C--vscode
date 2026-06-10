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

int h[maxn];
int n;

int F(int x)
{
    int res=0,cnt=n;
    vector<int>th(n,0),cur(n,0),h1(n,0),h2(n,0);
    while(cnt--)
    {
        int ii=(x+n)%n;
        th[n-cnt-1]=h[ii];
        x++;
    }
    int minh=0;
    for(int i=1;i<n;i++)
    {
        h1[i]=max(th[i-1],minh);
        minh=h1[i];
    }
    minh=0;
    for(int i=n-1;i>0;i--)
    {
        h2[i]=max(th[i],minh);
        minh=h2[i];
    }
    for(int i=1;i<n;i++)
    {
        cur[i]=min(h1[i],h2[i]);
    }
    for(auto i:cur)res+=i;
    return res;
}

void sol()
{
    cin>>n;
    for(int i=0;i<n;i++)cin>>h[i];
    for(int i=0;i<n;i++)
    {
        cout<<F(i)<<' ';
    }
    cout<<'\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=1;
    cin>>T;
    while(T--)sol();
}