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

int qp(int x,int y)
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

void sol()
{
    int w,l;
    cin>>w>>l;
    cout<<((l-1)+qp(w,l))%mod<<'\n';
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