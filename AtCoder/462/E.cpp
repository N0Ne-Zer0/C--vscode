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
    int A,B,X,Y;
    cin>>A>>B>>X>>Y;
    X=abs(X);
    Y=abs(Y);
    if(A>B)
    {
        A=min(3*B,A);
        int Z=min(X,Y);//move to (Z,Z)
        int cost=2*Z*B;
        int r=max(X,Y)-Z;
        cost+=(r/2)*(A+B);
        if(r%2)
        {
            if(X==Z)
            {
                cost+=B;
            }
            else
            {
                cost+=A;
            }
        }
        cout<<cost<<endl;
    }
    else
    {
        B=min(3*A,B);
        int Z=min(X,Y);//move to (Z,Z)
        int cost=2*Z*A;
        int r=max(X,Y)-Z;
        cost+=(r/2)*(A+B);
        if(r%2)
        {
            if(X==Z)
            {
                cost+=B;
            }
            else
            {
                cost+=A;
            }
        }
        cout<<cost<<endl;
    }
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