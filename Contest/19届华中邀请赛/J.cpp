#include<iostream>
#include<queue>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
#define endl '\n'

const int maxn=3e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=998244353;
const int INF=1e9;

struct tri
{
    pair<int,int>a,b,c;
    bool fg;
}tri[maxn];
int v[maxn];
int cnt,cntv;
map<int,int>mp;
map<pair<int,int>,int>mpv;

pair<int,int> mid(pair<int,int>a,pair<int,int>b)
{
    return {(a.first+b.first)>>1,(a.second+b.second)>>1};
}

int query(int i)
{
    // cout<<"A=>"<<mpv[tri[mp[i]].a]<<":"<<v[mpv[tri[mp[i]].a]]<<'\n';
    // cout<<"B=>"<<mpv[tri[mp[i]].b]<<":"<<v[mpv[tri[mp[i]].b]]<<'\n';
    // cout<<"C=>"<<mpv[tri[mp[i]].c]<<":"<<v[mpv[tri[mp[i]].c]]<<'\n';
    return v[mpv[tri[mp[i]].a]]+v[mpv[tri[mp[i]].b]]+v[mpv[tri[mp[i]].c]];
}
void update(int i,int y)
{
    // cout<<mpv[tri[mp[i]].a]<<"==>"<<y<<'\n';
    // cout<<mpv[tri[mp[i]].b]<<"==>"<<y<<'\n';
    // cout<<mpv[tri[mp[i]].c]<<"==>"<<y<<'\n';
    v[mpv[tri[mp[i]].a]]=y;
    v[mpv[tri[mp[i]].b]]=y;
    v[mpv[tri[mp[i]].c]]=y;
}
void extend(int i)
{
    auto [a,b,c,fg]=tri[mp[i]];
    auto d=mid(a,b);
    auto e=mid(a,c);
    auto f=mid(b,c);
    if(mpv.find(d)==mpv.end())
    {
        mpv[d]=++cntv;
        v[cntv]=1;
    }
    if(mpv.find(e)==mpv.end())
    {
        mpv[e]=++cntv;
        v[cntv]=1;
    }
        if(mpv.find(f)==mpv.end())
    {
        mpv[f]=++cntv;
        v[cntv]=1;
    }

    mp.insert({4*i,++cnt});
    if(fg)
    {
        tri[cnt]={a,d,e,fg};
    }
    else
    {
        tri[cnt]={d,b,f,fg};
    }

    mp.insert({4*i+1,++cnt});
    if(fg)
    {
        tri[cnt]={d,b,f,fg};
    }
    else
    {
        tri[cnt]={a,d,e,fg};
    }

    mp.insert({4*i+2,++cnt});
    tri[cnt]={e,f,d,!fg};

    mp.insert({4*i+3,++cnt});
    tri[cnt]={e,f,c,fg};

}

void sol()
{
    int q;
    cin>>q;
    mp.insert({1,++cnt});
    pair<int,int>a,b,c;
    a={-1*(1<<30),0};
    b={1<<30,0};
    c={0,1<<31};
    tri[cnt]={a,b,c,1};
    mpv[a]=++cntv;
    v[cntv]=1;
    mpv[b]=++cntv;
    v[cntv]=1;
    mpv[c]=++cntv;
    v[cntv]=1;
    while(q--)
    {
        string s;
        int i;
        cin>>s;
        cin>>i;
        if(s=="query")
        {
            cout<<query(i)<<'\n';
        }
        if(s=="update")
        {
            int y;
            cin>>y;
            update(i,y);
        }
        if(s=="extend")
        {
            extend(i);
        }
    }
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