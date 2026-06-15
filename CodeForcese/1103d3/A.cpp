#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
#define endl '\n'

const int maxn=3e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=998244353;
const int INF=1e9;

void sol()
{
    int n,ma=0,mi=MAX;
    cin>>n;
    vector<int>a(n);
    for(auto &x:a)
    {
        cin>>x;
        ma=max(ma,x);
        mi=min(mi,x);
    }
    cout<<ma+1-mi<<'\n';
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    T = 1;
    cin>>T;
    while (T--)
    {
        sol();
    }
}