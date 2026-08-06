#include<iostream>
#include<queue>
#include<vector>
#include<bitset>
#include<algorithm>
using namespace std;
#define int long long

const int maxn=3e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=998244353;
const int INF=1e9;
const int MAXL=100;

struct LinearBasis {
    static const int MAXL=100;
    vector<int>val;
    bitset<MAXL>b[MAXL];
 
    LinearBasis() {
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
    LinearBasis lb;
    int K;
    cin>>K;
    while(K--)
    {
        int C,S;
        cin>>C>>S;
        bitset<MAXL>x;
        x.reset();
        for(int i=0;i<C;i++)
        {
            int L;
            cin>>L;
            x.flip(L-1);
        }
        lb.insert(x,S);
    }
    int Q;
    cin>>Q;
    while(Q--)
    {
        int D;
        cin>>D;
        bitset<MAXL>x;
        x.reset();
        for(int i=0;i<D;i++)
        {
            int R;
            cin>>R;
            x.flip(R-1);
        }
        int res=lb.query(x);
        cout<<res<<'\n';
    }
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