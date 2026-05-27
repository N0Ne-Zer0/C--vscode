#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
#define int long long

const int maxn=2e5+5;
const int mod=1e9+7;


void sol()
{
    string S;
    cin>>S;
    int ans=0;
    for(int i=0;i<S.size();i++)
    {
        if(S[i]=='C')
        {
            int tem=min(i+1ull,S.size()-i);
            ans+=tem;
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