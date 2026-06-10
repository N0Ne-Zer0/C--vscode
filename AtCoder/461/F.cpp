// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long

const int maxn=3e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=998244353;



void sol()
{
    int n;
    cin>>n;
    vector<int>fact,fac(15,0);
    fac[0]=1;
    for(int i=1;i<15;i++)fac[i]=fac[i-1]*i%mod;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i)continue;
        fact.push_back(i);
        if(i*i==n)continue;
        fact.push_back(n/i);
    }
    sort(fact.begin(),fact.end());
    int len=fact.size();
    vector<vector<int>>dp(len,vector<int>(15,0));//dp[i][j]表示已经选择了j个数，且乘积为fact[i]的方案数
    vector<vector<int>>sco(len,vector<int>(15,0));//计算分数
    //选上fact[i],dp[idx(fact[i]*fact[k])][j+1]+=dp[i][j]

    //01背包
    dp[0][0]=1;
    for(int i=0;i<len;i++)//考虑加入第i个物品
    {
        int x=fact[i];
        for(int k=len-1;k>=0;k--)
        {
            if(i+k>=len)continue;
            int y=fact[k];
            if(n%(x*y))continue;
            int idx=lower_bound(fact.begin(),fact.end(),x*y)-fact.begin();//显然idx>k
            if(idx>=len)continue;
            for(int j=13;j>=0;j--)
            {
                dp[idx][j+1]=(dp[idx][j+1]+dp[k][j])%mod;
                sco[idx][j+1]=(sco[idx][j+1]+sco[k][j]+x%mod*dp[k][j]%mod)%mod;
                // if(idx==2&&dp[k][j])cout<<k<<' '<<j<<' '<<dp[k][j]<<'\n';
            }
        }
    }
    int res=0;
    for(int i=0;i<len;i++)
    {
        cout<<fact[i]<<": ";
        for(int j=1;j<5;j++)cout<<dp[i][j]<<" \n"[j==4];
    }
    for(int i=1;i<15;i++)res=(res+sco[len-1][i]*fac[i]%mod)%mod;
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

