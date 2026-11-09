#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=5e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=998244353;
const int INF=1e9;

struct Node{
    int v,w;
};

struct Q{
    int cnt,cost,u;
    bool operator<(const Q &other)const{
        if(cnt==other.cnt)return cnt<other.cnt;
        return cost<other.cost;
    }
};
void sol(){
    int n,m,V,T;
    cin>>n>>m>>V>>T;
    vector<vector<Node>>g(n+1);
    vector<int>ans(n+1,INF),dist(n+1,INF);
    auto add_edge=[&](int u,int v,int w)->void{
        g[v].push_back({u,w});
        g[u].push_back({v,w});
    };
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        add_edge(u,v,w);
    }
    priority_queue<Q>q;
    q.push(Q{1,0,T});
    ans[T]=1;
    while(!q.empty()){
        auto[cnt,cost,u]=q.top();q.pop();
        if(cnt>ans[u]||cnt==ans[u]&&cost>dist[u])continue;
        for(auto [v,w]:g[u]){
            if(w>V)continue;
            int ccnt,ccost;
            if(cost+w<=V){
                ccnt=cnt,ccost=cost+w;
            }
            else ccnt=cnt+1,ccost=w;
            if(ccnt<ans[v]){
                ans[v]=ccnt;
                dist[v]=ccost;
                q.push({ans[v],dist[v],v});
            }
            else if(ccnt==ans[v]&&ccost<dist[v]){
                ans[v]=ccnt;
                dist[v]=ccost;
                q.push({ans[v],dist[v],v});
            }
        }
    }
    for(int i=1;i<=n;i++){

        if(ans[i]==INF)cout<<"-1 ";
        else cout<<ans[i]<<' ';
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    T = 1;
    // cin>>T;
    while (T--)sol();
}