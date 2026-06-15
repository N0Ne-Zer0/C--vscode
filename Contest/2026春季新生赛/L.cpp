#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
#define endl '\n'

const int maxn = 5e5 + 5;



void sol()
{
    int n,k,L;
    cin>>n>>k>>L;
    vector<int>a(2*n);
    vector<pair<int,int>>A(n);
    for(int i=0;i<n;i++)
    {
        int l,r;
        cin>>l>>r;
        A[i]={l,r};
        a.push_back(l);
        a.push_back(r+1);
    }
    sort(a.begin(),a.end());
    int len=unique(a.begin(),a.end())-a.begin();
    vector<int>diff(len,0);
    vector<bool>res(len,0);
    for(auto [l,r]:A)
    {
        int li=lower_bound(a.begin(),a.end(),l)-a.begin();
        int ri=lower_bound(a.begin(),a.end(),r+1)-a.begin();
        diff[li]++;
        diff[ri]--;
    }
    int sum=0,ans=0;
    for(int i=0;i<len;i++)
    {
        sum+=diff[i];
        if(sum>k&&i+1<len)
        {
            ans+=a[i+1]-a[i];
        }
        if(sum==k+1)
        {
            res[i]=1;
        }
    }
    int minus=0;
    int l=len-1,r=0,tminus=0;
    for(int i=0;i<len;i++)
    {
        if(res[i]==0)continue;
        r=max(r,i);
        while(r<len&&a[r]-a[i]<L)
        {
            tminus+=(a[r+1]-a[r])*res[r];
            r++;
        }
        tminus+=(L-a[r]+a[i])*res[r];
        minus=max(minus,tminus);
        tminus-=a[i+1]-a[i];
        tminus=max(tminus,0ll);
    }
    for(int i=len-2;i>=0;i--)
    {
        if(res[i]==0)continue;
        l=min(l,i);
        while(l>=0&&a[i+1]-a[l]<L)
        {
            tminus+=(a[l+1]-a[l])*res[l];
            l--;
        }
        tminus+=(L-a[i+1]+a[l+1])*res[l];
        minus=max(minus,tminus);
        tminus-=a[i+1]-a[i];
        tminus=max(tminus,0ll);
    }
    cout<<ans-minus;
}


signed main()
{
    int T;
    T = 1;
    // cin>>T;
    while (T--)
    {
        sol();
    }
}