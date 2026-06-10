// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define int long long

const int maxn=1e6+5;
const int MAX=0x7fffffffffffffff;
const int mod=1e9+7;

string S[maxn];
int x[8]={-1,-1,-1,0,0,1,1,1};
int y[8]={-1,0,1,-1,1,-1,0,1};

void sol()
{
    int H,W;
    cin>>H>>W;
    for(int i=1;i<=H;i++)
    {
        cin>>S[i];
        S[i]=" "+S[i];
    }
    vector<vector<int>>dis(H+5,vector<int>(W+5,-1));
    queue<pair<int,int> >q;
    for(int i=1;i<=H;i++)
    {
        for(int j=1;j<=W;j++)
        {
            if(S[i][j]=='#')continue;
            bool fg=0;
            for(int k=0;k<8;k++)
            {
                int sx=i+x[k],sy=j+y[k];
                if(sx<1||sy<1||sx>H||sy>W)continue;
                if(S[sx][sy]=='#')
                {
                    fg=1;
                    break;
                }
            }
            if(fg)q.push({i,j});
        }
    }
    for(int i=1;i<=H;i++)
    {
        for(int j=1;j<=W;j++)
        {
            if(S[i][j]=='#')S[i][j]='.';
        }
    }
    while(q.size())
    {
        auto [tx,ty]=q.front();
        q.pop();
        S[tx][ty]='#';
    }
    for(int i=1;i<=H;i++)
    {
        for(int j=1;j<=W;j++)
        {
            if(S[i][j]=='#')
            {
                dis[i][j]=0;
                q.push({i,j});
            }
        }
    }
    if(q.empty())
    {
        for(int i=1;i<=H;i++)
        {
            for(int j=1;j<=W;j++)
            {
                cout<<'.';
            }
            cout<<'\n';
        }
        return;
    }
    while(q.size())
    {
        auto [tx,ty]=q.front();
        q.pop();
        for(int i=0;i<8;i++)
        {
            int sx=tx+x[i],sy=ty+y[i];
            if(sx<1||sy<1||sx>H||sy>W||dis[sx][sy]!=-1)continue;
            dis[sx][sy]=dis[tx][ty]+1;
            q.push({sx,sy});
        }
    }
    for(int i=1;i<=H;i++)
    {
        for(int j=1;j<=W;j++)
        {
            cout<<(dis[i][j]%2==0?'.':'#');
        }
        cout<<'\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=1;
    // cin>>T;
    while(T--)sol();
}
