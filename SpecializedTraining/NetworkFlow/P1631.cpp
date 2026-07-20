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
    int n,m,res=0;
    cin>>n;
    vector<int>a(n+1),b(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    cin>>m;
    int s=0,t=n+2*m+1;
    DinicMaxFlow D(t,s,t);
    for(int i=1;i<=n;i++)
    {
        res+=a[i];
        D.add_edge(s,i,a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        res+=b[i];
        D.add_edge(i,t,b[i]);
    }
    for(int i=1;i<=m;i++)
    {
        int k,c1,c2,p1,p2;
        cin>>k>>c1>>c2;
        res+=c1+c2;
        p1=n+i*2-1;
        p2=n+i*2;
        D.add_edge(s,p1,c1);
        D.add_edge(p2,t,c2);
        while(k--)
        {
            int x;
            cin>>x;
            D.add_edge(p1,x,INF);
            D.add_edge(x,p2,INF);
        }
    }
    res-=D.MaxFlow();
    cout<<res;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T=1;
    // cin>>T;
    while(T--)sol();
}