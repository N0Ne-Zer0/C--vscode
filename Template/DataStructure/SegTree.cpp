// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
#define int long long

const int maxn=3e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=1e9+7;

struct SegTree
{
    #define mid ((l+r)>>1)
    #define ls (p<<1)
    #define rs (p<<1|1)
    
    int n;
    struct Info{int sum,mx,mn;};
    struct Tag{int add=0,mul=1;};
    vector<Info>tr;
    vector<Tag>lazy;

    SegTree(int n,const vector<int>&a):n(n),tr(n*4+5),lazy(n*4+5)
    {
        build(1,1,n,a);
    }

    inline Info merge(const Info& x,const Info& y)//合并信息
    {
        auto&[s1,m1,n1]=x;
        auto&[s2,m2,n2]=y;
        return {s1+s2,max(m1,m2),min(n1,n2)};
    }

    inline void apply(int p,int l,int r,const Tag& t)//应用懒标记于p
    {
        auto[add,mul]=t;
        auto&[s,m,n]=tr[p];
        s=s*mul+add*(r-l+1);
        m=m*mul+add;
        n=n*mul+add;
        lazy[p].add=lazy[p].add*mul+add;
        lazy[p].mul*=mul;
    }

    inline void push(int p,int l,int r)//向下传递懒标记
    {
        if(lazy[p].add==0&&lazy[p].mul==1)return;
        apply(ls,l,mid,lazy[p]);
        apply(rs,mid+1,r,lazy[p]);
        lazy[p]=Tag();
    }

    inline void pull(int p){tr[p]=merge(tr[ls],tr[rs]);}//从子节点更新自身节点

    void build(int p,int l,int r,const vector<int>& a)
    {
        if(l==r)
        {
            tr[p]={a[l],a[l],a[l]};
            return;
        }
        build(ls,l,mid,a);
        build(rs,mid+1,r,a);
        pull(p);
    }

    void update(int p,int l,int r,int ql,int qr,const Tag&t)//区间[ql,qr]+tag(*mul)
    {
        if(ql<=l&&r<=qr)
        {
            apply(p,l,r,t);
            return;
        }
        push(p,l,r);
        if(ql<=mid)update(ls,l,mid,ql,qr,t);
        if(qr>mid)update(rs,mid+1,r,ql,qr,t);
        pull(p);
    }

    Info query(int p,int l,int r,int ql,int qr)//查询[ql,qr]
    {
        if(ql<=l&&r<=qr)return tr[p];
        push(p,l,r);
        if(qr<=mid)return query(ls,l,mid,ql,qr);
        if(ql>mid)return query(rs,mid+1,r,ql,qr);
        Info left=query(ls,l,mid,ql,qr);
        Info right=query(rs,mid+1,r,ql,qr);
        return merge(left,right);
    }

    void rangeAdd(int l,int r,int v){update(1,1,n,l,r,{v,1});}
    void rangeMul(int l,int r,int v){update(1,1,n,l,r,{0,v});}

    int querySum(int l,int r){return query(1,1,n,l,r).sum;}
    int queryMax(int l,int r){return query(1,1,n,l,r).mx;}
    int queryMin(int l,int r){return query(1,1,n,l,r).mn;}
};

void sol()
{

}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
