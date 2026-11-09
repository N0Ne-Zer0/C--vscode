#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=5e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=998244353;
const int INF=1e9;

void sol(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>g(n+1);
    vector<vector<int>>tele(n+1);
    vector<int>dist(n+1,MAX);
    for(int i=1;i<n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        tele[u].push_back(v);
        tele[v].push_back(u);
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    dist[1]=0;
    q.push({0,1});
    while(!q.empty()){
        auto[d,u]=q.top();q.pop();
        if(d>dist[u])continue;
        for(auto[v,w]:g[u]){
            if(d+w<dist[v]){
                dist[v]=d+w;
                q.push({dist[v],v});
            }
        }
    }
    vector<int>ans(n+1,0);
    for(int i=1;i<=n;i++){
        ans[0]+=dist[i];
    }
    for(int k=1;k<=n;k++){
        vector<int>new_dist(dist);
        for(int u=1;u<=n;u++){
            for(auto v:tele[u]){
                if(dist[v]<new_dist[u]){
                    new_dist[u]=dist[v];
                }
            }
        }
        for(int u=1;u<=n;u++)q.push({new_dist[u],u});
        while(!q.empty()){
            auto[d,u]=q.top();q.pop();
            if(d>new_dist[u])continue;
            for(auto[v,w]:g[u]){
                if(d+w<new_dist[v]){
                    new_dist[v]=d+w;
                    q.push({new_dist[v],v});
                }
            }
        }
        for(int u=1;u<=n;u++)ans[k]+=new_dist[u];
        dist=new_dist;
    }
    for(auto x:ans)cout<<x<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    T = 1;
    // cin>>T;
    while (T--)sol();
}