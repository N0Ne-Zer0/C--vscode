// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
#define int long long

const int maxn=2e5+5;
const int mod=1e9+7;

int sum[128];

void sol()
{
    string s;
    priority_queue<pair<int,char>>a;
    int maxc=0;
    cin>>s;
    for(int i='a';i<='z';i++)sum[i]=0;
    for(int i=0;i<s.size();i++)
    {
        sum[s[i]]++;
        if(sum[s[i]]>maxc)
        {
            maxc=sum[s[i]];
        }
    }
    for(int i='a';i<='z';i++)if(sum[i]>0)a.push(make_pair(sum[i],char(i)));
    if((s.size()+1)/2<maxc)
    {
        cout<<"No\n";
        return;
    }
    cout<<"Yes\n";
    int idx=0;
    while(a.size())
    {
        int tsum=a.top().first;
        int tchar=a.top().second;
        a.pop();
        while(idx<s.size()&&tsum>0)
        {
            s[idx]=tchar;
            tsum--;
            idx+=2;
            if(idx>=s.size())idx=1;
        }
    }
    cout<<s;
    // while(a.size())
    // {
    //     int tsum=a.top().first;
    //     char tchar=a.top().second;
    //     a.pop();
    //     cout<<tchar;
    //     tsum--;
    //     if(a.empty())break;
    //     int xsum=a.top().first;
    //     char xchar=a.top().second;
    //     cout<<xchar;
    //     xsum--;
    //     a.pop();
    //     if(tsum>0)a.push(make_pair(tsum,tchar));
    //     if(xsum>0)a.push(make_pair(xsum,xchar));
    // }
    cout<<'\n';
}

signed main()
{
    int T=1;
    cin>>T;
    while(T--)
    {
        sol();
    }
}