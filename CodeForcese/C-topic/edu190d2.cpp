// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<map>
using namespace std;
#define int long long

const int maxn=2e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=1e9+7;

vector<int>c(maxn);

void sol()
{
    int n;
    cin>>n;
    int ans=0,s=0,p=0;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        if(c[i]>1)
        {
            ans+=c[i];
            s+=(c[i]-2)/2;
        }
        else
        {
            p++;
        }
    }
    if(p+1==n)s++;
    ans+=min(p,s);
    if(ans<3)ans=0;
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
