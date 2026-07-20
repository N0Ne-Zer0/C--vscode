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

bool judge(int a,int b,int c)
{
    int v1=(5*b+10*(8*c/b))*a*a*a;
    int v2=(43*c+(8*c/b))*a*a;
    int v3=-(214*b+3833)*a+2*c-5*b-15121;
    int A=1145*a*a-451*a+41;
    return (v1+v2+v3)%A==0;
}

void sol()
{
    int l,r;
    cin>>l>>r;
    for(int a=l;a<=r;a++)
    {
        int b,c;
        b=20639;
        c=260263;
        // if(judge(a,b,c))
        {
            cout<<b<<' '<<c<<'\n';
        }
    }
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