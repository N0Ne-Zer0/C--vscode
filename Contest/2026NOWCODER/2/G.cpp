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

bool check(int x,int y)
{
    return __gcd(x,y)==1;
}

struct Edge
{
    int v,w;
};


int n,m,s;
vector<int>dist;
vector<vector<Edge>>edge;

void Dijkstra()
{
    priority_queue<pair<int,int>>q;
    dist.assign(n+1,INF);
    q.emplace(0,s);
    dist[s]=0;
    while(!q.empty())
    {
        auto [d,u]=q.top();
        q.pop();
        d=-d;
        if(d>dist[u])continue;
        for(auto [v,w]:edge[u])
        {
            if(d+w<dist[v])
            {
                dist[v]=d+w;
                // cout<<u<<' '<<v<<' '<<dist[v]<<'\n';
                q.emplace(-dist[v],v);
            }
        }
    }
}

void sol()
{
    int l,r,res=0,cnt=0;
    cin>>l>>r>>n;

    vector<int>prime;
    int tmp=n;
    for(int i=2;i*i<=n;i++)
    {
        if(tmp%i==0)
        {
            prime.push_back(i);
            while(tmp%i==0)
            {
                tmp/=i;
            }
        }
    }
    if(tmp>1)prime.push_back(tmp);
    vector<bool>coprime(n,1);
    for(auto p:prime)
    {
        for(int i=p;i<n;i+=p)
        {
            coprime[i]=0;
        }
    }
    int tr=max(l,r-500);
    if(r<tr)
    {
        for(int i=l;i<=r;i++)
        {
            if(coprime[i])
            {
                cnt++;
            }
        }
        res=(r-l+1)*2-cnt;
    }
    else
    {
        for(int i=l;i<tr;i++)
        {
            if(coprime[i])
            {
                cnt++;
            }
        }
        res=(tr-l)*2-cnt;

        edge.assign(n+1,vector<Edge>());
        for(int i=n;i>tr;i--)
        {
            for(int j=i-1;j>=tr;j--)
            {
                edge[i].push_back({j,__gcd(i,j)});
            }
        }
        s=n;
        Dijkstra();
        for(int i=tr;i<=r;i++)res+=dist[i];
    }
    cout<<res<<'\n';
}

signed main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int T;
    T = 1;
    cin>>T;
    while (T--)sol();
    system("pause");
}