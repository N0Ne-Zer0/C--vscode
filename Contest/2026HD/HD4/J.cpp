#include<iostream>
#include<map>
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
    int n;
    cin>>n;
    vector<int>a(n),b(n+1,0);
    int cnt=0;
    for(auto &x:a)
    {
        cin>>x;
        b[x]++;
        if(b[x]%4==1)cnt++;
        if(b[x]%4==0)cnt--;
        if(cnt==0)
        {
            
        }
    }
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