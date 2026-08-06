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
    int mid;
    vector<int>p(n+1,0);
    if(n%2)
    {
        if(n==1)
        {
            cout<<"1\n";
            return;
        }
        p[1]=1;
        p[3]=2;
        int x=n/2+3;
        for(int i=5;i<=n;i+=2)
        {
            p[i]=x++;
        }
        x=n/2+2;
        for(int i=2;i<=n;i+=2)
        {
            p[i]=x--;
        }
        for(int i=1;i<=n;i++)cout<<p[i]<<' ';
        cout<<'\n';
        return;
    }
    else mid=n/2+1;
    int idx=-1;
    for(int i=mid;i<=n;i++)
    {
        idx+=2;
        p[idx]=i;
    }
    idx=0;
    for(int i=mid-1;i>0;i--)
    {
        idx+=2;
        p[idx]=i;
    }
    if(idx==0)idx=1;
    for(int i=idx;i<=n;i++)cout<<p[i]<<' ';
    for(int i=1;i<idx;i++)cout<<p[i]<<' ';
    cout<<'\n';
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