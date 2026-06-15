// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
#define int long long

const int maxn=2e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=1e9+7;

vector<int>a(maxn),ans;
vector<int>pre(maxn),suff(maxn);

void sol()
{
    ans.clear();
    int n,tmax=0;
    cin>>n;
    pre[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        pre[i]=pre[i-1]+abs(a[i]);
        tmax+=a[i];
    }
    int idx=0;
    suff[n+1]=0;
    for(int i=n;i>=1;i--)
    {
        suff[i]=suff[i+1]+a[i];
        if(a[i]<0)continue;
        if(pre[i-1]-a[i]+suff[i+1]>tmax)
        {
            idx=i;
            tmax=pre[i-1]-a[i]+suff[i+1];
        }
    }

    int f=0;
    for(int i=idx-1;i>=1;i--)
    {
        if(f)
        {
            a[i]=-a[i];
        }
        if(a[i]>0)
        {
            f^=1;
            a[i]=-a[i];
            ans.push_back(i);
        }
    }
    if(idx)ans.push_back(idx);
    cout<<ans.size()<<'\n';
    for(auto i:ans)cout<<i<<' ';
    cout<<'\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=1;
    cin>>T;
    while(T--)sol();
}
