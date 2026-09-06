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

struct EDCC{
    struct Edge{int to,id;};
    int n,timer,dccCnt,edgeCnt;
    vector<vector<Edge>>g;
    vector<pair<int,int>>edges;
    vector<int>dfn,low,belong,bridge;
    vector<vector<int>>tree;
    EDCC(int n):n(n),g(n+1),dfn(n+1),low(n+1),belong(n+1,-1){}

    void addEdge(int u,int v){//无向图
        g[u].push_back({v,edgeCnt});
        g[v].push_back({u,edgeCnt});
        edges.push_back({u,v});
        edgeCnt++;
    }

    void dfs(int u,int peid){
        dfn[u]=low[u]=++timer;
        for(auto &e:g[u]){
            int v=e.to,id=e.id;
            if(id==peid)continue;//跳过反向边/父边
            if(!dfn[v]){
                dfs(v,id);
                low[u]=min(low[u],low[v]);
                if(low[v]>dfn[u])bridge[id]=1;
            }
            else{
                low[u]=min(low[u],dfn[v]);
            }
        }
    }

    void flood(int u,int c){
        belong[u]=c;
        for(auto &e:g[u]){
            if(!bridge[e.id]&&belong[e.to]==-1)flood(e.to,c);
        }
    }

    int run(){
        bridge.assign(edgeCnt,0);
        for(int i=1;i<=n;i++)if(!dfn[i])dfs(i,-1);
        dccCnt=0;
        for(int i=1;i<=n;i++)if(belong[i]==-1)flood(i,dccCnt++);
        return dccCnt;
    }

    void buildTree(){
        tree.assign(dccCnt,{});
        for(int id=0;id<edgeCnt;id++){
            if(!bridge[id])continue;
            int a=belong[edges[id].first];
            int b=belong[edges[id].second];
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
    }
};

void sol()
{
    
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