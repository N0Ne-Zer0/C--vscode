#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long

const int INF=1e18;

struct DinicMaxFlow
{
    struct Edge
    {
        int to,cap,rev;
    };
    
    int N,S,T;
    const int INF=2e18;
    vector<vector<Edge>>e;
    vector<int>cur,level;

    DinicMaxFlow(int n,int s,int t):N(n),S(s),T(t)
    {
        e.assign(n+1,{});
        cur.assign(n+1,0);
        level.assign(n+1,0);
    }

    void add_edge(int u,int v,int cap)
    {
        e[u].emplace_back(v,cap,e[v].size());
        e[v].emplace_back(u,0,e[u].size()-1);
    }

    bool BFS()
    {
        fill(begin(level),end(level),0);    //分层图
        fill(begin(cur),end(cur),0);        //重置当前弧
        queue<int>q;
        level[S]=1;
        q.emplace(S);
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(auto [v,c,r]:e[u])
            {
                if(level[v]||c==0)continue;
                level[v]=level[u]+1;
                q.emplace(v);
            }
        }
        return level[T];
    }

    int DFS(int u,int f)
    {
        if(u==T||f==0)return f;
        int ret=0;                                  //多路增广
        for(int &i=cur[u];i<(int)e[u].size();i++)   //&i=cur[u],当前弧优化
        {
            auto &[v,c,r]=e[u][i];
            if(c==0||level[v]!=level[u]+1)continue;
            int tf=DFS(v,min(f-ret,c));
            if(tf==0)continue;
            c-=tf;
            e[v][r].cap+=tf;
            ret+=tf;
            if(f==ret)break;
        }
        return ret;
    }

    int MaxFlow()
    {
        int res=0;
        while(BFS())res+=DFS(S,INF);
        return res;
    }
};

void sol()
{
    int n,m,g,res=0;
    cin>>n>>m>>g;
    int s=0,t=n+m+1;
    DinicMaxFlow G(t,s,t);
    vector<int>gender(n+1),v(n+1);
    for(int i=1;i<=n;i++)cin>>gender[i];
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        if(gender[i])
        {
            G.add_edge(s,i,v[i]);
        }
        else
        {
            G.add_edge(i,t,v[i]);
        }
    }
    int idx=n;
    vector<int>tem(20);
    for(int i=1;i<=m;i++)
    {
        int ge,w,k,fr;
        cin>>ge>>w>>k;
        res+=w;
        for(int j=1;j<=k;j++)cin>>tem[j];
        cin>>fr;
        if(fr)w+=g;
        if(ge)
        {
            G.add_edge(s,++idx,w);
            for(int j=1;j<=k;j++)G.add_edge(idx,tem[j],INF);
        }
        else
        {
            G.add_edge(++idx,t,w);
            for(int j=1;j<=k;j++)G.add_edge(tem[j],idx,INF);
        }
    }
    cout<<res-G.MaxFlow();
}

signed main()
{
    int T=1;
    // cin>>T;
    while(T--)sol();
}