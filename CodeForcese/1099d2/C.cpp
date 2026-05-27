// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define int long long

const int maxn=2e5+5;
const int mod=1e9+7;

int a[maxn];
int lst[maxn][100],cnt[maxn];

void sol()
{
    int ans1=0,sum1=0;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1)
        {
            sum1++;
        }
        cnt[i]=0;
        while(a[i]>1)
        {
            lst[i][++cnt[i]]=a[i];
            if(a[i]%2)
            {
                a[i]++;
            }
            else a[i]>>=1;
            ans1++;
        }
        lst[i][++cnt[i]]=1;
    }
    if(sum1)
    {
        ans1=min(ans1,ans1-n+2*sum1);
        cout<<ans1<<'\n';
        return;
    }
    int x=0;
    while(cnt[1])
    {
        int sm=lst[1][cnt[1]];
        cnt[1]--;
        bool fg=0;
        for(int i=2;i<=n;i++)
        {
            if(sm!=lst[i][cnt[i]])
            {
                fg=1;
                break;
            }
            cnt[i]--;
            if(cnt[i]<0)
            {
                fg=1;
                break;
            }
        }
        if(fg)break;
        x++;
    }
    x--;
    ans1=ans1-x*n;
    cout<<ans1<<'\n';
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