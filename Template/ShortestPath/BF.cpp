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

bool BF()
{
    dist.assign(n+1,INF);
    dist[s]=0;
    for(int i=1;i<=n-1;i++)
    {
        bool fg=0;
        for(int u=1;u<=n;u++)
        {
            for(auto [v,w]:edge[u])
            {
                if(dist[v]>dist[u]+w)
                {
                    fg=1;
                    dist[v]=dist[u]+w;
                }
            }
        }
        if(!fg)break;
    }

    for(int u=1;u<=n;u++)
    {
        for(auto [v,w]:edge[u])
        {
            if(dist[v]>dist[u]+w)
            {
                return 1;
            }
        }
    }
    return 0;
}

void sol()
{
    cin>>n>>m>>s;
    edge.assign(n+1,vector<Edge>());
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edge[u].emplace_back(v,w);
    }
    BF();
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