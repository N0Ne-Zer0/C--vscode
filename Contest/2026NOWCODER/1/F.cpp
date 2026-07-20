#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long

const int maxn=3e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=998244353;
const int INF=1e9;

void sol()
{
    int n,k,x;
    cin>>n>>k>>x;
    vector<int>P(n,0);
    for(auto &X:P)cin>>X;
    int offset=x-P[k];
    for(auto X:P)cout<<(X+offset+n)%n<<' ';
}

signed main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int T;
    T = 1;
    // cin>>T;
    while (T--)sol();
    system("pause");
}