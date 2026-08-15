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

bool SPFA()
{
    dist.assign(n+1,INF);
    dist[s]=0;
    queue<int>q;
    vector<int>vis(n+1,0),cnt(n+1,0);
    q.push(s);
    vis[s]=1;
    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=0;
        if(dist[u]==INF)continue;
        for(auto [v,w]:edge[u])
        {
            if(dist[u]+w<dist[v])
            {
                dist[v]=dist[u]+w;
                cnt[v]++;
                if(cnt[v]>=n)return false;
                if(!vis[v])
                {
                    q.push(v);
                    vis[v]=1;
                }
            }
        }
    }
    return true;
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
    SPFA();
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