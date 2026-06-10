// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long

const int maxn=2e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=1e9+7;
const int INF=1e9;

struct Node
{
    int ls,rs,v;
}str[maxn<<6];
int n,cnt,a[maxn],b[maxn];
int ver[maxn];

void update(int &o1,int o2,int l,int r,int pos,int v)
{
    str[o1=++cnt]=str[o2];
    if(l==r)
    {
        str[o1].v+=v;
        return;
    }
    int mid=(l+r)>>1;
    if(pos<=mid)update(str[o1].ls,str[o2].ls,l,mid,pos,v);
    if(pos>mid)update(str[o1].rs,str[o2].rs,mid+1,r,pos,v);
    str[o1].v=str[str[o1].ls].v+str[str[o1].rs].v;
}
int search(int o1,int o2,int l,int r,int k)
{
    if(l==r)return l;
    int tem=str[str[o2].ls].v-str[str[o1].ls].v;
    int mid=(l+r)>>1;
    if(tem>=k)
    {
        return search(str[o1].ls,str[o2].ls,l,mid,k);
    }
    else
    {
        return search(str[o1].rs,str[o2].rs,mid+1,r,k-tem);
    }
}

void sol()
{
    int q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b+1,b+n+1);
    int len=unique(b+1,b+n+1)-(b+1);
    for(int i=1;i<=n;i++)
    {
        int tem=lower_bound(b+1,b+len+1,a[i])-b;
        update(ver[i],ver[i-1],1,len,tem,1);
    }
    while(q--)
    {
        int l,r,k;
        cin>>l>>r>>k;
        cout<<b[search(ver[l-1],ver[r],1,len,k)]<<'\n';
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