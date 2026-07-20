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
    int n;
    cin>>n;
    vector<pair<int,int>>hl(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>hl[i].second>>hl[i].first;
    }
    sort(hl.begin()+1,hl.end());
    vector<int>suf(n+2,0);
    for(int i=n;i>=1;i--)
    {
        suf[i]=max(suf[i+1],hl[i].second);
    }
    int q;
    cin>>q;
    while(q--)
    {
        int t;
        cin>>t;
        int tem=upper_bound(hl.begin()+1,hl.end(),make_pair(t,INF))-hl.begin();
        cout<<suf[tem]<<'\n';
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    T = 1;
    // cin>>T;
    while (T--)sol();
}