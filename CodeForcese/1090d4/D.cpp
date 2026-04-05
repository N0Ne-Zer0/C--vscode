#include<iostream>
#include<vector>
using namespace std;
using ll=long long;

const int Max=5e6+5;

bool notprime[Max];
int prime[Max],cnt;

void Prime()
{
    for(int i=2;i<=2e3;i++)
    {
        if(notprime[i])continue;
        for(int j=i;i*j<=4e6;j++)
        {
            notprime[i*j]=1;
        }
    }
    for(int i=2;i<=4e6;i++)
    {
        if(!notprime[i])prime[cnt++]=i;
    }
}

void sol()
{
    int n;
    cin>>n;
    for(int i=1;i<n+1;i++)
    {
        cout<<prime[i]*prime[i-1]<<' ';
    }
    cout<<'\n';
}


int main()
{
    Prime();
    int T;
    cin>>T;
    while(T--)
    {
        sol();
    }
}