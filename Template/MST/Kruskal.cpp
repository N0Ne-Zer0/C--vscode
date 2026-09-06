#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
#define int long long

const int maxn=3e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=998244353;
const int INF=1e9;

struct Edge{
    int u,v,w;
    bool operator<(const Edge&other)const{
        return w<other.w;
    }
};
int n,m;
vector<Edge>edge;
vector<int>F;

int Find(int x){
    if(F[x]==x)return x;
    return F[x]=Find(F[x]);
}

void Unite(int x,int f){
    F[Find(x)]=Find(f);
}

void Kruskal(){
    int cnt=1,res=0;
    iota(begin(F),end(F),0);
    sort(begin(edge),end(edge));
    for(auto &[u,v,w]:edge){
        if(Find(u)==Find(v))continue;
        Unite(u,v);
        cnt++;
        res+=w;
    }
    if(cnt<n){
        cout<<"orz";
        return;
    }
    cout<<res;
}

void sol(){
    cin>>n>>m;
    edge.clear();
    edge.reserve(m);
    F.assign(n+1,0);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edge.push_back({u,v,w});
    }
    Kruskal();
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