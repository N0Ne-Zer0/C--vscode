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

// vector<int>seq;
// vector<vector<int>>maxseq;
int maxdmg=0;
void dfs(int x,int y,int k,int dmg,int p)
{
    if(x+y==0)
    {
        if(maxdmg<dmg)
        {
            maxdmg=dmg;
            // maxseq.clear();
        }
        // if(maxdmg==dmg)maxseq.push_back(seq);
        return;
    }
    if(p)
    {
        // seq.push_back(1);
        if(x>0)dfs(x-1,y,k+1,dmg,p^1);
        // seq.pop_back();
        // seq.push_back(0);
        if(y>0)dfs(x,y-1,1,dmg+k*(x+y-1),p^1);
        // seq.pop_back();
    }
    else
    {
        // seq.push_back(0);
        if(y>0)dfs(x,y-1,1,dmg+k*(x+y-1),p^1);
        // seq.pop_back();
        // seq.push_back(1);
        if(x>0)dfs(x-1,y,k+1,dmg,p^1);
        // seq.pop_back();
    }
}

void sol()
{
    int x,y;
    cin>>x>>y;
    // maxseq.clear();
    maxdmg=0;
    if(x<=y)dfs(x,y,1,0,0);
    else dfs(x,y,1,0,1);
    cout<<maxdmg<<'\n';
    // for(auto q:maxseq)
    // {
    //     for(auto x:q)
    //     {
    //         cout<<x;
    //     }
    //     cout<<'\n';
    // }
    // cout<<"======\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    T = 1;
    // cin>>T;
    while (T--)sol();
    // system("pause");
}