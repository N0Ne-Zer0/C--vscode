#include<iostream>
using namespace std;
using ll=long long;

const int Max=3e5+5;

void sol()
{
    int M=0x80000000,ans=0,a;
    for(int i=0;i<7;i++)
    {
        cin>>a;
        M=max(M,a);
        ans-=a;
    }
    cout<<ans+2*M<<'\n';
}


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        sol();
    }
}