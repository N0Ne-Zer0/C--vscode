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
    int n,m;
    cin>>n>>m;
    vector<vector<int>>a(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    if(n==1||m==1)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i][j]!=a[1][1])
                {
                    cout<<"-1\n";
                    return;
                }
            }
        }
        cout<<"0\n";
        return;
    }
    int X=a[1][2]+a[2][1]-a[1][1];
    vector<vector<int>>f(n+1,vector<int>(m+1,0));
    vector<vector<int>>R(n+1,vector<int>(m+1,0));
    vector<vector<int>>D(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            f[i][j]=X-a[i][j];
            if(f[i][j]<0)
            {
                cout<<"-1\n";
                return;
            }
        }
    }
    for(int j=1;j<=m;j++)
    {
        for(int i=n;i;i--)
        {
            if(i==n)D[i][j]=0;
            else
            {
                D[i][j]=f[i+1][j]-R[i+1][j-1];
            }
            R[i][j]=f[i][j]-D[i][j];
            if(D[i][j]<0||R[i][j]<0)
            {
                cout<<"-1\n";
                return;
            }
        }
    }
    for(int i=1;i<n;i++)
    {
        if(R[i][m]!=0)
        {
            cout<<"-1\n";
            return;
        }
    }
    for(int j=2;j<=m;j++)
    {
        if(R[1][j-1]!=f[1][j])
        {
            cout<<"-1\n";
            return;
        }
    }
    cout<<X-a[1][1]<<'\n';
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