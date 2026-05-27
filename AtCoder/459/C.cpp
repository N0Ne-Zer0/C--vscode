// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define int long long

const int maxn=3e6+5;
const int mod=1e9+7;

int N,Q;
int a[maxn],sum[maxn],ans;

void sol()
{
    cin>>N>>Q;
    while(Q--)
    {
        int n,x;
        cin>>n>>x;
        if(n==1)
        {
            a[x]++;
            sum[a[x]]++;
            if(sum[a[x]]>=N)ans++;
        }
        else
        {
            int tem=x+ans;
            cout<<sum[tem]<<'\n';
        }
    }
}

signed main()
{
    int T=1;
    // cin>>T;
    while(T--)
    {
        sol();
    }
}