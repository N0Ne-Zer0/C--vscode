#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
#define int long long

const int maxn=2e5+5;
const int mod=1e9+7;

int N,A[maxn],B[maxn],C[maxn],preB[maxn];

void sol()
{
    cin>>N;
    int s=0;
    preB[0]=0;
    for(int i=1;i<=N;i++)
    {
        cin>>A[i]>>B[i]>>C[i];
        preB[i]=preB[i-1]+B[i];
    }
    
}

signed main()
{
    int T=1;
    cin>>T;
    while(T--)
    {
        sol();
    }
}