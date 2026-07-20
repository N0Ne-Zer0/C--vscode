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
    int n,res=0;
    cin>>n;
    vector<int>a(n);
    int MIN=MAX;
    for(auto &x:a)
    {
        cin>>x;
        MIN=min(MIN,x);
        x=MIN;
        res+=x;
    }
    cout<<res<<'\n';
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