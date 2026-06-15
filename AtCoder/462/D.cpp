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
    int N,D;
    cin>>N>>D;
    int res=0;
    vector<int>T(1e6+1,0);
    for(int i=1;i<=N;i++)
    {
        int s,t;
        cin>>s>>t;
        if(s+D>t)continue;
        T[s]++;
        T[t-D+1]--;
    }
    int sum=0;
    for(int i=1;i<=1e6;i++)
    {
        sum+=T[i];
        if(sum>=2)
        {
            res+=sum*(sum-1)/2;
        }
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