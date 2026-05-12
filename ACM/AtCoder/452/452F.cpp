#include<iostream>
using namespace std;
#define int long long

const int maxn=5e5+15;
const int mod=998244353;

int N,K;
int p[maxn],trev[maxn];

inline int lowbit(int x)
{
    return x&(-x);
}

void add(int p,int w)
{
    if(p==0)return;
    for(;p<=N;p+=lowbit(p))
    {
        trev[p]+=w;
    }
}
int search(int p)
{
    int ans=0;
    for(;p;p-=lowbit(p))
    {
        ans+=trev[p];
    }
    return ans;
}

int Sum(int K)
{
    if(K<0)return 0;
    for(int i=0;i<=N;i++)trev[i]=0;
    int l=0,rev=0,sum=0;
    for(int r=0;r<N;r++)
    {
        rev+=search(N)-search(p[r]);
        add(p[r],1);
        while(l<=r&&rev>K)
        {
            add(p[l],-1);
            rev-=search(p[l]);
            l++;
        }
        sum+=r-l+1;
    }
    return sum;
}

void sol()
{
    cin>>N>>K;
    for(int i=0;i<N;i++)
    {
        cin>>p[i];
    }
    cout<<Sum(K)-Sum(K-1);
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