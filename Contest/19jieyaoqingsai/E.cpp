#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
#define int long long

const int maxn=1.4e9+5;
const int mod=1000000007;

int n,x,y,z;

bool check(int T)
{
    int magic=0,S=1;
    for(int i=1;i<=T;i++)
    {
        if(x<(T-i+1)*y+z)
        {
            int t=magic/x;
            magic-=x*t;
            S+=t;
        }
        magic+=S*y;
        if(magic+z*S>=n)
        {
            return 1;
        }
        if(z>x)
        {
            magic+=z*S;
            S=0;
        }
    }
    magic+=z*S;
    return magic>=n;
}

void sol()
{
    cin>>n>>x>>y>>z;
    int l=1,r=n;
    int ans=n;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(check(mid))
        {
            ans=mid;
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<ans;
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