#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
#define int long long

const int maxn=2e6;
const int mod=998244353;

int fac[maxn],invfac[maxn];

int qp(int x,int y)
{
    if(y==1)return 1;
    if(x==0)return 0;
    if(x==1)return 1;
    int ans=1,tem=x;
    while(y)
    {
        if(y&1)ans=ans*tem%mod;
        tem=tem*tem%mod;
        y>>=1;
    }
    return ans%mod;
}
int C(int x,int y)
{
    if(x<y)return 0;
    return fac[x]*invfac[y]%mod*invfac[x-y]%mod;
}

void sol()
{
    int ans=0;
    int X1,X2,X3;
    cin>>X1>>X2>>X3;
    fac[0]=1;
    for(int i=1;i<maxn;i++)
    {
        fac[i]=fac[i-1]*i%mod;
    }
    invfac[maxn-1]=qp(fac[maxn-1],mod-2);
    for(int i=maxn-1;i>=1;i--)
    {
        invfac[i-1]=invfac[i]*i%mod;
    }
    for(int i=1;i<=X2+1;i++)
    {
        ans=(ans+C(X2+1,i)*C(X1-1,i-1)%mod*C(X2+X3-i,X3)%mod)%mod;
    }
    cout<<ans;
}

signed main()
{
    int T=1;
    // cin>>T;
    while(T--)
    {
        sol();
    }
}