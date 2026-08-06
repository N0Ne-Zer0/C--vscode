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
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    auto mex=[&](int x)->int
    {
        if(a[x]!=0&&a[(x+1)%n]!=0&&a[(x+n-1)%n]!=0)return 0;
        if(a[x]!=1&&a[(x+1)%n]!=1&&a[(x+n-1)%n]!=1)return 1;
        if(a[x]!=2&&a[(x+1)%n]!=2&&a[(x+n-1)%n]!=2)return 2;
        return 3;
    };
    for(auto &x:a)cin>>x;
    vector<int>b(a);
    for(int i=1;i<=min(k,10ll);i++)
    {
        for(int j=0;j<n;j++)
        {
            b[j]=mex(j);
            // cout<<b[j]<<' ';
        }
        // cout<<'\n';
        if(i!=min(k,10ll))for(int j=0;j<n;j++)a[j]=b[j];
    }
    if(k<10)for(auto x:b)cout<<x<<' ';
    else if(k%2)for(auto x:a)cout<<x<<' ';
    else for(auto x:b)cout<<x<<' ';
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    T = 1;
    // cin>>T;
    while (T--)sol();
    // system("pause");
}