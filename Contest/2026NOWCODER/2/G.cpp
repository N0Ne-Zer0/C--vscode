#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long

const int maxn=1e7+5;
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


int n,l,r,s,tr;
vector<int>dist;
vector<vector<Edge>>edge;

void Dijkstra()
{
    dist.assign(n-tr+1,INF);
    dist[s]=0;
    vector<bool>vis(n-tr+1,0);
    for(int i=0;i<=n-tr;i++)
    {
        int u=-1,d=INF;
        for(int j=0;j<=n-tr;j++)
        {
            if(vis[j]||dist[j]>=d)continue;
            u=j;
            d=dist[j];
        }
        if(u==-1)break;
        vis[u]=1;
        for(auto [v,w]:edge[u])
        {
            dist[v]=min(dist[v],dist[u]+w);
        }
    }
}

vector<int>mu(maxn),prime,vis(maxn);

void ini()
{
    mu[1]=1;
    for(int i=2;i<maxn;i++)
    {
        if(!vis[i])
        {
            mu[i]=-1;
            prime.push_back(i);
        }
        for(auto p:prime)
        {
            if(i*p>=maxn)break;
            vis[i*p]=1;
            if(i%p==0)
            {
                mu[i*p]=0;
                break;
            }
            else
            {
                mu[i*p]=-mu[i];
            }
        }
    }
}

int countCoprime(int x,int n)
{
    if(x<=0)return 0;
    int res=0;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i)continue;
        res+=mu[i]*(x/i);
        int d=n/i;
        if(i!=d)res+=mu[d]*(x/d);
    }
    return res;
}

void sol()
{
    cin>>l>>r>>n;
    tr=max(l,min(r,n-150));

    //处理[l,tr]
    int cnt=countCoprime(tr,n)-countCoprime(l-1,n);
    int res=(tr-l+1)*2-cnt;
    if(tr==r)
    {
        cout<<res<<'\n';
        return;
    }
    
    //处理(tr,r]
    edge.assign(n-tr+1,{});
    for(int i=tr+1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            edge[j-tr].push_back({i-tr,__gcd(i,j)});
        }
    }
    s=n-tr;
    Dijkstra();
    for(int i=tr+1;i<=r;i++)res+=dist[i-tr];
    cout<<res<<'\n';
}

signed main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    ini();
    int T;
    T = 1;
    cin>>T;
    while (T--)sol();
    system("pause");
}