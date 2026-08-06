#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
#define ls (x<<1)
#define rs (x<<1|1)

const int maxn=3e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=998244353;
const int INF=1e9;

vector<int>A;

struct Node
{
    bool _0=0,_1=0,_2=0,_10=0,_21=0,_20=0,_210=0;
};

vector<Node>segTree;

void merge(int x)
{
    auto [l0,l1,l2,l10,l21,l20,l210]=segTree[ls];
    auto [r0,r1,r2,r10,r21,r20,r210]=segTree[rs];
    segTree[x]._0=l0||r0;
    segTree[x]._1=l1||r1;
    segTree[x]._2=l2||r2;
    segTree[x]._10=l10||r10||l1&&r0;
    segTree[x]._21=l21||r21||l2&&r1;
    segTree[x]._20=l20||r20||l2&&r0;
    segTree[x]._210=l210||r210||l21&&r0||l2&&r10;
}

Node merge(Node a,Node b)
{
    auto [l0,l1,l2,l10,l21,l20,l210]=a;
    auto [r0,r1,r2,r10,r21,r20,r210]=b;
    Node res;
    res._0=l0||r0;
    res._1=l1||r1;
    res._2=l2||r2;
    res._10=l10||r10||l1&&r0;
    res._21=l21||r21||l2&&r1;
    res._20=l20||r20||l2&&r0;
    res._210=l210||r210||l21&&r0||l2&&r10;
    return res;
}

void debug(int x,int l,int r)
{
    cout<<l<<' '<<r<<':';
    cout<<segTree[x]._0<<segTree[x]._1<<segTree[x]._2<<segTree[x]._10<<segTree[x]._21<<segTree[x]._20<<segTree[x]._210<<'\n';
}

void build(int x,int l,int r)
{
    if(l==r)
    {
        if(A[l]==0)segTree[x]._0=1;
        if(A[l]==1)segTree[x]._1=1;
        if(A[l]==2)segTree[x]._2=1;
        return;
    }
    int mid=(l+r)>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    merge(x);
}

void update(int x,int l,int r,int pos,int val)
{
    if(l==r)
    {
        segTree[x]._0=0;
        segTree[x]._1=0;
        segTree[x]._2=0;
        if(val==0)segTree[x]._0=1;
        if(val==1)segTree[x]._1=1;
        if(val==2)segTree[x]._2=1;
        return;
    }
    int mid=(l+r)>>1;
    if(pos<=mid)update(ls,l,mid,pos,val);
    else update(rs,mid+1,r,pos,val);
    merge(x);
}

Node rangeQuery(int x,int l,int r,int ql,int qr)
{
    if(ql<=l&&r<=qr)return segTree[x];
    Node res={0,0,0,0,0,0,0};
    int mid=(l+r)>>1;
    if(ql<=mid)
    {
        Node left=rangeQuery(ls,l,mid,ql,qr);
        res=merge(res,left);
    }
    if(qr>=mid+1)
    {
        Node right=rangeQuery(rs,mid+1,r,ql,qr);
        res=merge(res,right);
    }
    return res;
}

int S(Node a)
{
    if(a._210)return 2;
    if(a._10||a._20||a._21)return 1;
    return 0;
}

void sol()
{
    int n,q;
    cin>>n>>q;
    A.assign(n+1,0);
    segTree.assign(n<<3,{});
    for(int i=1;i<=n;i++)cin>>A[i];
    build(1,1,n);
    while(q--)
    {
        int op,xx,yy;
        cin>>op>>xx>>yy;
        if(op==1)update(1,1,n,xx,yy);
        else cout<<S(rangeQuery(1,1,n,xx,yy))<<'\n';
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