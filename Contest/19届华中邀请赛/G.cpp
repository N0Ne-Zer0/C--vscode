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

void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n+1),pre1(n+1,0),suf1(n+2,0),pre2(n+1,MAX),suf2(n+2,MAX);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        pre1[i]=max(pre1[i-1],a[i]);
        pre2[i]=min(pre2[i-1],a[i]);
    }
    for(int i=n;i>=1;i--)
    {
        suf1[i]=max(suf1[i+1],a[i]);
        suf2[i]=min(suf2[i+1],a[i]);
    }
    int res1=0,res2=MAX;
    for(int i=1;i<=n;i++)
    {
        if(i+k-1>n)break;
        int t=max(pre1[i-1],suf1[i+k])-min(pre2[i-1],suf2[i+k]);
        res1=max(res1,t);
        res2=min(res2,t);
    }
    cout<<res1<<' '<<res2;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    T = 1;
    // cin>>T;
    while (T--)
    {
        sol();
    }
}