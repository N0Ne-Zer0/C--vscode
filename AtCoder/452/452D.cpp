#include<iostream>
using namespace std;
#define int long long

const int maxn=2e5+5;

int g[maxn][260];

signed main()
{
    string S,T;
    int ans=0;
    cin>>S>>T;
    for(int j='a';j<='z';j++)
    {
        int tem=S.size();
        for(int i=S.size()-1;i>=0;i--)
        {
            if(S[i]==j)
            {
                tem=i;
            }
            g[i][j]=tem;
        }
    }
    for(int i=0;i<S.size();i++)
    {
        int x=i;
        int j;
        for(j=0;j<T.size()&&x<S.size();j++)
        {
            x=g[x][T[j]];
            if(x==S.size())break;
            x++;
        }
        if(j==T.size())ans+=S.size()-x+1;
    }
    ans=S.size()*(S.size()+1)/2-ans;
    cout<<ans;
}