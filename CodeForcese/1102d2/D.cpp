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
    int n,k,a=0,b=0,c=0;
    string s1,s2;
    cin>>n>>k;
    cin>>s1>>s2;
    for(int i=0;i<n;i++)
    {
        if(s1[i]=='1')a++;
        if(s2[i]=='1')b++;
        if(s1[i]!=s2[i])c++;
    }
    a=a*(n-a);
    b=b*(n-b);
    c=c*(n-c);
    int sum=(1<<k)+1,ans=0;
    int sa,sb,sc;
    sc=sum/3;
    sa=sb=(sum-sc)/2;
    ans=a*sa+b*sb+c*sc;
    cout<<ans<<'\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=1;
    cin>>T;
    while(T--)sol();
}
