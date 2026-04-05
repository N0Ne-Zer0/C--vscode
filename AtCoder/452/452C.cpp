#include<iostream>
using namespace std;

const int Max=2e5+5;
int N,M;
int A[20],B[20];
string S[Max];
bool fg[50][50][260];

int main()
{
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>A[i]>>B[i];
    }
    cin>>M;
    for(int i=0;i<M;i++)
    {
        cin>>S[i];
        for(int j=0;j<S[i].size();j++)
        {
            fg[S[i].size()][j+1][S[i][j]]=1;
        }
    }
    for(int i=0;i<M;i++)
    {
        if(S[i].size()!=N)
        {
            cout<<"No\n";
            continue;
        }
        bool flg=1;
        for(int j=0;j<N;j++)
        {
            
            if(!fg[A[j]][B[j]][S[i][j]])
            {
                flg=0;
                break;
            }
        }
        if(flg)cout<<"Yes\n";
        else cout<<"No\n";
    }

}