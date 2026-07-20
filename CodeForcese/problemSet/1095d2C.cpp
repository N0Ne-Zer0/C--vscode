#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
#define endl '\n'

const int maxn = 5e5 + 5;

void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    vector<bool>fg(1e6+1,0);
    for(auto &x:a)cin>>x;
    sort(a.begin(),a.end());

    auto check=[&](int y)->bool
    {
        int res=0;
        fg.assign(1e6+1,0);
        for(auto const &x:a)
        {
            if(x<y&&fg[x]==0)
            {
                fg[x]=1;
                continue;
            }
            while(fg[res])res++;
            if(res<=(x-1)/2)
            {
                fg[res]=1;
                res++;
            }
        }
        while(fg[res])res++;
        return res>=y;
    };

    int l=1,r=1e6;
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
    cout<<l<<'\n';
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