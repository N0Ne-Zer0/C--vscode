#include<iostream>
using namespace std;

const int Max=5e5+5;
int A[Max],B[Max];
int preb[Max];


int main()
{
    int N,M;
    cin>>N,M;
    for(int i=1;i<=N;i++)cin>>A[i];
    for(int i=1;i<=M;i++)
    {
        cin>>B[i];
        preb[i]=preb[i-1]+B[i];
    }
    for(int i=1;i<=N;i++)
    {
        
    }
}