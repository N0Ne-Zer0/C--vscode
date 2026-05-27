// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
#define int long long

const int maxn=2e5+5;
const int mod=1e9+7;

void sol()
{
    int n,x1,x2,k;
    cin>>n>>x1>>x2>>k;
    if(n<=3)
    {
        cout<<1<<'\n';
        return;
    }
    int ans=min(abs(x1-x2),(n-abs(x1-x2))%n);
    ans+=k;
    cout<<ans<<'\n';
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