// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define int long long

const int maxn=5e2+5;
const int MAX=0x7fffffffffffffff;
const int mod=1e9+7;

bool mp[maxn][maxn];
int preh[maxn][maxn];

void sol()
{
    int h,w,k;
    cin>>h>>w>>k;
    string s;
    for(int i=0;i<h;i++)
    {
        cin>>s;
        for(int j=0;j<w;j++)
        {
            if(s[j]=='1')mp[i+1][j+1]=1;
        }
    }
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
        {
            preh[i][j]=preh[i][j-1]+mp[i][j];
        }
    }
    int ans=0;
    for(int l=1;l<=w;l++)
    {
        for(int r=l;r<=w;r++)
        {
            int tr=1;
            vector<int>sum(h+1,0);
            for(tr=1;tr<=h;tr++)
            {
                sum[tr]=sum[tr-1]+preh[tr][r]-preh[tr][l-1];
            }
            int r1=1,r2=1;
            for(int i=1;i<=h;i++)
            {
                r1=max(r1,i),r2=max(r2,i);
                while(r1<=h&&sum[r1]-sum[i-1]<k)r1++;
                while(r2<=h&&sum[r2]-sum[i-1]<=k)r2++;
                ans+=r2-r1;
            }
        }
    }
    cout<<ans;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=1;
    // cin>>T;
    while(T--)sol();
}
