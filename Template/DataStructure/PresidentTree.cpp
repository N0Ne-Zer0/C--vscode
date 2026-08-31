#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long

const int maxn=3e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=998244353;
const int INF=1e9;

struct PresidentTree
{
    int tot=0;
    vector<int>ls,rs,cnt;

    PresidentTree(int n):ls(n*25),rs(n*25),cnt(n*25){}

    int update(int old,int l,int r,int pos,int delta)//从old节点处添加新节点p并返回
    {
        int p=++tot;
        ls[p]=ls[old];
        rs[p]=rs[old];
        cnt[p]=cnt[old]+delta;
        if(l!=r)
        {
            int mid=(l+r)>>1;
            if(pos<=mid)ls[p]=update(ls[old],l,mid,pos,delta);
            else rs[p]=update(rs[old],mid+1,r,pos,delta);
        }
        return p;
    }

    int queryCnt(int v1,int v2,int l,int r,int ql,int qr)//查询v2-v1版本中[ql,qr]总数量
    {
        if(ql>r||qr<l)return 0;
        if(ql<=l&&r<=qr)return cnt[v2]-cnt[v1];
        int mid=(l+r)>>1;
        int left=queryCnt(ls[v1],ls[v2],l,mid,ql,qr);
        int right=queryCnt(rs[v1],rs[v2],mid+1,r,ql,qr);
        return left+right;
    }

    int kth(int v1,int v2,int l,int r,int k)//查询v2-v1版本中第k大
    {
        if(l==r)return l;
        int mid=(l+r)>>1;
        int left=cnt[ls[v2]]-cnt[ls[v1]];
        if(k<=left)return kth(ls[v1],ls[v2],l,mid,k);
        return kth(rs[v1],rs[v2],mid+1,r,k-left);
    }
};


void sol()
{
    
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