#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std;
#define int long long
#define endl '\n'

const int maxn=3e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=998244353;
const int INF=1e9;

void sol()
{
    int n,res=0;
    cin>>n;
    vector<int>a(n),b(n),c(n);
    bitset<2001>vis;
    vis.reset();
    for(auto &x:a)cin>>x;
    for(auto &x:b)cin>>x;
    for(int i=0;i<n;i++)
    {
        int j=0;
        for(;j<n;j++)
        {
            if(a[i]<=b[j]&&vis[j]==0)
            {
                c[i]=j;
                vis[j]=1;
                break;
            }
        }
        if(j==n)
        {
            cout<<"-1\n";
            return;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(c[i]>c[j])res++;
        }
    }
    cout<<res<<'\n';
}


signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    T = 1;
    cin>>T;
    while (T--)
    {
        sol();
    }
}