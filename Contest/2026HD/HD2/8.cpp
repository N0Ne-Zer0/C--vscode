#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
#define YES cout<<"Yes\n"
#define NO cout<<"No\n"

const int maxn=3e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=998244353;
const int INF=1e9;

void sol()
{
    int n;
    cin>>n;
    vector<int>d(n+1,0);
    vector<vector<int>>s(n+1,vector<int>(1,0));
    vector<int>idx(n+1,1);
    int mi=MAX,ma=0;

    auto add_edge=[](int x,int y)
    {
        cout<<x<<' '<<y<<'\n';
    };

    for(int i=1;i<=n;i++)
    {
        cin>>d[i];
        mi=min(mi,d[i]);
        ma=max(ma,d[i]);
        s[d[i]][0]++;
        s[d[i]].push_back(i);
    }
    if(s[mi][0]>2)
    {
        NO;
        return;
    }
    if(s[mi][0]==2)
    {
        if(ma==2*mi-2)
        {
            for(int i=mi;i<=ma;i++)
            {
                if(s[i][0]<2)
                {
                    NO;
                    return;
                }
            }
            //合法
            YES;
            for(int i=ma;i>mi;i--)
            {
                add_edge(s[i][idx[i]++],s[i-1][idx[i-1]]);
            }
            add_edge(s[mi][idx[mi]],s[mi][idx[mi]++]);
            for(int i=ma;i>mi;i--)
            {
                add_edge(s[i][idx[i]++],s[i-1][idx[i-1]]);
            }


            for(int i=ma;i>mi;i--)
            {
                while(idx[i]<s[i].size())
                {
                    add_edge(s[i][idx[i]++],s[i-1][1]);
                }
            }
        }
        else
        {
            NO;
            return;
        }
    }
    else
    {
        if(ma==2*mi-1)
        {
            for(int i=mi+1;i<=ma;i++)
            {
                if(s[i][0]<2)
                {
                    NO;
                    return;
                }
            }
            //合法
            YES;
            for(int i=ma;i>mi;i--)
            {
                add_edge(s[i][idx[i]++],s[i-1][idx[i-1]]);
            }
            for(int i=ma;i>mi;i--)
            {
                add_edge(s[i][idx[i]++],s[i-1][idx[i-1]]);
            }

            for(int i=ma;i>mi;i--)
            {
                while(idx[i]<s[i].size())
                {
                    add_edge(s[i][idx[i]++],s[i-1][1]);
                }
            }
        }
        else
        {
            NO;
            return;
        }
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