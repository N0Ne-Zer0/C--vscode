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
    int x,y,res=0;
    cin>>x>>y;
    if(y==0)
    {
        cout<<"0\n";
        return;
    }
    if(x==0)
    {
        res=y*(y-1)/2;
        cout<<res<<'\n';
        return;
    }
    if(x==1)
    {
        res=y*(y+1)/2;
        cout<<res<<'\n';
        return;
    }
    if(x<=y)
    {
        res+=x+y-1;

        res+=2*(x+y)*(x-2);
        res-=2*x*(x-2);

        res+=(y-x)*(y-x+1)/2;
        res+=2*(y-x+1);
    }
    else
    {
        int L=x/(y+1);
        int r=x%(y+1);
        int C=r*(L+2);
        if(r)
        {
            res+=(L+2)*((L+2)*r*(r+1)/2-r);
            res-=r*(L+2)-1;
        }
        res+=(L+1)*((L+1)*(y-r)*(y-r+1)/2+(y-r)*(C-1));
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
    while (T--)sol();
    // system("pause");
}