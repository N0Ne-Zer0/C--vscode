#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
#define int long long

const int maxn=2e4+5;
const int mod=1e9+7;

void sol()
{
    int n,q;
    cin>>n>>q;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]=min(n,a[i]);
    }
    while(q--)
    {
        int l,r,res=0;
        cin>>l>>r;
        int L=r-l+1;
        vector<int>bt(L+1,0),suf(L+2,0);
        for(int i=l;i<=r;i++)
        {
            bt[min(L,a[i])]++;
        }
        for(int i=L;i;i--)
        {
            suf[i]=suf[i+1]+bt[i];
            res=(res+suf[i]*suf[i]%mod*i%mod)%mod;
        }
        cout<<res<<'\n';
    }
}


signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T=1;
    // cin>>T;
    while(T--)
    {
        sol();
    }
}