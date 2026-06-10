// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
#define int long long

const int maxn=3e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=1e9+7;



void sol()
{
    string s;
    int n;
    cin>>n;
    cin>>s;
    int s1=0,s2=0;
    for(auto c:s)
    {
        if(c=='(')s1++;
        if(c==')')s2++;
    }
    if(s1!=s2)
    {
        cout<<"NO\n";
    }
    else cout<<"YES\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=1;
    cin>>T;
    while(T--)sol();
}
