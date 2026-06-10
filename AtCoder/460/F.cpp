// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
#define int long long

const int maxn=3e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=1e9+7;

int dist(int x,int y);

struct Node
{
    int x,y,d;
    Node(int x=0,int y=0):x(x),y(y),d(dist(x,y)){}
    bool operator<(const Node& t)const
    {
        return d<t.d;
    }
};

vector<int>dep,col;
vector<vector<int> >tree,f;
vector<Node>segtre;

void dfs(int x,int fa)
{
    dep[x]=dep[fa]+1;
    f[x][0]=fa;
    for(int i=1;i<=20;i++)
    {
        f[x][i]=f[f[x][i-1]][i-1];
    }
    for(auto c:tree[x])
    {
        if(c==fa)continue;
        dfs(c,x);
    }
}

int lca(int x,int y)
{
    if(dep[x]!=dep[y])
    {
        if(dep[x]<dep[y])swap(x,y);
        int tem=dep[x]-dep[y],i=0;
        while(tem)
        {
            if(tem&1)x=f[x][i];
            tem>>=1;
            i++;
        }
    }
    if(x==y)return x;
    for(int i=20;i>=0;i--)
    {
        if(f[x][i]==f[y][i])continue;
        x=f[x][i];
        y=f[y][i];
    }
    return f[x][0];
}

int dist(int x,int y)
{
    if(x==0||y==0)return -1;
    if(x==y)return 0;
    return dep[x]+dep[y]-2*dep[lca(x,y)];
}

Node merge(int x,int y)
{
    Node res=max(segtre[x],segtre[y]);
    res=max(res,Node(segtre[x].x,segtre[y].x));
    res=max(res,Node(segtre[x].x,segtre[y].y));
    res=max(res,Node(segtre[x].y,segtre[y].x));
    res=max(res,Node(segtre[x].y,segtre[y].y));
    return res;
}

void build(int x,int l,int r)
{
    if(l==r)
    {
        segtre[x]=Node(l,l);
        return;
    }
    int mid=(l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    segtre[x]=merge(x<<1,x<<1|1);
}

void update(int x,int l,int r,int pos)
{
    if(l==r)
    {
        col[l]^=1;
        if(col[l])segtre[x]=Node(l,l);
        else segtre[x]=Node(0,0);
        return;
    }
    int mid=(l+r)>>1;
    if(pos>=mid+1)update(x<<1|1,mid+1,r,pos);
    else update(x<<1,l,mid,pos);
    segtre[x]=merge(x<<1,x<<1|1);
}

void sol()
{
    int N;
    cin>>N;
    dep.assign(N+1,0);
    col.assign(N+1,1);
    tree.assign(N+1,vector<int>(0));
    f.assign(N+1,vector<int>(22));
    segtre.assign(N<<2,Node());
    for(int i=1;i<=N-1;i++)
    {
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1,0);
    build(1,1,N);
    int Q;
    cin>>Q;
    while(Q--)
    {
        int x;
        cin>>x;
        update(1,1,N,x);
        cout<<segtre[1].d<<'\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=1;
    // cin>>T;
    while(T--)sol();
}
