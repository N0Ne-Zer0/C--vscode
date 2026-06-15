// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
#define int long long

const int maxn=3e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=998244353;
const int INF=1e9;



void sol()
{
    int n;
    cin>>n;
    vector<int>a(n+1,0),h(n+1,0);
    int maxh=0,maxi=0;
    for(auto i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>maxh)
        {
            maxh=a[i];
            maxi=i;
        }
    }
    for(int i=maxi+1,j=1;i<=maxi+n;i++,j++)
    {
        int t=(i+n-1)%n+1;
        h[j]=a[t];
    }
    vector<int>stk1(n+1,0),stk2(n+1,0);
    vector<int>pre(n+1,0),suf(n+1,0);
    int cnt1=0,cnt2=0,sum=0;
    for(int i=1;i<n;i++)
    {
        while(cnt1&&h[stk1[cnt1]]<h[i])
        {
            int x=h[stk1[cnt1]],k=stk1[cnt1]-stk1[cnt1-1];
            cnt1--;
            sum-=x*k;
        }
        int x=h[i],k=i-stk1[cnt1];
        stk1[++cnt1]=i;
        sum+=x*k;
        pre[i]=sum;
    }
    sum=0;
    stk2[0]=n;
    for(int i=n-1;i;i--)
    {
        while(cnt2&&h[stk2[cnt2]]<h[i])
        {
            int x=h[stk2[cnt2]],k=-stk2[cnt2]+stk2[cnt2-1];
            cnt2--;
            sum-=x*k;
        }
        int x=h[i],k=stk2[cnt2]-i;
        stk2[++cnt2]=i;
        sum+=x*k;
        suf[i]=sum;
    }
    for(int i=1;i<=n;i++)cout<<pre[(i+n-2-maxi)%n+1]+suf[(i-maxi+n-1)%n+1]<<" \n"[i==n];
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=1;
    cin>>T;
    while(T--)sol();
}