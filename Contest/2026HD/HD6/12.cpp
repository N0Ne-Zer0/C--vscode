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
    int n;
    cin>>n;
    vector<int>A(n+1,0),B(n+1,0),f(n+1,0);
    for(int i=1;i<=n;i++)cin>>A[i];
    for(int i=2;i<=n;i++)cin>>f[i];
    auto op=[&](int i)
    {
        B[f[i]]+=B[i]+A[i];
        B[i]=0;
    };
    auto sgn=[](int x)
    {
        if(x>0)return 1;
        else if(x==0)return 0;
        else return -1;
    };
    int delta=0;
    for(int i=2;i<=n;i++)delta+=A[i];
    if(delta)
    {
        cout<<sgn(delta)<<'\n';
        return;
    }
    int dt=0,lst=0;
    do
    {
        for(int i=2;i<=n;i++)op(i);
        dt=B[1]-lst;
        lst=B[1];
    }while(dt);
    cout<<sgn(B[1])<<'\n';
}
/*
1
9
-1 -7 3 8 6 -5 4 -9 -2
6 1 5 3 9 9 5 1

*/

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    T = 1;
    cin>>T;
    while (T--)sol();
    // system("pause");
}