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
    int n,k,res=0;
    cin>>n>>k;
    if(n%2)
    {
        int mid=n/2+1;
        if(k<=mid)
        {
            res=(mid-1)*k;
        }
        else
        {
            res+=(mid-1)*mid;
            res+=mid*(k-mid);
        }
    }
    else
    {
        res+=n/2*k;
    }
    cout<<res;
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