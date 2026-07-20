#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long

struct MCMF
{
    struct Edge
    {
        int to,cap,cost,rev;
    };
    
    int N,S,T,MC,MF;
    const int INF=2e18;
    vector<vector<Edge>>e;
    vector<int>cur,dist,vis;

    MCMF(int n,int s,int t):N(n),S(s),T(t),MC(0),MF(0)
    {
        e.assign(n+1,vector<Edge>());
        cur.assign(n+1,0);
        dist.assign(n+1,0);
        vis.assign(n+1,0);
    }

    void add_edge(int u,int v,int cap,int cost)
    {
        e[u].emplace_back(v,cap,cost,e[v].size());
        e[v].emplace_back(u,0,-cost,e[u].size()-1);
    }

    bool SPFA()
    {
        fill(begin(dist),end(dist),INF);
        fill(begin(vis),end(vis),0);
        fill(begin(cur),end(cur),0);        //重置当前弧
        queue<int>q;
        dist[S]=0;
        vis[S]=1;
        q.emplace(S);
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            vis[u]=0;
            for(auto [v,c,m,r]:e[u])
            {
                if(c&&dist[u]+m<dist[v])
                {
                    dist[v]=dist[u]+m;
                    if(!vis[v])
                    {
                        vis[v]=1;
                        q.emplace(v);
                    }
                }
            }
        }
        return dist[T]!=INF;
    }

    int DFS(int u,int f)
    {
        if(u==T||f==0)return f;
        vis[u]=1;               //防止出现0费用环
        int ret=0;
        for(int &i=cur[u];i<(int)e[u].size();i++)
        {
            auto &[v,c,m,r]=e[u][i];
            if(vis[v]||c==0||dist[v]!=dist[u]+m)continue;
            int tf=DFS(v,min(f-ret,c));
            if(tf==0)continue;
            c-=tf;
            e[v][r].cap+=tf;
            ret+=tf;
            MC+=tf*m;
            if(f==ret)break;
        }
        vis[u]=0;
        return ret;
    }

    void mcmf()
    {
        while(SPFA())MF+=DFS(S,INF);
    }
};


signed main()
{
    int n,m,s,t;
    cin>>n>>m>>s>>t;
    MCMF D(n,s,t);
    for(int i=1;i<=m;i++)
    {
        int u,v,w,c;
        cin>>u>>v>>w>>c;
        D.add_edge(u,v,w,c);
    }
    D.mcmf();
    cout<<D.MF<<' '<<D.MC;
}