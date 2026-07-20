#include<iostream>
#include<queue>
#include<vector>
#include<map>
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
    string s;
    cin>>s;
    int len=s.size();
    s=' '+s;
    string ABC="ABC",CBA="CBA";
    vector<int>C(len+3,0),bonus(len+1,0);
    int abc=0,cba=0;
    int res=0;
    for(int i=1;i<=len;i++)
    {
        char c=s[i];
        if(c==ABC[abc])
        {
            abc++;
        }
        else
        {
            abc=0;
            if(c==ABC[abc])abc++;
        }
        if(c==CBA[cba])
        {
            cba++;
        }
        else
        {
            cba=0;
            if(c==CBA[cba])cba++;
        }
        if(abc==3)
        {
            C[i]++;
            abc=0;
            bonus[i-2]=1;
            bonus[i-1]=1;
            res++;
        }
        if(cba==3)
        {
            C[i]--;
            cba=0;
        }
    }
    int m=0;
    int pre1=0,pre2=0;
    for(int i=1;i<=len;i++)
    {
        pre1+=C[i];
        int seg=pre1-pre2+bonus[i];
        m=max(m,seg);
        pre2=min(pre2,pre1);
    }
    res-=m;
    cout<<res;
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