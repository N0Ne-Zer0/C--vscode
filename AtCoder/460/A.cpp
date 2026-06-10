// #include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define int long long

const int maxn=3e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=1e9+7;



void sol()
{
    int M,N;
    cin>>N>>M;
    int cnt=0;
    while(M)
    {
        M=N%M;
        cnt++;
    }
    cout<<cnt;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=1;
    // cin>>T;
    while(T--)sol();
}
