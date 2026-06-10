// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define int long long

const int maxn=2e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=1e9+7;

int a[maxn],b[maxn];

void sol()
{
    int n;
    int al=0,dmv=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        al+=a[i];
    }
    b[n]=a[n];
    dmv+=b[n];
    int x=n,sum=0,tx=n,tsum=0;
    for(int i=n-1;i>=1;i--)
    {
        b[i]=min(b[i+1],a[i]);
        dmv+=b[i];
        if(b[i]==b[tx])
        {
            tsum++;
        }
        else
        {
            if(tsum>sum)
            {
                sum=tsum;
                x=tx;
            }
            tx=i;
            tsum=0;
        }
    }
    if(tsum>sum)
    {
        sum=tsum;
        x=tx;
    }
    // for(int i=1;i<=n;i++)cout<<b[i];
    // cout<<'\n';
    // cout<<x<<' '<<al<<'-'<<dmv<<'+'<<sum<<"===\n";
    cout<<al-dmv+sum<<'\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=1;
    cin>>T;
    while(T--)sol();
}
