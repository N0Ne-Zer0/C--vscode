#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long

const int maxn=2e3+5;
const int MAX=0x7fffffffffffffff;
const int mod=1e9+7;
const int INF=1e9;

void sol()
{
    int T,M;
    cin>>T>>M;
    vector<int>t(M+1,0),w(M+1,0);
    for(int i=1;i<=M;i++)cin>>t[i]>>w[i];
    //dp[i][j]
    vector<int>dp(T+1,0);
    for(int i=1;i<=M;i++)
    {
        for(int j=T;j>=t[i];j--)
        {
            dp[j]=max(dp[j-t[i]]+w[i],dp[j]);
        }
    }
    cout<<dp[T];
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    T = 1;
    // cin>>T;
    while (T--)sol();
}