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
    int N;
    cin>>N;
    for(int i=N;i<=S.size()-N-1;i++)
    {
        cout<<S[i];
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