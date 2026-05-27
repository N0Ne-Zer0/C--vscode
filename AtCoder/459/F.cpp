// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
#define int long long

const int maxn=2e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=1e9+7;

vector<int>a(maxn),d(maxn),d1(maxn);
stack<pair<int,int>>s;

void sol()
{
    while(s.size())s.pop();
    int N;
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        cin>>a[i];
        d[i]=a[i]-i;
    }
    for(int i=1;i<=N;i++)
    {
        pair<int,int>t={1,d[i]};
        while(s.size())
        {
            auto tm=s.top();
            if((__int128)tm.second*t.first<=(__int128)t.second*tm.first)break;
            s.pop();
            t={t.first+tm.first,t.second+tm.second};
        }
        s.push(t);
    }
    int ci=N;
    while(s.size())
    {
        int k=s.top().first;
        int v=s.top().second/k;
        int r=s.top().second%k;
        if(r<0)
        {
            r+=k;
            v--;
        }
        s.pop();
        while(k--)d1[ci--]=v+bool(0<r--);
    }
    int ans=0,sum1=0,sum2=0;
    for(int i=1;i<=N;i++)
    {
        sum1+=d[i];
        sum2+=d1[i];
        ans+=sum1-sum2;
    }
    cout<<ans<<'\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin>>T;
    while(T--) sol();
}
