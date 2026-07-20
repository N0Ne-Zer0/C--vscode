// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<map>
#include<cmath>
using namespace std;
#define int long long

const int maxn=2e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=998244353;
const int INF=1e9+1;

void sol()
{
    int n,q;
    cin>>n>>q;
    vector<pair<int,int>>L(n);
    for(auto&[k,b]:L)cin>>k>>b;

    auto D=[](pair<int,int>A,pair<int,int>B)->pair<double,double>
    {
        auto[k1,b1]=A;
        auto[k2,b2]=B;
        if(k1==k2&&b1==b2)return pair<double,double>(INF,INF);
        if(k1==k2)return pair<double,double>(-INF,-INF);
        return pair<double,double>((b1-b2)/(k2-k1),(b1*k2-b2*k1)/(k2-k1));
    };

    int cnt=0;
    map<pair<double,double>,int>mp;
    mp[{-INF,-INF}]=0;
    mp[{INF,INF}]=INF;

    vector<vector<int>>ST(n,vector<int>(22,INF));

    for(int i=1;i<22;i++)
    {
        int len=(1<<i);
        for(int j=0;j+len<=n;j++)
        {
            int l=ST[j][i-1],r=ST[j+(len>>1)][i-1];
            if(l==0||r==0)
            {
                ST[j][i]=0;
            }
            else if(l==INF||r==INF)
            {
                auto tem=D(L[j],L[j+(len>>1)]);
                if(mp.find(tem)==mp.end())
                {
                    mp[tem]=++cnt;
                }

                if(l==INF&&r==INF)
                {
                    ST[j][i]=mp[tem];
                }
                else if(l==INF)
                {
                    ST[j][i]=((mp[tem]==r||mp[tem]==INF)?r:0);
                }
                else
                {
                    ST[j][i]=((mp[tem]==l||mp[tem]==INF)?l:0);
                }
            }
            else
            {
                ST[j][i]=(l==r?l:0);
            }
        }
    }

    auto search=[&](int l,int r)->bool
    {
        int i=log2(r-l+1);
        int x=ST[l][i],y=ST[r-(1<<i)+1][i];
        if(x==0||y==0)
        {
            return 0;
        }
        else return (x==y||x==INF||y==INF);
    };

    while(q--)
    {
        int l,r;
        cin>>l>>r;
        if(search(l-1,r-1))cout<<"Yes\n";
        else cout<<"No\n";
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
