// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define int long long

const int maxn=2e5+5;
const int mod=1e9+7;
const int MAX=0x7fffffffffffffff;

int a[maxn];

void sol()
{
    int n;
    cin>>n;
    bool ans=1;
    int mink=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i==1)continue;
        if(!ans)continue;
        if(a[i-1]>a[i])mink=max(mink,a[i-1]-a[i]);
    }
    a[n+1]=MAX;
    for(int i=n;i>=1;i--)
    {
        if(a[i]+mink<=a[i+1])
        {
            a[i]+=mink;
        }
        if(a[i]>a[i+1])
        {
            ans=0;
            break;
        }
    }
    if(ans)cout<<"YES\n";
    else cout<<"NO\n";
}

signed main()
{
    int T=1;
    cin>>T;
    while(T--)
    {
        sol();
    }
}