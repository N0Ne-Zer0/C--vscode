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
    int n;
    cin>>n;
    vector<pair<int,int>>g(n);
    for(auto &[t,c]:g)
    {
        int w,s;
        cin>>w>>s>>t;
        c=s-w;
    }
    int res=0,cur=0;
    sort(g.begin(),g.end());
    priority_queue<int>que;
    for(auto [t,c]:g)
    {
        cur+=c;
        que.push(-c);
        while(cur<0)
        {
            cur+=que.top();
            res++;
            que.pop();
        }
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