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
    int n;
    cin>>n;
    vector<int>a(n+1,0);
    int cur=0;//cur=sum[l,r]
    for(int l=1;l<=n;l++)
    {
        cin>>a[l];
        if(a[l]>=cur)
        {
            cur=a[l];
        }
        else
        {
            cur+=a[l];
        }
    }
    cout<<cur<<'\n';
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