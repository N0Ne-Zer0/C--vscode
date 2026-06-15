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
    int n,m;
    cin>>n>>m;
    vector<string>s(n+1,"");
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        s[i]=" "+s[i];
    }
    if(n==1||m==1)
    {
        cout<<"NO";
        return;
    }
    bool fg1=1,fg2=1,fg3=1,fg4=1;
    for(int i=1;i<=n;i++)
    {
        if(s[i][1]=='#')fg4=0;
        if(s[i][m]=='#')fg2=0;
    }
    for(int i=1;i<=m;i++)
    {
        if(s[1][i]=='#')fg1=0;
        if(s[n][i]=='#')fg3=0;
    }
    if((fg1&&fg2)||(fg3&&fg4))cout<<"YES";
    else cout<<"NO";
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