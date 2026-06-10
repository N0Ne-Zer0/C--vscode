// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
#define int long long

const int maxn=2e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=1e9+7;

vector<int>a(maxn*2);
bool fg[maxn*2],fgl[maxn*2],fgr[maxn*2];

void sol()
{
    int n;
    cin>>n;
    int l=0,r=0;
    fg[0]=0;
    fgl[0]=0;
    fgr[0]=0;
    for(int i=1;i<=2*n;i++)
    {
        fg[i]=0;
        fgl[i]=0;
        fgr[i]=0;
        cin>>a[i];
        if(a[i]==0)
        {
            if(l==0)l=i;
            else r=i;
        }
    }
    int tl=l,tr=r;
    int sl=l,sr=r;
    bool not_lr=0;
    while(l<=r)
    {
        if(a[l]!=a[r])
        {
            not_lr=1;
            break;
        }
        fg[a[l]]=1;
        l++,r--;
    }
    while(tl>=1&&tr<=2*n&&not_lr==0)
    {
        if(a[tl]!=a[tr])break;
        fg[a[tl]]=1;
        tl--,tr++;
    }
    int x,y;
    x=y=sl;
    while(x>=1&&y<=2*n)
    {
        if(a[x]!=a[y])break;
        fgl[a[x]]=1;
        x--,y++;
    }
    x=y=sr;
    while(x>=1&&y<=2*n)
    {
        if(a[x]!=a[y])break;
        fgr[a[x]]=1;
        x--,y++;
    }
    int ans=0,ansl=0,ansr=0;
    while(fg[ans])ans++;
    if(not_lr==1)ans=0;
    while(fgl[ansl])ansl++;
    while(fgr[ansr])ansr++;
    ans=max(ans,max(ansl,ansr));
    cout<<ans<<'\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=1;
    cin>>T;
    while(T--)sol();
}
