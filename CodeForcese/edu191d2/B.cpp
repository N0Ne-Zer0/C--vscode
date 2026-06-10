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
    vector<int>a(4*n+1);
    for(int i=1;i<=n;i++)
    {
        a[i]=i;
        a[2*n-i+1]=i;
        a[3*n+1-i]=i;
        a[3*n+i]=i;
    }
    if(n%2)swap(a[(3*n+1)/2],a[(n+3)/2]);
    for(int i=1;i<=4*n;i++)cout<<a[i]<<' ';
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
