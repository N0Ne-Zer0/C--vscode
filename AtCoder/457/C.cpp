#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
#define int long long

const int maxn=2e5+5;
const int mod=1e9+7;

int N,K;
vector<int>a[maxn],C(maxn);

void sol()
{
    cin>>N>>K;
    for(int i=1;i<=N;i++)
    {
        int L;
        cin>>L;
        a[i].assign(L+2,0);
        a[i][0]=L;
        for(int j=1;j<=L;j++)
        {
            int tem;
            cin>>tem;
            a[i][j]=tem;
        }
    }
    for(int i=1;i<=N;i++)
    {
        cin>>C[i];
    }
    int cnt=0;
    for(int i=1;i<=N;i++)
    {
        if(cnt+a[i][0]*C[i]<K)
        {
            cnt+=a[i][0]*C[i];
            continue;
        }
        else
        {
            int tem=(K-cnt)%a[i][0];
            if(tem==0)tem=a[i][0];
            cout<<a[i][tem];
            break;
        }
    }
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