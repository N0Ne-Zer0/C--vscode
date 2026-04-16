#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
#define endl '\n'

const int maxn = 5e5 + 5;

int n, k, L, l[maxn], r[maxn], diff[maxn];
int x[maxn];
int sl[maxn],sr[maxn],cnt,pre[maxn];
vector<int>vec;

void sol()
{
    cin >> n >> k >> L;
    for (int i = 0; i < n; i++)
    {
        cin >> l[i] >> r[i];
        vec.push_back(l[i]);
        vec.push_back(r[i] + 1);
    }


    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());


    for (int i = 0; i < n; i++)
    {
        int dl = lower_bound(vec.begin(), vec.end(), l[i]) - vec.begin();
        int dr = lower_bound(vec.begin(), vec.end(), r[i] + 1) - vec.begin();
        diff[dl]++;
        diff[dr]--;
    }


    x[0] = diff[0];
    int cur=0;
    for (int i = 0; i < vec.size(); i++)
    {
        cur+=diff[i];
        x[i]=cur;
    }


    int total=0;
    for(int i=0;i<vec.size()-1;i++)
    {
        int tl=vec[i],tr=vec[i+1];
        if(x[i]>k)total+=tr-tl;//左闭右开
        if(x[i]==k+1)
        {
            sl[cnt]=tl;
            sr[cnt]=tr-1;
            cnt++;
        }
    }

    pre[0]=sr[0]-sl[0]+1;
    for(int i=1;i<cnt;i++)
    {
        pre[i]=pre[i-1]+sr[i]-sl[i]+1;
    }

/*    cout<<total<<'\n';

    for(int i=0;i<cnt;i++)
    {
        cout<<sl[i]<<' '<<sr[i]<<'\n';
    }
*/


    int left=0,right=0,ans=0;
    while(sr[right]-sl[0]+1<L)right++;
    right--;
    for(;right<cnt;right++)
    {
        
        while(sr[right]-sl[left]+1>L&&left<=right)left++;
        if(left>right)continue;

        int tem;
        if(left>0)tem=pre[right]-pre[left-1];
        else tem=pre[right];

        int len=sr[right]-sl[left]+1;
        
        //L固定在右
        int Lextra=0;
        if(left>0&&sr[right]-L+1>=0&&sr[right]-L+1<=sr[left-1])
        {
            Lextra=sr[left-1]-(sr[right]-L+1)+1;
        }

        //L固定在左
        int Rextra=0;
        if(right<cnt-1&&sl[left]+L-1>=sl[right+1])
        {
            Rextra=(sl[left]+L-1)-sl[right+1]+1;
        }
        tem+=max(Rextra,Lextra);
        ans=max(ans,tem);
    }
    cout<<total-ans<<endl;
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