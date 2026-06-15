#include<iostream>
#include<map>
#include<vector>
#include<bitset>
#include<algorithm>
using namespace std;
#define int long long
#define endl '\n'

const int maxn=5e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=1e9+7;
const int INF=1e9;

bitset<maxn>not_prime;
vector<int>p;
void prime()
{
    for(int i=2;i*i<=5e5;i++)
    {
        if(!not_prime[i])
        {
            p.push_back(i);
        }
        for(auto x:p)
        {
            if(x*i*x*i>5e5)break;
            not_prime[x*i]=1;
            if(i%x==0)break;
        }
    }
}

void sol()
{
    int n,x;
    cin>>n>>x;
    vector<int>a(n+1);
    map<int,int>mp;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        for(auto x:p)
        {
            if(a[i]%x)continue;
            while(a[i]%x==0)
            {
                mp[x]++;
                a[i]/=x;
            }
            if(a[i]==1)break;
        }
        if(a[i]>1)mp[a[i]]++;
    }
    int ans=1;
    for(auto [k,v]:mp)
    {
        ans=(ans*(v+1))%mod;
    }
    cout<<ans<<'\n';
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    T = 1;
    prime();
    cin>>T;
    while (T--)
    {
        sol();
    }
}