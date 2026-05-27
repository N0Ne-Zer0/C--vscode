// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define int long long

const int maxn=2e5+5;
const int mod=1e9+7;

void sol()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cout<<2*i-1<<' ';
    }
    cout<<'\n';
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