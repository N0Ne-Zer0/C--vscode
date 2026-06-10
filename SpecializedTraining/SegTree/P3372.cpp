// #include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define int long long

const int maxn=3e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=1e9+7;

int A[maxn],N;

struct Node
{
    int sum,maxv,minv;
    int lazy;
}segTree[maxn<<2];

void build(int x,int l,int r)
{
    segTree[x].lazy=0;
    if(l==r)
    {
        segTree[x]={A[l],A[l],A[l],0};
        return;
    }
    int mid=(l+r)>>1;
    int ls=x<<1,rs=x<<1|1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    segTree[x].sum=segTree[ls].sum+segTree[rs].sum;
    segTree[x].maxv=max(segTree[ls].maxv,segTree[rs].maxv);
    segTree[x].minv=min(segTree[ls].minv,segTree[rs].minv);
}

void pushDown(int x,int l,int r)
{
    if(segTree[x].lazy==0)return;
    int lz=segTree[x].lazy;
    int mid=(l+r)>>1;
    int ls=x<<1,rs=x<<1|1;
    segTree[ls].sum+=(mid-l+1)*lz;
    segTree[ls].maxv+=lz;
    segTree[ls].minv+=lz;
    segTree[ls].lazy+=lz;
    segTree[rs].sum+=(r-mid)*lz;
    segTree[rs].maxv+=lz;
    segTree[rs].minv+=lz;
    segTree[rs].lazy+=lz;
    segTree[x].lazy=0;
}

void rangeAdd(int ql,int qr,int val,int x,int l,int r)
{
    if(ql<=l&&r<=qr)
    {

        segTree[x].sum+=(r-l+1)*val;
        segTree[x].maxv+=val;
        segTree[x].minv+=val;
        segTree[x].lazy+=val;
        return;
    }
    pushDown(x,l,r);
    int mid=(l+r)>>1;
    int ls=x<<1,rs=x<<1|1;
    if(ql<=mid)rangeAdd(ql,qr,val,ls,l,mid);
    if(qr>=mid+1)rangeAdd(ql,qr,val,rs,mid+1,r);
    segTree[x].sum=segTree[ls].sum+segTree[rs].sum;
    segTree[x].maxv=max(segTree[ls].maxv,segTree[rs].maxv);
    segTree[x].minv=min(segTree[ls].minv,segTree[rs].minv);
}

Node rangeQuery(int ql,int qr,int x,int l,int r)
{
    if(ql<=l&&r<=qr)return segTree[x];
    pushDown(x,l,r);
    Node res={0,-MAX,MAX,0};
    int mid=(l+r)>>1;
    int ls=x<<1,rs=x<<1|1;
    if(ql<=mid)
    {
        Node left=rangeQuery(ql,qr,ls,l,mid);
        res.sum+=left.sum;
        res.maxv=max(res.maxv,left.maxv);
        res.minv=min(res.minv,left.minv);
    }
    if(qr>=mid+1)
    {
        Node right=rangeQuery(ql,qr,rs,mid+1,r);
        res.sum+=right.sum;
        res.maxv=max(res.maxv,right.maxv);
        res.minv=min(res.minv,right.minv);
    }
    return res;
}

void sol()
{
    int f,x,y,k;
    cin>>f>>x>>y;
    if(f==1)
    {
        cin>>k;
        rangeAdd(x,y,k,1,1,N);
    }
    else
    {
        cout<<rangeQuery(x,y,1,1,N).sum<<'\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=1;
    cin>>N;
    cin>>T;
    for(int i=1;i<=N;i++)cin>>A[i];
    build(1,1,N);
    while(T--)sol();
}