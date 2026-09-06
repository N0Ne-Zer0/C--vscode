// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
#define int long long

const int maxn=5e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=1e9+7;

typedef int T;
struct FenwickTree{
    int n,bit;
    vector<T>BIT;
    FenwickTree(int _n):BIT(_n+1),n(_n){
        bit=1;
        while((bit<<1)<=n)bit<<=1;
    }

    inline int lb(int x){return -x&x;}

    inline void add(int x,const T &v){
        for(int i=x;i<=n;i+=lb(i)){
            BIT[i]=BIT[i]+v;
        }
    }

    inline T sum(int x){
        T res=0;
        for(int i=x;i>0;i-=lb(i)){
            res=res+BIT[i];
        }
        return res;
    }

    inline T rangeSum(int l,int r){
        if(l>r)return 0;
        return sum(r)-sum(l-1);
    }

    inline T select(const T& k){//返回最小的x，使得sum(x)>=k，或返回n+1
        int idx=0;
        T cur{};
        for(int i=bit;i;i>>=1){
            int nxt=idx+i;
            if(nxt>n||cur+BIT[nxt]>=k)continue;
            idx=nxt;
            cur+=BIT[idx];
        }
        return idx+1;
    }
};

struct BITRange{
    int n;
    vector<T>BIT1,BIT2;

    BITRange(int _n):BIT1(_n+1),BIT2(_n+1),n(_n){}

    inline int lb(int x){return -x&x;}

    inline void add(vector<T>&BIT,int x,const T &v){//单点加
        for(int i=x;i<=n;i+=lb(i)){
            BIT[i]=BIT[i]+v;
        }
    }

    inline void rangeAdd(int l,int r,T val){//区间加
        if (l>r)return;
        add(BIT1,l,val);
        add(BIT1,r+1,-val);
        add(BIT2,l,val*(l-1));
        add(BIT2,r+1,-val*r);
    }

    inline T preSum(int x){//前缀和
        T res=0;
        if(x<=0)return 0;
        T s1=0,s2=0;
        for(T i=x;i>0;i-=lb(i)){
            s1+=BIT1[i];
            s2+=BIT2[i];
        }
        res=s1*x-s2;
        return res;
    }

    inline T rangeSum(T l,T r){//区间和 [l, r]
        if(l>r)return 0;
        return preSum(r)-preSum(l - 1);
    }
};

signed main()
{
    
}
