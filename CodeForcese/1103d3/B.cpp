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

void F(char &c)
{
    if(c=='1')c='0';
    else c='1';
}

void sol()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    s=" "+s;
    for(int i=1;i<=n-k;i++)
    {
        if(s[i]=='1')
        {
            s[i]=0;
            F(s[i+k]);
        }
    }
    for(int i=n-k+1;i<=n;i++)
    {
        if(s[i]=='1')
        {
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
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