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
    char c;
    cin>>n;
    cin>>c;
    bool res=0;
    vector<string>a(n);
    for(auto &s:a)
    {
        cin>>s;
        if(c=='A')
        {
            if(s[0]=='o')res=1;
        }
        if(c=='B')
        {
            if(s[1]=='o')res=1;
        }
        if(c=='C')
        {
            if(s[2]=='o')res=1;
        }
        if(c=='D')
        {
            if(s[3]=='o')res=1;
        }
        if(c=='E')
        {
            if(s[4]=='o')res=1;
        }
    }
    if(res)cout<<"Yes";
    else cout<<"No";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    T = 1;
    // cin>>T;
    while (T--)sol();
}