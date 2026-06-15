#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<unordered_map>
#include<algorithm>
using namespace std;
#define int long long
#define endl '\n'

const int maxn=3e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=998244353;
const int INF=1e9;



void sol()
{
    int n;
    cin>>n;
    vector<int>a(n+1,0);
    vector<vector<bool>>w(n+1,vector<bool>(n+1));
    vector<bool>vis(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int l=1;l<=n;l++)
    {
        int mi=a[l],ma=a[l];
        vis.assign(n+1,0);
        for(int r=l;r<=n;r++)
        {
            if(r-l+1>n/2)break;
            vis[a[r]]=vis[a[r]]^1;
            if(vis[a[r]]==0)break;
            mi=min(mi,a[r]);
            ma=max(ma,a[r]);
            if(r-l+1==ma-mi+1)
            {
                w[r-l+1][mi]=1;
            }
        }
    }
    int res=0;

    for(int len=1;len<=n/2;len++)
    {
        for(int i=1;i<=n;i++)
        {
            if(i+len>n)break;
            if(w[len][i]&&w[len][i+len])res=len;
        }
    }
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