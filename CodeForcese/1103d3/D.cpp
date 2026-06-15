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

inline int lb(int x)
{
    return -x&x;
}
inline void add(vector<int>&BIT,int x,int v=1)
{
    for(int i=x;i<BIT.size();i+=lb(i))
    {
        BIT[i]+=v;
    }
}
inline int search(const vector<int>&BIT,int x)
{
    int res=0;
    for(int i=x;i>0;i-=lb(i))
    {
        res+=BIT[i];
    }
    return res;
}

void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n+1,0);
    vector<int>tr(n+1);
    vector<int>ct(n+1,0);
    vector<int>bt(1,0);
    int cnt=0;
    vector<int>dp(n+1,-1);//dp[i]means player del this cell and will win or fail
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a.begin()+1,a.end());
    int lst=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=lst)
        {
            lst=a[i];
            bt.push_back(a[i]);
            ct[++cnt]++;
        }
        else
        {
            ct[cnt]++;
        }
    }
    for(int i=cnt;i>=1;i--)
    {
        int j=upper_bound(bt.begin()+1,bt.end(),bt[i]+k)-bt.begin()-1;
        if(i==j)
        {
            if(ct[i]%2)
            {
                dp[i]=0;
            }
            else
            {
                dp[i]=1;
                add(tr,i);
            }
            continue;
        }
        if(search(tr,j)-search(tr,i)<j-i)//have P => N pos
        {
            dp[i]=1;
            add(tr,i);
        }
        else//not P
        {
            if(ct[i]%2)//odd => P
            {
                dp[i]=0;
            }
            else//even => N
            {
                dp[i]=1;
                add(tr,i);
            }
        }
    }
    for(int i=1;i<=cnt;i++)
    {
        if(dp[i]==1)
        {
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
}
//1 2 3 4
//P N N P
//if I can move to P => the pos is N
//if I cant move to P,
    //if cnt is odd => the pos is P
    //if cnt is even => the pos still N
//choos y that x<= y <= x+k
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    T = 1;
    cin>>T;
    while (T--)
    {
        sol();
    }
}