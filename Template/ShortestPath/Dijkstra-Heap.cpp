#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long

const int MAX=0x7fffffffffffffff;
const int mod=998244353;
const int INF=4e18;

struct Edge
{
    int v,w;
};


int n,m,s;
vector<int>dist;
vector<vector<Edge>>edge;

void Dijkstra()
{
    priority_queue<pair<int,int>>q;
    dist.assign(n+1,INF);
    q.push({0,s});
    dist[s]=0;
    while(!q.empty())
    {
        auto [d,u]=q.top();
        q.pop();
        d=-d;
        if(d>dist[u])continue;
        for(auto [v,w]:edge[u])
        {
            if(d+w<dist[v])
            {
                dist[v]=d+w;
                q.push({-dist[v],v});
            }
        }
    }
}

void sol()
{
    cin>>n>>m>>s;
    edge.assign(n+1,{});
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edge[u].push_back({v,w});
    }
    Dijkstra();
    for(int i=1;i<=n;i++)
    {
        cout<<dist[i]<<' ';
    }
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