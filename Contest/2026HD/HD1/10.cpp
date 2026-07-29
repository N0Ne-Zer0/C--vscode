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
    int n;
    bool fst=1;
    cin>>n;
    vector<int>x(n);
    for(auto &X:x)cin>>X;
    int mid,sum1=0,sum2=0;
    if(n%2)
    {
        mid=(n-1)>>1;
        for(int i=0;i<mid;i++)sum1+=x[i];
        for(int i=n-1;i>mid;i--)sum2+=x[i];
    }
    else
    {
        mid=(n+1)>>1;
        for(int i=0;i<mid;i++)sum1+=x[i];
        for(int i=n-1;i>mid;i--)sum2+=x[i];
        fst=0;
    }
    if(sum1>sum2)cout<<"YES\n";
    else if(sum1==sum2)
    {
        int idx1=mid-1,idx2=mid+1;
        while(sum1==sum2&&idx1>=0&&idx2<n)
        {
            sum1-=x[idx1--];
            sum2-=x[idx2++];
        }
        if(fst)
        {
            if(sum1>sum2)cout<<"YES\n";
            else cout<<"NO\n";
        }
        else
        {
            if(sum1>=sum2)cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    else cout<<"NO\n";
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