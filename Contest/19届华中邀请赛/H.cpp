#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
#define int long long

const int maxn=1e5+5;
const int mod=1e9+7;

struct Node
{
    int cnt,ls,rs;
    int s1,s2,C;
};

struct S
{
    int l,r,i;
    int A;
};

inline int lb(int x)
{
    return -x&x;
}

inline void add(vector<int>&BIT,int x,int v)
{
    for(size_t i=x;i<BIT.size();i+=lb(i))
    {
        BIT[i]+=v;
    }
}

inline int search(const vector<int>&BIT,int x)
{
    int res=0;
    for(int i=x;i;i-=lb(i))
    {
        res+=BIT[i];
    }
    return res;
}

void sol()
{
    int n,q;
    cin>>n>>q;
    vector<int>a(n+1);
    vector<S>ans(q);
    vector<int>tr1(n+1,0),tr2(n+1,0);
    int B=ceil(1.0*n/sqrt(q));
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<q;i++)
    {
        auto &[l,r,t,A]=ans[i];
        cin>>l>>r;
        t=i;
        A=0;
    }
    sort(ans.begin(),ans.end(),[&](S x,S y)->bool
    {
        if((x.l-1)/B==(y.l-1)/B)return x.r<y.r;
        return (x.l-1)/B<(y.l-1)/B;
    });
    int curL=1,curR=n+2;//[curL,curR)
    for(int i=0;i<q;i++)
    {
        auto &[l,r,k,A]=ans[i];
        if(curR>r+1)
        {
            tr1.assign(n+1,0);
            tr2.assign(n+1,0);
            curL=curR=l;
        }
        while(curR<=r)
        {
            int L=curR-curL;
            int x=a[curR];
            int t=min(x,L+1);
            add(tr1,x,1);
            add(tr2,x,t*(t+1)/2);
            int tem=search(tr1,n)-search(tr1,L);
            A+=(x*(1+x)/2+2*search(tr2,n)+(L+1)*tem*tem%mod)%mod;
            A%=mod;
            curR++;
        }
        while(curL<l)
        {
            int L=curR-curL;
            int x=a[curL];
            int t=min(x,L-1);
            add(tr1,x,-1);
            add(tr2,x,-t*(1+t)/2);
            int tem=search(tr1,n)-search(tr1,L-1);
            A+=(x*(1+x)/2-2*search(tr2,n)-L*tem*tem%mod)%mod;
            A%=mod;
            curL++;
        }
        while(curL>l)
        {
            int L=curR-curL;
            int x=a[curL-1];
            int t=min(x,L+1);
            add(tr1,x,-1);
            add(tr2,x,-t*(1+t)/2);
            int tem=search(tr1,n)-search(tr1,L);
            A+=(x*(1+x)/2+2*search(tr2,n)+(L+1)*tem*tem%mod)%mod;
            A%=mod;
            curL--;
        }
    }
    sort(ans.begin(),ans.end(),[&](S x,S y)->bool
    {
        return x.i<y.i;
    });
    for(int i=0;i<q;i++)
    {
        cout<<ans[i].A<<'\n';
    }
}


signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T=1;
    // cin>>T;
    while(T--)
    {
        sol();
    }
}