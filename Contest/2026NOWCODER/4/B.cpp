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
    int p;
    cin>>p;
    int x1=1;
    if(p==2)
    {
        cout<<"12 1 71\n";
        return;
    }
    if(p==3)
    {
        cout<<"4 1 13\n";
        return;
    }
    while(x1<p)
    {
        int x2=p-x1;
        int q=x1*x1-p;
        if(x1<q&&x2>0)
        {
            cout<<x1<<' '<<x2<<' '<<q<<'\n';
            return;
        }
        x2=x1;
        q=x1*x1-p;
        if(x1<q&&x2<p)
        {
            cout<<x1<<' '<<x2<<' '<<q<<'\n';
            return;
        }
        x1++;
    }
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