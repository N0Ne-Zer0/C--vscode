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
    int res=(n+1)/2;
    vector<int>dp(n+1,0);
    for(int i=n;i;i--)
    {
        if(i%2==0)continue;
        int ma=0;
        for(int j=i*3;j<=n;j+=2*i)
        {
            ma=max(ma,dp[j]+1);
        }
        dp[i]=ma;
    }
    vector<int>ans;
    for(int i=1;i<=n;i+=2)ans.push_back(i*(1<<dp[i]));
    sort(ans.begin(),ans.end());
    cout<<res<<'\n';
    for(auto x:ans)cout<<x<<' ';
    cout<<'\n';
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    T = 1;
    cin>>T;
    while (T--)sol();
    // system("pause");
}