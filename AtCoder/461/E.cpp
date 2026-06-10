// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
#define int long long

const int maxn=3e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=1e9+7;

int n,q;
vector<int>col(maxn,0),row(maxn,-1);
vector<int>BITcol(maxn,0),BITrow(maxn,0);

inline int lowbit(int x){return -x&x;}
void update(vector<int>&BIT,int pos,int val)
{
    if(pos==0)return;
    for(int i=pos;i<=q;i+=lowbit(i))
    {
        BIT[i]+=val;
    }
}
int sum(vector<int>&BIT,int pos)
{
    int res=0;
    for(int i=pos;i>0;i-=lowbit(i))
    {
        res+=BIT[i];
    }
    return res;
}

void sol()
{
    cin>>n>>q;
    int res=0;
    for(int i=1;i<=q;i++)
    {
        int x,f;
        cin>>x>>f;
        if(x==1)
        {
            if(row[f]==-1)
            {
                res+=n;
                row[f]=i;
                update(BITrow,i,1);
            }
            else
            {
                res+=sum(BITcol,i)-sum(BITcol,row[f]);
                update(BITrow,row[f],-1);
                update(BITrow,i,1);
                row[f]=i;
            }
        }
        else
        {
            res-=sum(BITrow,i)-sum(BITrow,col[f]);
            update(BITcol,col[f],-1);
            update(BITcol,i,1);
            col[f]=i;
        }
        cout<<res<<'\n';
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
