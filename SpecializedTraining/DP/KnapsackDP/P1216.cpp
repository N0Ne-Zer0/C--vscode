#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long

const int maxn=2e3+5;
const int MAX=0x7fffffffffffffff;
const int mod=998244353;
const int INF=1e9;

void sol()
{
    int r;
    cin>>r;
    vector<vector<int>>a(r+1,vector<int>(r+2,0));
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cin>>a[i][j];
        }
    }
    vector<int>dp(r+1,0);
    for(int i=1;i<=r;i++)
    {
        for(int j=i;j>=1;j--)
        {
            dp[j]=max(dp[j],dp[j-1])+a[i][j];
        }
    }
    int res=0;
    for(int i=1;i<=r;i++)res=max(res,dp[i]);
    cout<<res;
}
//10 15 15

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    T = 1;
    // cin>>T;
    while (T--)sol();
}