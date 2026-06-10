// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
#define int long long

const int maxn=3e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=998244353;
const int INF=1e9;

// bool F(int a)
// {
//     vector<int>m;
//     while(a)
//     {
//         m.push_back(a%10);
//         a/=10;
//     }
//     for(auto i=1u;i<m.size();i++)
//     {
//         int j=m.size()-i-1;
//         if(m[i]!=m[j])return 0;
//     }
//     return 1;
// }

void sol()
{
    // for(int i=1;i<=100;i++)
    // {
    //     int a,b;
    //     cout<<"==========\n";
    //     cout<<i<<'\n';
    //     for(a=0;a<=i;a++)
    //     {
    //         b=i-a;
    //         if(b%12)continue;
    //         if(!F(a))continue;
    //         cout<<a<<' '<<b<<'\n';
    //         break;
    //     }
    // }
    int n;
    cin>>n;
    if(n==10)
    {
        cout<<-1<<'\n';
        return;
    }
    int a,b;
    if(n%12<=9)
    {
        a=n%12;
        b=n-a;
    }
    else if(n%12==10)
    {
        a=22;
        b=n-a;
    }
    else if(n%12==11)
    {
        a=11;
        b=n-a;
    }
    else
    {
        a=0;
        b=n;
    }
    cout<<a<<' '<<b<<'\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=1;
    cin>>T;
    while(T--)sol();
}
