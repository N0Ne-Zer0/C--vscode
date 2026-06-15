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

bool cmp(pair<int,int>x,pair<int,int>y)
{
    if(x.first==y.first)return x.second>y.second;
    return x.first<y.first;
}

void sol()
{
    int n;
    cin>>n;
    vector<pair<int,int>>a(n);
    for(auto &[x,y]:a)
    {
        cin>>x>>y;
    }
    sort(a.begin(),a.end(),cmp);
    int lst=MAX,res=0;
    for(auto [x,y]:a)
    {
        if(y<=lst)
        {
            // cout<<x<<' '<<y<<'\n';
            res++;
        }
        lst=min(lst,y);
    }
    cout<<res;
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