#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
#define int long long

const int maxn=3e5+5;
const int mod=1e9+7;

int N;
struct S
{
    int t,x;
}a[maxn];
vector<int>ans;

bool cmp(S x,S y)
{
    if(x.t==y.t)return x.x<y.x;
    return x.t<y.t;
}

void sol()
{
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        int t,x;
        cin>>t>>x;
        a[i].t=t+x;
        a[i].x=t-x;
    }
    sort(a+1,a+1+N,cmp);
    for(int i=1;i<=N;i++)
    {
        auto pos=lower_bound(ans.begin(),ans.end(),-a[i].x);
        if(pos==ans.end())
        {
            ans.push_back(-a[i].x);
        }
        else
        {
            *pos=-a[i].x;
        }
    }
    cout<<ans.size();
}

signed main()
{
    int T=1;
    // cin>>T;
    while(T--)
    {
        sol();
    }
}