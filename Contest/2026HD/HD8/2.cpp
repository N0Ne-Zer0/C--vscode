#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define int unsigned long long

const int maxn=5e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=998244353;
const int INF=1e9;

typedef int T;
struct BITRange {
    int n;
    vector<T>BIT1,BIT2;

    BITRange(int _n):BIT1(_n+2),BIT2(_n+2),n(_n){}

    inline int lb(int x){return -x&x;}

    inline void add(vector<T>&BIT,int x,const T &v)
    {
        for(int i=x;i<=n;i+=lb(i))
        {
            BIT[i]=BIT[i]+v;
        }
    }

    // 区间加 [l, r] 增加 val
    inline void rangeAdd(int l,int r,T val)
    {
        if (l>r)return;
        add(BIT1,l,val);
        add(BIT1,r+1,-val);
        add(BIT2,l,val*(l-1));
        add(BIT2,r+1,-val*r);
    }

    // 前缀和 [1..x]
    inline T preSum(int x)
    {
        T res=0;
        if(x<=0)return 0;
        T s1=0,s2=0;
        for (T i=x;i>0;i-=lb(i)){
            s1+=BIT1[i];
            s2+=BIT2[i];
        }
        res=s1*x-s2;
        return res;
    }

    // 区间和 [l, r]
    inline T rangeSum(T l,T r)
    {
        if(l>r)return 0;
        return preSum(r)-preSum(l - 1);
    }
};

void sol()
{
    int n,m;
    cin>>n>>m;
    vector<int>pA(n+1,0),pB(n+1,0);
    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        pA[i]=pA[i-1]+a;
        pB[i]=pB[i-1]+b;
    }
    BITRange s1(n),s2(n);
    for(int i=1;i<=m;i++)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int l,r,x;
            cin>>l>>r>>x;
            int tx=i*x;
            s1.rangeAdd(l,r,x);
            s2.rangeAdd(l,r,tx);
        }
        else
        {
            int l,r;
            cin>>l>>r;
            int sA=pA[r]-pA[l-1];
            int sB=pB[r]-pB[l-1];
            int ss1=s1.rangeSum(l,r);
            int ss2=s2.rangeSum(l,r);
            int res=sA+i*sB+i*ss1-ss2;
            cout<<res<<'\n';
        }
    }
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