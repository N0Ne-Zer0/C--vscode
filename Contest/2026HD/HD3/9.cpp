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
const int inv2=499122177;


void sol()
{
    int n,res=0;
    cin>>n;
    vector<vector<int>>edge(n+1);
    vector<int>deg(n+1,0);
    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    queue<int>q;
    for(int i=1;i<=n;i++)if(deg[i]==1)q.push(i);
    while(q.size())
    {
        int u=q.front();
        q.pop();
        res++;
        for(auto v:edge[u])
        {
            if(deg[v]>1)
            {
                deg[v]--;
                if(deg[v]==1)
                {
                    q.push(v);
                }
            }
        }
    }
    res+=(n-res)*inv2%mod;
    cout<<res<<'\n';
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    T = 1;
    cin>>T;
    while (T--)sol();
    // system("pause");
}