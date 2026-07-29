#include<iostream>
#include<vector>
#include<bitset>
#include<algorithm>
using namespace std;
#define int long long

const int maxn=3e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=998244353;
const int INF=1e9;

void sol()
{
    int n;
    cin>>n;
    vector<vector<vector<int>>>cnt(32,vector<vector<int>>(2,vector<int>(2,0)));
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        for(int j=0;j<31;j++)
        {
            int biti=(a>>j)&1;
            int biti_=(a>>(j+1))&1;
            cnt[j][biti][biti_]++;
        }
    }
    int m;
    cin>>m;
    int bit0=0,bit1=(1<<31)-1;
    while(m--)
    {
        int type,x;
        cin>>type>>x;
        if(type==1)
        {
            bit0&=x;
            bit1&=x;
        }
        else if(type==2)
        {
            bit0|=x;
            bit1|=x;
        }
        else
        {
            bit0^=x;
            bit1^=x;
        }
        int res=0;
        for(int j=0;j<31;j++)
        {
            int bitj0=(bit0>>j)&1;
            int bitj1=(bit1>>j)&1;
            int bitj_0=(bit0>>(j+1))&1;
            int bitj_1=(bit1>>(j+1))&1;
            if(bitj0==1&&bitj_0==0)res+=cnt[j][0][0];
            if(bitj0==1&&bitj_1==0)res+=cnt[j][0][1];
            if(bitj1==1&&bitj_0==0)res+=cnt[j][1][0];
            if(bitj1==1&&bitj_1==0)res+=cnt[j][1][1];
        }
        cout<<res<<'\n';
    }
}

signed main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int T;
    T = 1;
    // cin>>T;
    while (T--)sol();
    system("pause");
}