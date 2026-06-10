// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
#define int long long

const int maxn=3e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=1e9+7;

int a[maxn],b[maxn];

void sol()
{
    int n;
    cin>>n; 
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    for(int i=1;i<=n;i++)
    {
        if(a[b[i]]!=i)
        {
            cout<<"No";
            return;
        }
    }
    cout<<"Yes";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=1;
    // cin>>T;
    while(T--)sol();
}
