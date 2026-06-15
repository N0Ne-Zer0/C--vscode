// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
#define int long long

const int maxn=2e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=998244353;
const int INF=1e9;



void sol()
{
    int n,k;
    string s;
    vector<int>a;
    cin>>n>>k;
    cin>>s;
    vector<int>fg(n,-1);
    vector<bool>ans(n,0);
    int cnt=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(')
        {
            a.push_back(i);
        }
        else
        {
            if(a.empty())
            {
                a.push_back(i);
                continue;
            }
            if(s[a.back()]=='(')
            {
                fg[i]=a.back();
                fg[a.back()]=i;
                a.pop_back();
            }
        }
    }
    for(int i=0;i<s.size();i++)
    {
        if(cnt>=k)break;
        if(fg[i]<i)continue;
        if(fg[i]==INF)continue;
        int l=i,r=fg[i];
        int fl=1,fr=1;
        for(int j=l+1;j<s.size();j++)
        {
            if(fg[j]!=-1)continue;
            if(fg[j]==INF)continue;
            if(s[j]==')')
            {
                fl=0;
                break;
            }
        }
        for(int j=r-1;j>=0;j--)
        {
            if(fg[j]!=-1)continue;
            if(fg[j]==INF)continue;
            if(s[j]=='(')
            {
                fr=0;
                break;
            }
        }
        if(fr)
        {
            fg[r]=-1;
            fg[l]=INF;
            ans[l]=1;
            cnt++;
        }
        else
        {
            if(fl)
            {
                fg[l]=-1;
                fg[r]=INF;
                ans[r]=1;
                cnt++;
            }
        }
    }
    for(auto i:ans)cout<<i;
    cout<<'\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=1;
    cin>>T;
    while(T--)sol();
}
