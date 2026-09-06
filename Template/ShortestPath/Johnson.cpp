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

struct Edge{
    int v,w;
};
int n,m;
vector<int>h;
vector<vector<Edge>>edge;
vector<vector<int>>dist;

bool SPFA(int s){
    h.assign(n+1,INF);
    h[s]=0;
    queue<int>q;
    vector<int>vis(n+1,0),cnt(n+1,0);
    q.push(s);
    vis[s]=1;
    while (!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(auto [v,w]:edge[u]){
            if(h[u]+w<h[v]){
                h[v]=h[u]+w;
                if(!vis[v]){
                    q.push(v);
                    vis[v]=1;
                    cnt[v]++;
                    if(cnt[v]>=n)return true;
                }
            }
        }
    }
    return false;
}

void Dijkstra(int s){
    priority_queue<pair<int,int>>q;
    q.push({0,s});
    dist[s][s]=0;
    while(!q.empty()){
        auto[d,u]=q.top();
        q.pop();
        d=-d;
        if(d>dist[s][u])continue;
        for(auto [v,w]:edge[u]){
            if(dist[s][v]>d+w){
                dist[s][v]=d+w;
                q.push({-dist[s][v],v});
            }
        }
    }
}

void Johnson(){
    for(int i=1;i<=n;i++){
        edge[0].push_back({i,0});
    }
    if(SPFA(0)){
        cout<<-1;
        return;
    }
    dist.assign(n+1,vector<int>(n+1,INF));
    for(int u=1;u<=n;u++){
        for(auto &[v,w]:edge[u]){
            w=w+h[u]-h[v];      //dist[v]<=dist[u]+w边权转化
        }
    }
    for(int i=1;i<=n;i++)Dijkstra(i);
    for(int i=1;i<=n;i++){
        int res=0;
        for(int j=1;j<=n;j++){
            if(dist[i][j]!=INF)dist[i][j]=dist[i][j]-h[i]+h[j];
            res+=j*dist[i][j];
        }
        cout<<res<<'\n';
    }
}

void sol(){
    cin>>n>>m;
    edge.assign(n+1,vector<Edge>());
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edge[u].push_back({v,w});
    }
    Johnson();
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    T = 1;
    // cin>>T;
    while (T--)sol();
}