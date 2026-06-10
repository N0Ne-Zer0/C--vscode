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
    int sum=0,ans=MAX;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
        ans=min(ans,sum/i);
        cout<<ans<<' ';
    }
    cout<<'\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=1;
    cin>>T;
    while(T--)
    {
        sol();
    }
}