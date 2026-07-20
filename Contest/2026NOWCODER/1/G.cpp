#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define int long long

const int maxn=3e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=998244353;
const int INF=1e9;
const double eps=1e-2;
const double PI=acos(-1.0);

void sol()
{
    int n;
    cin>>n;
    cout<<2*n<<'\n';
    double len=eps+1e-4;
    int x=ceil(sqrt(n));
    int cnt=0;
    for(int i=1;i<=x;i++)
    {
        for(int j=1;j<=x;j++)
        {
            if(cnt<n)
            {
                cout<<i*len<<' '<<j*len<<" 0\n";
                cnt++;
            }
        }
    }
    cnt=0;
    for(int i=1;i<=x;i++)
    {
        for(int j=1;j<=x;j++)
        {
            if(cnt<n)
            {
                cout<<i*len<<' '<<j*len<<" 1\n";
                cnt++;
            }
        }
    }
}

signed main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int T;
    T = 1;
    cin>>T;
    while (T--)sol();
    system("pause");
}