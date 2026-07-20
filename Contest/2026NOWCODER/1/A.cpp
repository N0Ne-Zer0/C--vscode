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
    char C[5]={'a','e','i','o','u'};
    string s;
    cin>>s;
    if(s.size()!=8)
    {
        cout<<"Well-Being\n";
        return;
    }
    for(int i=0;i<8;i++)
    {
        if(i%2)
        {
            bool fg=0;
            for(auto c:C)
            {
                if(s[i]==c)fg=1;
            }
            if(!fg)
            {
                cout<<"Well-Being\n";
                return;
            }
        }
        else
        {
            for(auto c:C)
            {
                if(s[i]==c)
                {
                    cout<<"Well-Being\n";
                    return;
                }
            }
        }
    }
    cout<<"Suspected Virus\n";
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