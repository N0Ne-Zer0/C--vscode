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

void sol()
{
    struct clo
    {
        int l,r,i;
    };
    
    int n,k;
    cin>>n>>k;
    vector<clo>a(n);
    for(int j=0;auto &[l,r,i]:a)
    {
        cin>>l>>r;
        i=j;
        j++;
    }
    
    sort(begin(a),end(a),[](clo x,clo y)
    {
        if(x.r==y.r)return x.l>y.l;
        return x.r<y.r;
    });

    auto check=[&](int x)
    {
        int tk=k;
        int curR=a[0].r;
        tk--;
        for(int i=1;i<n;i++)
        {
            if(a[i].l-curR>=x)
            {
                curR=a[i].r;
                tk--;
            }
            if(tk<=0)return 1;
        }
        return 0;
    };


    int l=0,r=1e9;
    while(l<r)
    {
        int mid=(l+r+1)>>1;
        if(check(mid))
        {
            l=mid;
        }
        else
        {
            r=mid-1;
        }
    }
    if(l==0)l=-1;
    cout<<l;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    T = 1;
    // cin>>T;
    while (T--)sol();
}