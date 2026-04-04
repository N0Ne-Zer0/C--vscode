#include<iostream>
#include<queue>
using namespace std;

const int Max=3e5+5;
priority_queue<int,vector<int>, greater<int>>prique;
int Q,x,h;

void Q1()
{
    prique.push(h);
}
void Q2()
{
    while(prique.size()&&prique.top()<=h)
    {
        prique.pop();
    }
}

int main()
{
    cin>>Q;
    while(Q--){
        cin>>x>>h;
        if(x==1)Q1();
        else Q2();
        cout<<prique.size()<<'\n';
    }
}