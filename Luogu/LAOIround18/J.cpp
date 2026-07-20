#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
#define endl '\n'

const int maxn=3e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=998244353;
const int INF=1e9;

int qp(int x,int p)
{
    if(p==0)return 1;
    if(x==0)return 0;
    x%=mod;
    int res=1;
    while(p)
    {
        if(p&1)res=x%mod*res%mod;
        x=x%mod*x%mod;
        p>>=1;
    }
    return res;
}

//m=m*(m-1)^(n-1)
void sol()
{
    int n,m;
    cin>>n>>m;
    int res=m%mod*qp(m-1,n-1)%mod;
    cout<<res<<'\n';
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    T = 1;
    cin>>T;
    while (T--)
    {
        sol();
    }
}