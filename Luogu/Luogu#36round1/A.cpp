// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<map>
using namespace std;
#define int unsigned long long

const int maxn=2e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=1e9+7;

void sol()
{
    int a,b,c,x,y,z;
    cin>>a>>b>>c>>x>>y>>z;
    if((a*y>=b*x)&&(a*z>=x*c))cout<<"1\n";
    else if((b*x>=a*y)&&(b*z>=c*y))cout<<"2\n";
    else if((c*x>=a*z)&&(c*y>=b*z))cout<<"3\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=1;
    cin>>T;
    while(T--)sol();
}
