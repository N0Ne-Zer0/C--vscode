#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const ll N=2e5+10, MOD=1e9+7, INF=1e12;

#define DEBUG
#ifdef DEBUG
#define debug(a) cout<<#a<<'='<<a<<endl;
#endif
#ifndef DEBUG
#define debug(a)
#endif

void sol()
{
    int x,y,m,n;
    cin>>x>>y>>n>>m;
    vector<int>a(n+1),b(m+1);
    int ma=0,mb=0,mia=0,mib=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ma=max(ma,a[i]);
        mia=min(mia,a[i]);
    }
    for(int i=1;i<=m;i++)
    {
        cin>>b[i];
        mb=max(mb,b[i]);
        mib=min(mib,b[i]);
    }
    int res=x*y;
    int x1=x+ma,x2=x+mia;
    int y1=y+mb,y2=y+mib;
    
    res=max(res,x1*y1);
    res=max(res,x1*y2);
    res=max(res,x2*y1);
    res=max(res,x2*y2);
    cout<<res<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        sol();
    }
    return 0;
}