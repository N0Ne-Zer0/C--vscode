#include<iostream>
#include<map>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
#define int long long

const int maxn=1e6+5;
const int MAX=0x7fffffffffffffff;
const int mod=998244353;
const int INF=1e5;

vector<int>prime,fg(maxn);

void init()
{
    for(int i=2;i<maxn;i++)
    {
        if(!fg[i])prime.push_back(i);
        for(auto &p:prime)
        {
            if(p*i>=maxn)break;
            fg[i*p]=1;
            if(i%p==0)break;
        }
    }
}

void sol()
{
    int x;
    cin>>x;
    int t=0;
    for(auto p:prime)
    {
        if(p*p>x)break;
        int cnt=0;
        while(x%p==0)
        {
            cnt++;
            x/=p;
        }
        t=max(t,cnt);
    }
    if(x>1)
    {
        int k=sqrt(x);
        if(k*k==x)t=max(t,2ll);//由于质数只处理到了1e6，还可能存在大于1e6的质数有平方根
        else t=max(t,1ll);
    }
    int res=0;
    while(t)
    {
        t/=2;
        res++;
    }
    cout<<res<<'\n';
}

signed main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int T;
    T = 1;
    init();
    cin>>T;
    while (T--)sol();
    system("pause");
}