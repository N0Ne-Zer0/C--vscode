#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
#define int long long

const int maxn=3e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=998244353;
const int INF=1e9;

struct Edge
{
    int v,w;
};


int n,m;
vector<vector<Edge>>edge;

void Prim()
{
    priority_queue<pair<int,int>>q;
    vector<bool>vis(n+1,0);
    int cnt=0,res=0;
    q.emplace(0,1);
    while(!q.empty())
    {
        auto [d,u]=q.top();
        q.pop();
        d=-d;
        if(vis[u])continue;
        vis[u]=1;
        res+=d;
        cnt++;
        for(auto [v,w]:edge[u])
        {
            if(vis[v])continue;
            q.emplace(-w,v);
        }
    }
    if(cnt<n)
    {
        cout<<"orz";
    }
    else cout<<res;
}

void sol()
{
    cin>>n>>m;
    edge.assign(n+1,{});
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edge[u].emplace_back(v,w);
        edge[v].emplace_back(u,w);
    }
    Prim();
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