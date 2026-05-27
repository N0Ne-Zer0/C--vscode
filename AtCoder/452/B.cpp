#include<iostream>
using namespace std;

const int Max=3e5+5;


int main()
{
    int h,w;
    cin>>h>>w;
    for(int i=0;i<w;i++)cout<<"#";
    cout<<"\n";
    for(int i=1;i<h-1;i++){
        cout<<"#";
        for(int j=1;j<w-1;j++){
            cout<<".";
        }
        cout<<"#\n";
    }
    if(h>1)for(int i=0;i<w;i++)cout<<"#";

}