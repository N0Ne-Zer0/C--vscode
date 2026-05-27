#include<iostream>
#include<queue>
#include<cmath>
using namespace std;
#define int long long

const int maxn=2e5+5;
const int mod=1e9+7;

priority_queue<int>que1,que2;

void sol()
{
    int X;
    cin>>X;
    que1.push(X);
    que2.push(-X);
    int Q;
    cin>>Q;
    while(Q--)
    {
        int A,B;
        cin>>A>>B;
        int tem=que1.top();
        que1.pop();
        que2.pop();
        if(A<=tem)que1.push(A);
        else que2.push(-A);
        if(B<=tem)que1.push(B);
        else que2.push(-B);

        if(que1.size()>que2.size())
        {
            int t=que1.top();
            que2.push(-tem);
            que2.push(-t);
            tem=t;
        }
        else if(que1.size()<que2.size())
        {
            int t=-que2.top();
            que1.push(tem);
            que1.push(t);
            tem=t;
        }
        else
        {
            que1.push(tem);
            que2.push(-tem);
        }
        cout<<tem<<'\n';
    }
}

signed main()
{
    int T=1;
    // cin>>T;
    while(T--)
    {
        sol();
    }
}