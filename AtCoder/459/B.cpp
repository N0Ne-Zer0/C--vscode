// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define int long long

const int maxn=2e5+5;
const int mod=1e9+7;

int N;
string S[maxn];

int F(char c)
{
    if(c>='a'&&c<='c')return 2;
    if(c>='d'&&c<='f')return 3;
    if(c>='g'&&c<='i')return 4;
    if(c>='j'&&c<='l')return 5;
    if(c>='m'&&c<='o')return 6;
    if(c>='p'&&c<='s')return 7;
    if(c>='t'&&c<='v')return 8;
    if(c>='w'&&c<='z')return 9;
}

void sol()
{
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        cin>>S[i];
        cout<<F(S[i][0]);
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