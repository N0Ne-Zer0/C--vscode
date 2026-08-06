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

void sol()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>s(n+1,0),c(n+1,0),res(n+1,0);
    vector<vector<int>>e(n+1);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for(int i=1;i<=k;i++)
    {
        int u;
        cin>>u;
        s[u]=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(!s[i])continue;
        for(auto v:e[i])
        {
            if(s[v])continue;
            c[v]++;
        }
    }
    queue<int>q;
    vector<int>CNT(n+1,0),fg(n+1,0);
    for(int i=1;i<=n;i++)
    {
        if(c[i]>=2)
        {
            q.push(i);
            fg[i]=1;
        }
    }
    while(q.size())
    {
        int u=q.front();
        q.pop();
        for(auto v:e[u])
        {
            if(s[v]||fg[v])continue;
            CNT[v]++;
            bool f=0;
            if(CNT[v]>=2)f=1;
            else if(CNT[v]&&c[v])f=1;
            if(f)
            {
                fg[v]=1;
                q.push(v);
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(s[i])continue;
        if(c[i])res[i]=1;
        else if(CNT[i])res[i]=1;
    }

    int cnt=0;
    for(int i=1;i<=n;i++)if(res[i])cnt++;
    cout<<cnt<<'\n';
    for(int i=1;i<=n;i++)
    {
        if(res[i])cout<<i<<' ';
    }
    cout<<'\n';
}
/*
1
12 11 6
2 4
2 3
1 2
1 5
1 6
6 7
6 8
8 9
9 10
9 11
8 12
3 4 5 7 10 11

*/

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