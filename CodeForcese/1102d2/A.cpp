// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
#define int long long

const int maxn=1e2+5;
const int MAX=0x7fffffffffffffff;
const int mod=998244353;
const int INF=1e9;

int a[maxn];

void sol()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]=-a[i];
    }
    sort(a+1,a+n+1);
    for(int i=3;i<=n;i++)
    {
        int x=-a[i-2],y=-a[i-1],k=-a[i];
        if(x%y!=k)
        {
            cout<<-1<<'\n';
            return;
        }
    }
    for(int i=1;i<=2;i++)
    {
        cout<<-a[i]<<' ';
    }
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
