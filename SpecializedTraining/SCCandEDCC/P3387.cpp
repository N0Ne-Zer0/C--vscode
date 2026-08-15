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

struct SCC
{
    int n,timer,sccCnt;
    vector<vector<int>>g,dag;
    vector<int>dfn,low,stk,inStk,belong;
    vector<int>indeg,outdeg;

    SCC(int n):n(n),g(n+1),dfn(n+1),low(n+1),inStk(n+1),belong(n+1,-1){}
    
    void addEdge(int u,int v){g[u].push_back(v);}//有向图
    void dfs(int u)
    {
        dfn[u]=low[u]=++timer;
        stk.push_back(u);
        inStk[u]=1;
        for(auto v:g[u])
        {
            if(!dfn[v])
            {
                dfs(v);
                low[u]=min(low[u],low[v]);
            }
            else if(inStk[v])
            {
                low[u]=min(low[u],dfn[v]);
            }
        }
        if(low[u]==dfn[u])
        {
            while(1)
            {
                int x=stk.back();
                stk.pop_back();
                inStk[x]=0;
                belong[x]=sccCnt;
                if(x==u)break;
            }
            sccCnt++;
        }
    }
    int run()//返回scc数量，scc标号为[0,sccCnt)
    {
        timer=sccCnt=0;
        for(int i=1;i<=n;i++)if(!dfn[i])dfs(i);
        return sccCnt;
    }
    void shrink()
    {
        dag.assign(sccCnt,{});
        indeg.assign(sccCnt,0);
        outdeg.assign(sccCnt,0);
        for(int u=1;u<=n;u++)
        {
            for(int v:g[u])
            {
                int a=belong[u],b=belong[v];
                if(a!=b)
                {
                    dag[a].push_back(b);
                    indeg[b]++;
                    outdeg[a]++;
                }
            }
        }
    }
};

void sol()
{
    int n,m;
    cin>>n>>m;
    vector<int>a(n+1);
    SCC scc(n);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        scc.addEdge(u,v);
    }
    int N=scc.run();
    scc.shrink();
    queue<int>q;
    vector<int>dp(N,0),w(N,0);
    for(int u=1;u<=n;u++)
    {
        w[scc.belong[u]]+=a[u];
    }
    for(int i=0;i<N;i++)
    {
        if(scc.indeg[i]==0)
        {
            q.push(i);
            dp[i]=w[i];
        }
    }
    while(q.size())
    {
        int u=q.front();
        q.pop();
        for(auto v:scc.dag[u])
        {
            dp[v]=max(dp[v],dp[u]+w[v]);
            if(--scc.indeg[v]==0)q.push(v);
        }
    }
    int ans=0;
    for(int i=0;i<N;i++)
    {
        ans=max(ans,dp[i]);
    }
    cout<<ans<<'\n';
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