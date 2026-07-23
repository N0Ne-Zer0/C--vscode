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

struct LinearBasis {
    vector<int>d;
 
    LinearBasis() {
        d.assign(63,0);
    }
 
    bool insert(int val) {
        for (int i = 61; i >= 0; i--) {
            if ((val >> i) & 1) {
                if (!d[i]) {
                    d[i] = val;
                    return true;
                }
                val ^= d[i];
            }
        }
        return false;
    }
 
    int query_max() {
        int res = 0;
        for (int i = 61; i >= 0; i--) {
            if ((res ^ d[i]) > res) {
                res ^= d[i];
            }
        }
        return res;
    }
};

void sol()
{
    int n,S=0;
    cin>>n;
    vector<int>a(n);
    for(auto &x:a)cin>>x;
    sort(a.begin(),a.end());
    for(auto x:a)S^=x;
    int msk=~S;
    LinearBasis lb;
    for(int i=0;i<n;i++)lb.insert(a[i]&msk);
    cout<<S+2*lb.query_max()<<'\n';
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