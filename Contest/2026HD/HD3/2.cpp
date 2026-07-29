#include<iostream>
#include<queue>
#include<vector>
#include<iomanip>
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
    long double w;
    cin>>n>>w;
    long double S=0.0;
    vector<long double>x(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>x[i];
        S+=(long double)1.0/x[i];
    }
    sort(x.begin(),x.end());
    long double sum=1.0/x[1];
    for(int i=2;i<=n;i++)
    {
        sum+=1.0/x[i];
        long double C=(i-sum)/(i-1.0);
        S=min(S,C);
    }
    cout<<fixed<<setprecision(10)<<w/S<<'\n';
}

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