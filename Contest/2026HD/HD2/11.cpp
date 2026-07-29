#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long

const int maxn=3e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=998244353;
const int INF=1e9;

void sol()
{
    int n;
    cin>>n;
    vector<int>a(n+2,0);
    for(int i=1;i<=n;i++)cin>>a[i];
    vector<int>dp(n+2,MAX),dp2(n+2,MAX);
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        dp[i]=min(dp[i],dp[i-1]+a[i+1]);
        if(i>1)
        {
            dp[i]=min(dp[i],dp[i-2]+max(a[i-1],a[i+1]));
        }
        if(i>2)
        {
            dp[i]=min(dp[i],dp[i-3]+max(a[i-1],a[i+1])+min(a[i-1],a[i-2]));
        }
    }
    int res=dp[n];
    cout<<res<<'\n';
}

signed main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int T;
    T = 1;
    cin>>T;
    while (T--)sol();
    system("pause");
}