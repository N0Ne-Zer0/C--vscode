// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
#define int long long

const int maxn=2e5+5;
const int mod=1e9+7;

int N,M;
int s[3];

void sol()
{
    int n;
    cin>>n;
    s[0]=s[1]=s[2]=0;
    for(int i=1;i<=n;i++)
    {
        int t;
        cin>>t;
        s[t]++;
    }
    int ans=s[0];
    ans+=min(s[1],s[2])+abs(s[1]-s[2])/3;
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