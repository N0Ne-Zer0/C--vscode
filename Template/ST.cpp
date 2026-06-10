// #include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define int long long

const int maxn=3e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=1e9+7;

int a[maxn],N,M;
int ST[maxn][20];
void build()
{
    for(int i=1;i<=N;i++)
    {
        ST[i][0]=a[i];
    }
    for(int i=1;i<20;i++)
    {
        int len=1<<i;
        for(int j=1;j<=N;j++)
        {
            if(j+len-1>N)continue;
            ST[j][i]=max(ST[j][i-1],ST[j+(1<<(i-1))][i-1]);
        }
    }
}
int search(int l,int r)
{
    int len=r-l+1;
    int t=19;
    while((1<<t)>len)t--;
    return max(ST[l][t],ST[r-(1<<t)+1][t]);
}


signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
}
