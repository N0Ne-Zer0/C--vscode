#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define int unsigned long long

const int maxn=3e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=998244353;
const int INF=1e9;

void sol()
{
    int n,S=0;
    cin>>n;
    vector<int>a(n),b(n);
    for(auto &x:a)cin>>x;
    sort(a.begin(),a.end());
    for(auto x:a)S^=x;
    int msk=~S;
    for(int i=0;i<n;i++)b[i]=a[i]&msk;
    vector<int>p(64,0);
    auto insert=[&](int x)
    {
        for(int i=63;~i;i--)
        {
            if(!(x>>i))continue;
            if(!p[i])
            {
                p[i]=x;
                break;
            }
            x^=p[i];
        }
    };
    for(auto x:b)insert(x);
    int res=0;
    for(int i=63;~i;i--)
    {
        res=max(res,res^p[i]);
    }
    cout<<S+2*res<<'\n';
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