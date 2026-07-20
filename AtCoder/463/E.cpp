#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long

const int maxn=2e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=998244353;
const int INF=1e9;


void sol()
{
    int N,M,Y;
    cin>>N>>M>>Y;
    vector<vector<pair<int,int>>>mp(N+1);
    vector<int>X(N+1);
    vector<int>res(N+1,MAX);
    for(int i=1;i<=M;i++)
    {
        int u,v,t;
        cin>>u>>v>>t;
        mp[u].emplace_back(v,t);
        mp[v].emplace_back(u,t);
    }
    for(int i=1;i<=N;i++)
    {
        cin>>X[i];
    }
    mp[N+1].emplace_back(N+2,Y);
    for(int i=1;i<=N;i++)
    {
        mp[i].emplace_back(N+1,X[i]);
        mp[N+2].emplace_back(i,X[i]);
    }
    priority_queue<pair<int,int>>que;
    que.emplace(0,1);
    res[1]=0;
    while(que.size())
    {
        auto [t,u]=que.top();
        que.pop();
        t=-t;
        if(t>res[u])continue;
        for(auto [v,T]:mp[u])
        {
            if(res[v]>res[u]+T)
            {
                res[v]=res[u]+T;
                que.emplace(-res[v],v);
            }
        }
    }
    for(int i=2;i<=N;i++)cout<<res[i]<<' ';
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