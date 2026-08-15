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
    int n,w;
    cin>>n>>w;
    string s;
    cin>>s;
    cout<<"Yes\n";
    cout<<w<<' ';
    for(int i=0;i<n-1;i++)
    {
        if(s[i]=='&')cout<<INT_MAX<<' ';
        else cout<<"0 ";
    }
    cout<<'\n';
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