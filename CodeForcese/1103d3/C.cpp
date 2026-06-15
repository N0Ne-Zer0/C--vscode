#include<iostream>
#include<queue>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
#define endl '\n'

const int maxn=3e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=998244353;
const int INF=1e9;

// 4 2 1 0
// 7 3 1 0

void sol()
{
    int a,b,x;
    cin>>a>>b>>x;
    int ans=abs(a-b);
    vector<pair<int,int>>ma,mb;
    int cnt=0;
    ma.push_back({a,0});
    while(a)
    {
        ma.push_back({a/x,++cnt});
        a/=x;
    }
    ma.push_back({0,++cnt});

    mb.push_back({b,0});
    cnt=0;
    while(b)
    {
        mb.push_back({b/x,++cnt});
        b/=x;
    }
    mb.push_back({0,++cnt});
    for(auto [x,c1]:ma)
    {
        for(auto [y,c2]:mb)
        {
            ans=min(ans,abs(x-y)+c1+c2);
        }
    }
    cout<<ans<<'\n';
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