// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
#define int long long

const int maxn=2e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=1e9+7;

int a[maxn];
vector<int>s2,s3,s6,s;

void sol()
{
    int n;
    cin>>n;
    s2.clear();
    s3.clear();
    s6.clear();
    s.clear();
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]%6==0)s6.push_back(a[i]);
        else if(a[i]%3==0)s3.push_back(a[i]);
        else if(a[i]%2==0)s2.push_back(a[i]);
        else s.push_back(a[i]);
    }
    for(auto i:s6)cout<<i<<' ';
    for(auto i:s2)cout<<i<<' ';
    for(auto i:s)cout<<i<<' ';
    for(auto i:s3)cout<<i<<' ';
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
