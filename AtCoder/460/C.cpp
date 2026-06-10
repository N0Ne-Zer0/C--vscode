// #include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define int long long

const int maxn=2e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=1e9+7;

int A[maxn],B[maxn];

void sol()
{
    int N,M;
    cin>>N>>M;
    for(int i=1;i<=N;i++)cin>>A[i];
    for(int i=1;i<=M;i++)cin>>B[i];
    sort(A+1,A+N+1);
    sort(B+1,B+M+1);
    int j=1,ans=0;
    for(int i=1;i<=N;i++)
    {
        if(B[j]>2*A[i]&&j<=M)continue;
        if(j>M)break;
        ans++;
        j++;
    }
    cout<<ans;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=1;
    // cin>>T;
    while(T--)sol();
}
