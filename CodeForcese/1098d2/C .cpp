// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
#define int long long

const int maxn=2e5+5;
const int mod=1e9+7;

int x[1000],cnt;

void sol()
{
    int a,n,x1,x2;
    int tem=1;
    cin>>a>>n;
    int a1=a;
    cin>>x1>>x2;
    if(a==0)
    {
        cout<<min(x1,x2)<<'\n';
        return;
    }
    cnt=0;
    while(a)
    {
        x[++cnt]=a%10;
        a/=10;
        tem*=10;
    }
    tem/=10;
    int ans1=0,ans2=0,ans3=0,ans4=0;
    int t2=0;
    for(int i=1;i<cnt;i++)
    {
        t2=t2*10+max(x1,x2);
    }
    if(cnt==1)
    {
        ans3=0x7fffffffffffffff;
    }
    else ans3=t2;
    t2=0;
    for(int i=1;i<=cnt+1;i++)
    {
        t2=t2*10+min(x1,x2);
        if(i==1&&min(x1,x2)==0)
        {
            t2=max(x1,x2);
        }
    }
    ans4=t2;
    while(x[cnt]==x1||x[cnt]==x2)
    {
        if(x[cnt]==x1)
        {
            ans1+=x1*tem;
        }
        else ans1+=x2*tem;
        ans2=ans1;
        cnt--;
        tem/=10;
        if(cnt<1)break;
    }
    if(x1<x[cnt]&&x2<x[cnt])
    {
        while(tem)
        {
            ans1+=tem*max(x1,x2);
            tem/=10;
        }
        ans2=0x7fffffffffffffff;
    }
    else if(x1>x[cnt]&&x2>x[cnt])
    {
        while(tem)
        {
            ans1+=tem*min(x1,x2);
            tem/=10;
        }
        ans2=0x7fffffffffffffff;
    }
    else
    {
        ans1+=tem*max(x1,x2);
        ans2+=tem*min(x1,x2);
        tem/=10;
        while(tem)
        {
            ans1+=tem*min(x1,x2);
            ans2+=tem*max(x1,x2);
            tem/=10;
        }
    }
    // cout<<ans1<<' '<<ans2<<' '<<ans3<<' '<<ans4<<'\n';
    cout<<min(min(abs(a1-ans3),abs(a1-ans4)),min(abs(a1-ans1),abs(a1-ans2)))<<'\n';
}

signed main()
{
    int T=1;
    cin>>T;
    while(T--)
    {
        sol();
    }
}