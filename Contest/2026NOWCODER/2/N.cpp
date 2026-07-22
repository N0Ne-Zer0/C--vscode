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
    int n,k,res=0;
    cin>>n>>k;
    vector<int>a(n+1,0);
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a.begin(),a.end());
    for(auto x:a)res+=x;
    // if(k<=2)
    // {
    //     cout<<res<<'\n';
    //     return;
    // }
    int sum=0,mid=0;
    queue<int>que;
    int RES=0,cnt=0;
    if(k%2)
    {
        for(int i=1;i<=k/2;i++)
        {
            sum+=a[i];
            cnt++;
        }
        for(int i=n;i>k/2;i--)
        {
            que.push(a[i]);
            sum+=a[i];
            cnt++;
            if(cnt>k)
            {
                sum-=que.front();
                que.pop();
                cnt--;
            }
            if(cnt==k)
            {
                int tem=a[i]*k-sum;
                RES=max(RES,res+tem);
            }
        }
    }
    else
    {
        for(int i=1;i<k/2;i++)
        {
            sum+=a[i];
            cnt++;
        }
        for(int i=n;i>=k/2;i--)
        {
            que.push(a[i]);
            sum+=a[i];
            cnt++;
            if(cnt>k)
            {
                sum-=que.front();
                que.pop();
                cnt--;
            }
            if(cnt==k)
            {
                int tem=(a[i]+a[i+1])*k/2-sum;
                RES=max(RES,res+tem);
            }
        }
    }
    cout<<RES<<'\n';
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