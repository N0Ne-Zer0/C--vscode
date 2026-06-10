// #include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define int long long

const int maxn=3e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=1e9+7;



void sol()
{
    int X1,Y1,R1,X2,Y2,R2;
    cin>>X1>>Y1>>R1>>X2>>Y2>>R2;
    if((X1-X2)*(X1-X2)+(Y1-Y2)*(Y1-Y2)<=(R1+R2)*(R1+R2)&&(X1-X2)*(X1-X2)+(Y1-Y2)*(Y1-Y2)>=(R1-R2)*(R1-R2))
    {
        cout<<"Yes\n";
    }
    else cout<<"No\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=1;
    cin>>T;
    while(T--)sol();
}
