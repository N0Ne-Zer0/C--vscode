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
    vector<char>s(n);
    for(auto &c:s)cin>>c;
    sort(s.begin(),s.end());
    for(int i=0;i<s.size();i+=2)
    {
        res+=s[i+1]-s[i];
    }
    cout<<res;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    T = 1;
    // cin>>T;
    while (T--)
    {
        sol();
    }
}