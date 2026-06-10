// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
#define int long long

const int maxn=2e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=1e9+7;

vector<int>a(maxn),ans;

void sol()
{
    ans.clear();
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int f=0;
    for(int i=n;i>=1;i--)
    {
        if(f)
        {
            a[i]=-a[i];
        }
        if(a[i]>0)
        {
            f^=1;
            a[i]=-a[i];
            ans.push_back(i);
        }
    }
    cout<<ans.size()<<'\n';
    for(auto i:ans)cout<<i<<' ';
    cout<<'\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=1;
    cin>>T;
    while(T--)sol();
}
