// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<map>
using namespace std;
#define int long long

const int maxn=2e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=1e9+7;

void sol()
{
    int n,q;
    cin>>n>>q;
    vector<int>a(n+1),pre(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        pre[i]=pre[i-1]^a[i];
    }

    while(q--)
    {
        int op,k,l,r;
        int res=0;
        cin>>op>>k>>l>>r;
        int XOR=pre[r]^pre[l-1];
        //(a[1]|k)^(a[2]|k)^(a[3]|k)^...
        if(op)
        {
            res=(XOR&(~k))|(((r-l+1)%2)*k);
        }
        //(a[1]&k)^(a[2]&k)^(a[3]&k)^...
        else
        {
            res=XOR&k;
        }
        cout<<res<<'\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=1;
    // cin>>T;
    while(T--)sol();
}
