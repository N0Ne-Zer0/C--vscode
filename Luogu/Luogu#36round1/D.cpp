// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
#define int long long

const int maxn=2e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=1e9+7;

void sol()
{
    int n,m,res=0;
    cin>>n>>m;
    vector<int>a(n+1);
    vector<int>mx(n+1,0),sx(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        if(y>mx[x])
        {
            sx[x]=mx[x];
            mx[x]=y;
        }
        else if(y>sx[x])
        {
            sx[x]=y;
        }
    };
    vector<vector<int>>dp(n+1,vector<int>(2,0));
    for(int i=0;i<n;i++)
    {
        dp[i+1][0]=max(dp[i+1][0],max(dp[i][0],dp[i][1])+a[i+1]);//no apply
        dp[i+1][0]=max(dp[i+1][0],dp[i][0]-a[i]+mx[i]+a[i+1]);//apply to left
        dp[i+1][1]=max(dp[i+1][1],max(dp[i][0],dp[i][1])+mx[i]);//apply to right
        dp[i+1][1]=max(dp[i+1][1],dp[i][0]-a[i]+mx[i]+sx[i]);//apply to both side
    }
    res=max(dp[n][0],dp[n][1]);
    cout<<res;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=1;
    // cin>>T;
    while(T--)sol();
}
