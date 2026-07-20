#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
#define int long long

const int maxn=2e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=998244353;
const int INF=1e9;

int qp(int x,int y)
{
    if(y==0)return 1;
    if(x==0)return 0;
    int res=1;
    while(y)
    {
        if(y&1)res=res*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return res;
}

void sol()
{
    vector<int>fac(maxn,1),invfac(maxn),pow2(maxn,1),invpow2(maxn);
    for(int i=1;i<maxn;i++)
    {
        fac[i]=fac[i-1]*i%mod;
        pow2[i]=pow2[i-1]*2%mod;
    }
    invfac[maxn-1]=qp(fac[maxn-1],mod-2);
    invpow2[maxn-1]=qp(pow2[maxn-1],mod-2);
    for(int i=maxn-2;i>=0;i--)
    {
        invfac[i]=invfac[i+1]*(i+1)%mod;
        invpow2[i]=invpow2[i+1]*2%mod;
    }

    auto C=[&](int x,int y)
    {
        if(x<y||x<0||y<0)return 0ll;
        return fac[x]*invfac[y]%mod*invfac[x-y]%mod;
    };

    struct Query
    {
        int N,t,X,id;
    };
    
    int T,id=0;
    cin>>T;
    vector<Query>query;
    vector<int>ans(T);
    int block_sz=max(1ll,(int)(maxn/sqrt(T)));
    while(T--)
    {
        int N,X;
        cin>>N>>X;
        X=abs(X);
        if(X>N)
        {
            ans[id]=X;
        }
        else
        {
            query.emplace_back(N,(N+X-1)/2,X,id);
        }
        id++;
    }
    sort(begin(query),end(query),[&](const Query&x,const Query&y)
    {
        int xid=x.N/block_sz,yid=y.N/block_sz;
        if(xid!=yid)return xid<yid;
        return ((xid&1)?x.t>y.t:x.t<y.t);
    });

    int curN=0,curt=0,cur=1;

    auto addt=[&]()
    {
        cur=(cur+C(curN,curt+1))%mod;
        curt++;
    };
    auto subt=[&]()
    {
        cur=(cur-C(curN,curt)+mod)%mod;
        curt--;
    };
    auto addN=[&]()
    {
        cur=(2*cur%mod-C(curN,curt)+mod)%mod;
        curN++;
    };
    auto subN=[&]()
    {
        cur=(cur+C(curN-1,curt))%mod*invpow2[1]%mod;
        curN--;
    };
    for(auto &[N,t,X,id]:query)
    {
        while(N>curN)addN();
        while(t>curt)addt();
        while(t<curt)subt();
        while(N<curN)subN();
        subt();subN();
        int g=N*cur%mod;
        addN();addt();
        ans[id]=(((N+X)%mod*cur%mod-2*g%mod+mod)%mod*invpow2[N-1]-X+mod)%mod;
    }
    for(auto x:ans)cout<<x<<'\n';
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