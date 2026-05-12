#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
#define int long long

const int maxn=2e4+5;
const int mod=1e9+7;

int n,a[maxn];
int tem[maxn];

void sol()
{
    int l,r;
    int ans=0;
    cin>>l>>r;
    int len=r-l+1;
    for(int k=l;k<=r;k++)
    {
        int i=k-l+1;
        tem[i]=a[k];
    }
    sort(tem+1,tem+len+1);
    int x=len,t=0;
    for(int i=len;i>=1;i--)
    {
        while(x>=1&&tem[x]>=i)
        {
            t++;
            x--;
        }
        int tt=max(1ll,t);
        ans=(ans+(i*tt*tt)%mod)%mod;
    }
    cout<<ans<<'\n';
}


signed main()
{
    int T=1;
    cin>>n;
    cin>>T;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    while(T--)
    {
        sol();
    }
}