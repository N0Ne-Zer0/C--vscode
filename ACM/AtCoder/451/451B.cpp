#include<iostream>
using namespace std;

const int Max=1e2+5;

int N,M,A,B;
int sum[Max][2];


int main()
{
    cin>>N>>M;
    for(int i=0;i<N;i++)
    {
        cin>>A>>B;
        sum[A][0]++;
        sum[B][1]++;
    }
    for(int i=1;i<=M;i++){
        cout<<sum[i][1]-sum[i][0]<<'\n';
    }
}