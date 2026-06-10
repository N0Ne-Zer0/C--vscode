// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define int long long

const int maxn=2e5+5;
const int mod=1e9+7;



void sol()
{
    int n,x,s;
    cin>>n>>x>>s;
    int icnt=0;
    string S;
    cin>>S;
    int sum=0,sumA=0,sumI=0;
    for(auto i=0u;i<S.size();i++)
    {
        char c=S[i];
        if(c=='A')
        {
            if(icnt*s>sum)
            {
                sumA++;
                sum++;
            }
            else
            {
                if(icnt<x)
                {
                    sumA++;
                    sum++;
                    icnt++;
                }
            }
        }
        if(c=='E')
        {
            if(icnt*s>sum)
            {
                sum++;
            }
            else
            {
                if(icnt<x&&sumA+sumI>icnt)
                {
                    icnt++;
                    sum++;
                }
            }
        }
        if(c=='I')
        {
            if(icnt<x)
            {
                icnt++;
                sumI++;
                sum++;
            }
        }
    }
    cout<<sum<<'\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=1;
    cin>>T;
    while(T--)
    {
        sol();
    }
}