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

struct Edge
{
    int v,w;
};


int n,m,s;
vector<int>dist;
vector<vector<Edge>>edge;

void Dijkstra()
{
    dist.assign(n+1,INF);
    dist[s]=0;
    vector<bool>vis(n+1,0);
    for(int i=1;i<=n;i++)
    {
        int u=-1,d=INF;
        for(int j=1;j<=n;j++)
        {
            if(vis[j]||dist[j]>=d)continue;
            u=j;
            d=dist[j];
        }
        if(u==-1)break;
        vis[u]=1;
        for(auto [v,w]:edge[u])
        {
            dist[v]=min(dist[v],dist[u]+w);
        }
    }
}

void sol()
{
    cin>>n>>m>>s;
    edge.assign(n+1,vector<Edge>());
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