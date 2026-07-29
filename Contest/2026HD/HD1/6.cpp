#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=2e5+5;
const int mod=998244353;

int fac[maxn],invfac[maxn];

int qp(int x,int y)
{
    if(y==0)return 1;
    if(x==0)return 0;
    int res=1;
    while(y)
    {
        if(y&1)res= res*x%mod;
        x= x*x%mod;
        y>>=1;
    }
    return res;
}
int C(int x,int y)
{
    if(x<y)return 0;
    return  fac[x]*invfac[y]%mod*invfac[x-y]%mod;
}

void ini()
{
    fac[0]=1;
    for(int i=1;i<maxn;i++)
    {
        fac[i]= fac[i-1]*i%mod;
    }
    invfac[maxn-1]=qp(fac[maxn-1],mod-2);
    for(int i=maxn-1;i>=1;i--)
    {
        invfac[i-1]= invfac[i]*i%mod;
    }
}

void sol()
{
    int n,sum=0;
    cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)sum+=a[i];
    sum%=mod;
    int res=((a[1]+a[n])%mod+(n+3ll)*(sum%mod)%mod)%mod*qp(6,mod-2)%mod;
    cout<<res<<'\n';
}

signed main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    ini();
    int T=1;
    cin>>T;
    while(T--)sol();
    system("pause");
}