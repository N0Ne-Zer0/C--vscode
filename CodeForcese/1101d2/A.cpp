// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define int long long

const int maxn=1e3+5;
const int mod=1e9+7;

int a[maxn];

void sol()
{
    int N;
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+N+1);
    int ans=0;
    int l=1,r=N;
    while(a[l]!=a[r])
    {
        ans++;
        l++;
        r--;
        if(l>N/2)break;
    }
    cout<<ans<<'\n';
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