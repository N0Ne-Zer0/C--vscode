#include<bits/stdc++.h>
using namespace std;
#define int long long

void sol(){
    int n;cin>>n;
    vector<int>a(2*n+1);
    vector<pair<int,int>>vec(2*n+1,{0,0});
    for(int i=1;i<=2*n;i++){
        cin>>a[i];
        auto&[l,r]=vec[a[i]];
        if(!l)l=i;
        else r=i;
    }
    vector<int>dp(2*n+1,0);
    for(int i=1;i<=2*n;i++){
        auto[l,r]=vec[a[i]];
        dp[i]=dp[i-1];
        if(i==r){
            int L=r-l+1;
            dp[i]=max(dp[i-1],dp[l-1]+L*L-L);
        }
    }
    int res=2*n+dp[2*n];
    cout<<res<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T=1;cin>>T;
    while(T--)sol();
}