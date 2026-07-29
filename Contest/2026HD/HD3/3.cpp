#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long

const int maxn=3e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=1e18;
const int INF=1e18+1;

void sol()
{
    int n,res=0;
    cin>>n;
    vector<int>b(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    vector<int>dp;
    for(int i=1;i<=n;i++)
    {
        auto pos=upper_bound(dp.begin(),dp.end(),b[i]);
        if(pos==dp.end())
        {
            int tem=b[i];
            if(dp.size())tem+=dp.back();
            dp.push_back(tem);
        }
		else if(pos==dp.begin())
		{
			*pos=b[i];
		}
        else
        {
			int tem=*(pos-1)+b[i];
			*pos=min(tem,*pos);
        }
    }
    cout<<dp.size()<<'\n';
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    T = 1;
    cin>>T;
    while (T--)sol();
    // system("pause");
}