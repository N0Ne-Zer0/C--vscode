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

void sol()
{
    string s;
    string tmp="Rounddo";
    cin>>s;
    int ss=s.size();
    int k;
    cin>>k;
    for(int i=1;i<=k;i++)tmp+="g";
    int idx=0,cnt=0;
    if(s.size()<tmp.size())
    {
        cout<<"0\n";
        return;
    }
    for(auto c:s)
    {
        if(c==tmp[idx])idx++;
        else idx=0;
        if(idx==tmp.size())
        {
            idx=0;
            cnt++;
        }
    }
    if(idx>0)
    {
        for(int i=0;idx;i++)
        {
            if(s[i]==tmp[idx])idx++;
            else idx=0;
            if(idx==tmp.size())
            {
                idx=0;
                cnt++;
            }
        }
    }
    int res=0;
    if(cnt>=2)res=ss;
    else if(cnt==1)
    {
        res=ss-tmp.size()+1;
    }
    else res=0;
    cout<<res<<'\n';
}
/*
1
ggggggggggggggRounddoggg
6
*/

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