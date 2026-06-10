// #include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
#define int unsigned long long

const int maxn=3e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=998244353;

int _10[20];

int L(int x)
{
    int res=0;
    while(x){x/=10;res++;}
    return res;
}
void sol()
{
    int ans=0;
    int N,M;
    cin>>N>>M;
    for(int i=1;i<=L(N);i++)
    {
        int G=__gcd(M,_10[i]-1);
        int sumx=N/(M/G);
        int sumy=9*_10[i-1];
        if(i==L(N))sumy=N-_10[i-1]+1;
        ans=(ans+sumx%mod*(sumy%mod)%mod)%mod;
    }
    cout<<ans<<'\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=1;
    _10[0]=1;
    for(int i=1;i<=19;i++)_10[i]=_10[i-1]*10;
    cin>>T;
    while(T--)sol();
}
