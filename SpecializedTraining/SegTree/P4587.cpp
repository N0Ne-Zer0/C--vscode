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
int n,cnt,a[maxn],ver[maxn];

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
    else update(str[o1].rs,str[o2].rs,mid+1,r,pos,v);
    str[o1].v=str[str[o1].ls].v+str[str[o1].rs].v;
}
int search(int o1,int o2,int l,int r,int ql,int qr)
{
    if(ql<=l&&r<=qr)
    {
        return str[o2].v-str[o1].v;
    }
    int mid=(l+r)>>1,res=0;
    if(ql<=mid)res+=search(str[o1].ls,str[o2].ls,l,mid,ql,qr);
    if(qr>mid)res+=search(str[o1].rs,str[o2].rs,mid+1,r,ql,qr);
    return res;
}

void sol()
{
    int m;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        update(ver[i],ver[i-1],1,INF,a[i],a[i]);
    }
    cin>>m;
    while(m--)
    {
        int l,r;
        cin>>l>>r;//l-1版本和r版本之差的权值树
        int lst=0,ans=1;
        while(1)
        {
            int mob=search(ver[l-1],ver[r],1,INF,lst+1,ans);
            if(mob>0)
            {
                lst=ans;
                ans+=mob;
            }
            else break;
        }
        cout<<ans<<'\n';
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