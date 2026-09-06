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

int n,m;
vector<vector<int>>dist;

void Floyd(){
    for(int k=1;k<=n;k++){
        for(int u=1;u<=n;u++){
            for(int v=1;v<=n;v++){
                if(u==v)dist[u][v]=0;
                if(dist[u][v]>dist[u][k]+dist[k][v]){
                    dist[u][v]=dist[u][k]+dist[k][v];
                    dist[v][u]=dist[v][k]+dist[k][u];
                }
            }
        }
    }
}

void sol(){
    cin>>n>>m;
    dist.assign(n+1,vector<int>(n+1,INF));
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        dist[u][v]=min(dist[u][v],w);
        dist[v][u]=min(dist[v][u],w);
    }
    Floyd();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<dist[i][j]<<' ';
        }
        cout<<'\n';
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