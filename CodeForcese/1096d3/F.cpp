// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define int long long

const int maxn=2e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=1e9+7;

inline int lb(int x)
{
    return -x&x;
}
inline void add(vector<int>&BIT,int x,int v=1)
{
    for(int i=x;i<BIT.size();i+=lb(i))
    {
        BIT[i]+=v;
    }
}
inline int search(const vector<int>&BIT,int x)
{
    int res=0;
    for(int i=x;i>0;i-=lb(i))
    {
        res+=BIT[i];
    }
    return res;
}


inline void sol()
{
    int n;
    cin>>n;
    int res=0;
    vector<int>a(n+1),th(n+1);
    vector<int>B(n+1,0),Bi(n+1,0),bk(n+1,0);
    vector<int>cnt(n+1,0),suf(n+1,0);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=n;i>=1;i--)
    {
        res+=a[i]*(n-i);
        res-=search(Bi,a[i]-1)+a[i]*(search(B,n)-search(B,a[i]-1));
        th[i]=search(B,a[i])-search(B,a[i]-1);
        add(B,a[i]);
        add(Bi,a[i],a[i]);
    }
    int ti=0,bns=0;
    for(int i=1;i<=n;i++)
    {
        int tem=search(bk,n)-search(bk,a[i]-1)+th[i];
        if(tem>bns)
        {
            ti=i;
            bns=tem;
        }
        add(bk,a[i]);
    }
    cout<<res+bns<<'\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=1;
    cin>>T;
    while(T--)sol();
}
