#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
#define int long long

const int maxn=2e5+5;
const int mod=1e9+7;


void sol()
{
    int H,W;
    cin>>H>>W;
    for(int i=1;i<=H;i++)
    {
        for(int j=1;j<=W;j++)
        {
            int ans=4;
            if(i==1)ans--;
            if(i==H)ans--;
            if(j==1)ans--;
            if(j==W)ans--;
            cout<<ans<<' ';
        }
        cout<<'\n';
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