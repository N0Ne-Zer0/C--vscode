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
    int X;
    string S="HelloWorld";
    cin>>X;
    for(int i=0;i<10;i++)
    {
        if(i+1==X)continue;
        cout<<S[i];
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