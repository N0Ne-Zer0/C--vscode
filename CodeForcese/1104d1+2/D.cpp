#include<iostream>
#include<queue>
#include<bitset>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
#define endl '\n'

const int maxn=1e6+5;
const int MAX=0x7fffffffffffffff;
const int mod=998244353;
const int INF=1e9;


void sol()
{
    int n;
    cin>>n;
    string s;
    vector<int>a(n+1,0);
    cin>>s;
    for(int i=0;i<n;i++)
    {
        char c=s[i];
        if(c=='0')a[i+1]=1;
        else a[i+1]=2;
    }
    vector<int>pre(n+1,0);
    for(int i=1;i<=n;i++)
    {
        pre[i]=(pre[i-1]+a[i])%3;
    }
    int res=0,l=1,lst=0;
    int cnt[3]={1,0,0};
    for(int r=1;r<=n;r++)
    {
        if(r>=2&&a[r]==a[r-1])
        {
            lst=r-1;
        }
        while(l<lst)
        {
            cnt[pre[l]]++;
            l++;
        }
        if(lst>0)
        {
            res+=lst-cnt[pre[r]];
        }
        res++;
    }
    cout<<res<<'\n';
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