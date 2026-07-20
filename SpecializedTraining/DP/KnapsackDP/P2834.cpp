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
    int n,w;
    cin>>n>>w;
    vector<int>a(n);
    vector<int>dp(w+1,0);
    for(auto &x:a)cin>>x;
    dp[0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=a[i];j<=w;j++)
        {
            dp[j]=(dp[j]+dp[j-a[i]])%mod;
        }
    }
    cout<<dp[w];
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