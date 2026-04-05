#include<iostream>
#include<vector>

#define int long long
using namespace std;

const int Max=3e5+5;
const int mod=998244353;


void sol()
{
    int N,M;
    cin>>N>>M;
    vector<int>A(N+10);
    vector<int>B(M+10);
    vector<int>suf1(N+10);
    vector<int>suf2(N+10);
    vector<int>T(N+10);
    for(int i=1;i<=N;i++){cin>>A[i];}
    for(int i=1;i<=M;i++){cin>>B[i];}
    for(int t=N;t>=1;t--)
    {
        suf1[t]=(suf1[t+1]+A[t])%mod;
        suf2[t]=(suf2[t+1]+A[t]*t)%mod;
        T[t]=(suf2[t]-((t-1)*suf1[t])%mod+mod)%mod;
    }
    int ans=0;
    for(int j=2;j<=M;j++)
    {
        if(!B[j])continue;
        int S=0;
        for(int t=j+1;t<=N+1;t+=j)
        {
            S=(S+T[t]-T[t-1]+mod)%mod;
        }
        S=(S*j)%mod;
        S+=T[1];
        ans=(ans+B[j]*S)%mod;
    }
    cout<<(ans+mod)%mod<<'\n';
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