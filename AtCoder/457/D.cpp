#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
#define int long long

const int maxn=2e5+5;
const int mod=1e9+7;

pair<int,int>a[maxn];
int N,K;

bool cmp(pair<int,int>x,pair<int,int>y)
{
    return x.first<y.first;
}

bool check(int x)
{
    int cnt=K;
    for(int i=1;i<=N;i++)
    {
        int tem=a[i].first;
        if(a[i].first>=x)return 1;
        int q=(x-a[i].first)/a[i].second;
        tem+=q*a[i].second;
        if(tem<x)q++;
        cnt-=q;
        if(cnt<0)return 0;
    }
    return 1;
}

void sol()
{
    cin>>N>>K;
    for(int i=1;i<=N;i++)
    {
        int x;
        cin>>x;
        pair<int,int>tem=make_pair(x,i);
        a[i]=tem;
    }
    sort(a+1,a+N+1,cmp);
    int l=a[1].first,r=2e18;
    int ans=l;
    while(l<r)
    {
        int mid=(l+r+1)>>1;
        if(check(mid))
        {
            ans=mid;
            l=mid;
        }
        else
        {
            r=mid-1;
        }
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