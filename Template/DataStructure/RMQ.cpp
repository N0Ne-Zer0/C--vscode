// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
#define int long long

const int maxn=3e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=1e9+7;

typedef int T;
struct RMQ
{
    vector<int>lg;
    vector<vector<T>>ST;
    int N;

    RMQ(int n,vector<T>&a):N(n)
    {
        lg.assign(n+1,0);
        ST.assign(21,vector<T>(n+1));
        for(int i=1;i<=n;i++)ST[0][i]=a[i];
        for(int i=2;i<=N;i++)lg[i]=lg[i/2]+1;
        build();
    }

    inline T merge(T a,T b)
    {
        return max(a,b);
    }

    void build()
    {
        for(int i=1;i<20;i++)
        {
            int len=1<<i;
            for(int j=1;j+len-1<=N;j++)
            {
                ST[i][j]=merge(ST[i-1][j],ST[i-1][j+(1<<(i-1))]);
            }
        }
    }

    inline T search(int l,int r)
    {
        int len=r-l+1;
        int t=lg[len];
        return merge(ST[t][l],ST[t][r-(1<<t)+1]);
    }
};

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,M;
    cin>>N>>M;
    vector<int>a(N+1,0);
    for(int i=1;i<=N;i++)cin>>a[i];
    RMQ ST(N,a);
    while(M--)
    {
        int l,r;
        cin>>l>>r;
        cout<<ST.search(l,r)<<'\n';
    }
}
