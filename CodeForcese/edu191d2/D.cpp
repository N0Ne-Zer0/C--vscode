// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
#define int long long

const int maxn=2e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=998244353;
const int INF=1e9;

int a[maxn],bad[maxn];
map<int,bool>mp;

void sol()
{
    int n;
    cin>>n;
    int badcnt=0;
    int tem=0;
    mp.clear();
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=tem)
        {
            if(mp.find(a[i])!=mp.end())
            {
                mp[a[i]]=1;
                tem=a[i];
            }
            else
            {
                bad[++badcnt]=a[i];
            }
        }
    }
    if(badcnt>2)
    {
        cout<<"NO"<<'\n';
        return;
    }
    
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=1;
    cin>>T;
    while(T--)sol();
}
