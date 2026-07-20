#include<iostream>
#include<queue>
#include<vector>
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
    int n;
    cin>>n;
    if((n-2)%3||n<8)
    {
        cout<<"-1\n";
        return;
    }
    int x=(n-2)/3;
    vector<int>res(n,-1);
    for(int i=0;i<x+2;i++)res[i]=0;
    int cnt=x+2;
    int j=n-1;
    if(x%3==0)
    {
        res[j]=0;
        j--;
    }

    if(x%3==1)
    {
        res[j]=0;
        j--;
        res[j]=0;
        j--;
    }

    while(cnt--)
    {
        res[j--]=1;
    }
    int C=0;
    for(int i=x+2;i<n;i++)
    {
        if(res[i]==1)break;
        res[i]=!C;
        C++;
        if(C==3)C=0;
    }
    for(auto x:res)cout<<x<<' ';
    cout<<'\n';
}

vector<bool>fg(100);
int FG=0;

void dfs(vector<int>&s,int l)
{
    if(FG>=2)return;
    if(l==0)
    {
        int c1=0,c0=0;
        int sum1=0;
        int cnt0=0,cnt1=0,cnt2=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i])sum1++;
            if(s[i])c1++;
            else c0++;
            if(c0+c1>3)
            {
                if(s[i-3])c1--;
                else c0--;
            }
            if(c1+c0==3)
            {
                if(c1&&c0)cnt2++;
                if(c1&&!c0)cnt0++;
                if(!c1&&c0)cnt1++;
            }
        }
        if(cnt0&&cnt0==cnt2&&cnt0==cnt1)
        {
            FG++;
            if(fg[sum1])return;
            fg[sum1]=1;
            cout<<sum1<<"===";
            for(auto x:s)cout<<(x==1?'#':'.');
            cout<<'\n';
        }

        return;
    }

    s.push_back(0);
    dfs(s,l-1);
    s.pop_back();

    s.push_back(1);
    dfs(s,l-1);
    s.pop_back();
}

void S(int x)
{
    vector<int>s;
    FG=0;
    fg.assign(100,0);
    dfs(s,x);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    T = 1;
    // for(int i=14;i<=40;i+=9)
    // {
    //     cout<<"======="<<i<<"===========\n";
    //     S(i);
    //     cout<<'\n';
    // }
    cin>>T;
    while (T--)
    {
        sol();
    }
}