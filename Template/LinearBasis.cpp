#include<iostream>
#include<queue>
#include<bitset>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long

const int maxn=3e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=998244353;
const int INF=1e9;

struct LinearBasis {
    static const int MAXL=100;
    vector<int>val;
    bitset<MAXL>b[MAXL];
 
    LinearBasis(){clear();}

    void clear()
    {
        val.assign(MAXL,0);
        for(auto x:b)x.reset();
    }
 
    void insert(bitset<MAXL>x,int v) {
        for(int i=MAXL-1;i>=0;i--)
        {
            if(!x[i])continue;
            if(b[i].none())
            {
                b[i]=x;
                val[i]=v;
                return;
            }
            x^=b[i];
            v^=val[i];
        }
    }
 
    int query(bitset<MAXL>x) {
        int res=0;
        for(int i=MAXL-1;i>=0;i--)
        {
            if(!x[i])continue;
            if(b[i].none())return -1;
            x^=b[i];
            res^=val[i];
        }
        return res;
    }
};

void sol()
{
    
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