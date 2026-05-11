#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
#define int long long

const int maxn=2e5+5;
const int mod=1e9+7;

int n,x,y;
vector<int>a[maxn];

void sol()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        a[i].assign(x+2,0);
        for(int j=1;j<=x;j++)
        {
            int tem;
            cin>>tem;
            a[i][j]=tem;
        }
    }
    cin>>x>>y;
    cout<<a[x][y];
}

signed main()
{
    int T=1;
    // cin>>T;
    while(T--)
    {
        sol();
    }
}