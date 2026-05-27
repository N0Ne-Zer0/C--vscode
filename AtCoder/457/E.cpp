#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;
#define int long long

const int maxn=2e5+5;
const int mod=1e9+7;

int N,M,Q;
vector<pair<int,int> >l[maxn],r[maxn];
pair<int,int> maxL[maxn],minR[maxn],a[maxn];
map<pair<int,int>,int>mp;

bool check(int s,int t)
{
    if(l[s].empty()||r[t].empty())return 0;
    auto ans1=lower_bound(l[s].begin(),l[s].end(),make_pair(-t,1ll));
    if(ans1==l[s].end())return 0;
    if(ans1->first==-t)
    {
        if(maxL[t].second==ans1->second&&mp[a[maxL[t].second]]<=1)
        {
            if(minR[s].second==ans1->second&&mp[a[minR[s].second]]<=1)
            {
                return 0;
            }
        }
        if(maxL[t].first>=s||minR->first<=t)return 1;
        return 0;
        // for(int i=s;i<=t;i++)
        // {
        //     if(l[i].empty())continue;
        //     if(l[i].back().first>=-t&&l[i].back().second!=ans1->second)
        //     {
        //         return 1;
        //     }
        // }
        // return 0;
    }
    else
    {
        auto ans2=lower_bound(r[t].begin(),r[t].end(),make_pair(s,1ll));
        if(ans2==r[t].end())return 0;
        if(ans2->first<=(1-ans1->first))return 1;
        else return 0;
    }
}

void sol()
{
    cin>>N>>M;
    for(int i=1;i<=M;i++)
    {
        int tl,tr;
        cin>>tl>>tr;
        a[i]=make_pair(tl,tr);
        l[tl].push_back(make_pair(-tr,i));
        r[tr].push_back(make_pair(tl,i));
        mp[make_pair(tl,tr)]++;
    }
    for(int i=1;i<=N;i++)
    {
        if(l[i].size())
        {
            sort(l[i].begin(),l[i].end());
        }
        if(r[i].size())
        {
            sort(r[i].begin(),r[i].end());
        }
    }
    minR[N+1]=make_pair(0x7fffffff,M+1);
    for(int i=1,j=N;i<=N;i++,j--)
    {
        maxL[i]=maxL[i-1];
        if(r[i].size())
        {
            maxL[i]=max(maxL[i-1],r[i].back());
        }
        minR[j]=minR[j+1];
        if(l[j].size())
        {
            minR[j]=min(minR[j+1],make_pair(-l[j].back().first,l[j].back().second));
        }
    }
    cin>>Q;
    while(Q--)
    {
        int s,t;
        cin>>s>>t;
        if(check(s,t))
        {
            cout<<"Yes\n";
        }
        else
        {
            cout<<"No\n";
        }
    }
}

signed main()
{
    int T=1;
    // cin>>T;
    while(T--)
    {
        sol();
    }
}