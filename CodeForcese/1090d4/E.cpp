#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
using ll=long long;

const int Max=4e3+5;
int a[Max];

void sol()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int ans=-1;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            ans=max(ans,a[i]^a[j]);
        }
    }
    cout<<ans<<'\n';
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