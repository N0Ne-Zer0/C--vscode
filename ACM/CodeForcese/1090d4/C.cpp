#include<iostream>
using namespace std;
using ll=long long;

const int Max=3e5+5;

void sol()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cout<<i<<' ';
        cout<<n+2*i<<' '<<n+2*i-1<<' ';
    }
    cout<<'\n';
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