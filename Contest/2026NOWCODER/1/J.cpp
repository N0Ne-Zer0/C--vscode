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
    vector<vector<int>>usedcard(13,vector<int>(4,0));
    vector<vector<pair<int,int>>>card(2,vector<pair<int,int>>(4));
    auto mp=[&](char X,char Y)->pair<int,int>
    {
        pair<int,int>res;
        if(X=='A')res.first=0;
        else if(X=='K')res.first=1;
        else if(X=='Q')res.first=2;
        else if(X=='J')res.first=3;
        else if(X=='T')res.first=4;
        else if(X=='9')res.first=5;
        else if(X=='8')res.first=6;
        else if(X=='7')res.first=7;
        else if(X=='6')res.first=8;
        else if(X=='5')res.first=9;
        else if(X=='4')res.first=10;
        else if(X=='3')res.first=11;
        else res.first=12;
        if(Y=='C')res.second=0;
        else if(Y=='D')res.second=1;
        else if(Y=='H')res.second=2;
        else res.second=3;
        return res;
    };
    for(int i=0;i<4;i++)
    {
        string c;
        cin>>c;
        card[0][i]=mp(c[0],c[1]);
        usedcard[card[0][i].first][card[0][i].second]=1;
    }
    for(int i=0;i<4;i++)
    {
        char c[2];
        cin>>c;
        card[1][i]=mp(c[0],c[1]);
    }
    sort(card[0].begin(),card[0].end());
    sort(card[1].begin(),card[1].end());
    auto T0=[&](int x)->bool
    {

    };
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