#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long

const int maxn=3e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=1e9+7;
const int INF=1e9;

inline int qp(int x,int y)//快速幂
{
    if(y==0||x==1)return 1;
    if(x==0)return 0;
    int res=1;
    while(y)
    {
        if(y&1)res=res*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return res;
}

vector<int>fac(maxn,0),invfac(maxn,0);

inline void init()
{
    fac[0]=1;
    invfac[0]=1;
    for(int i=1;i<maxn;i++)fac[i]=fac[i-1]*i%mod;
    invfac[maxn-1]=qp(fac[maxn-1],mod-2);
    for(int i=maxn-2;i;i--)invfac[i]=invfac[i+1]*(i+1)%mod;
}

inline int C(int x,int y)//x里面选y个
{
    if(x-y<0)return 0;
    return fac[x]*invfac[x-y]%mod*invfac[y]%mod;
}

inline int inv(int x)//x的逆元
{
    return qp(x,mod-2);
}

void sol()
{
    
}

signed main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    init();
    cout<<22*inv(9)%mod;
    int T;
    T = 1;
    cin>>T;
    while (T--)sol();
    system("pause");
}