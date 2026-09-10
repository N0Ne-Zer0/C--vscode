#include<bits/stdc++.h>
using namespace std;
#define int long long

void sol(){
    int n;
    cin>>n;
    vector<pair<char,int>>a(n+1,{'0',0});
    map<int,int>mp;
    vector<int>nxt(n+1,0);
    vector<int>stk;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
    }
    for(int i=n;i>=1;i--){
        nxt[i]=mp[a[i].second];
        mp[a[i].second]=i;
    }
    mp.clear();
    for(int i=1;i<=n;i++){
        auto[op,x]=a[i];
        char nxtop=a[nxt[i]].first;
        if(op=='+'){
            stk.push_back(x);
            cout<<'+';
            mp[x]=1;
            if(nxtop=='F'||nxtop=='+'||nxtop=='0'){
                stk.pop_back();
                cout<<'-';
                mp[x]=0;
            }
        }
        else if(op=='F'){
            cout<<'?';
        }
        else if(op=='T'){
            cout<<'?';
            if(nxtop=='F'||nxtop=='+'||nxtop=='0'){
                mp[x]=-1;
            }
        }
        while(!stk.empty()&&mp[stk.back()]==-1){
            stk.pop_back();
            cout<<'-';
        }
    }
    while(!stk.empty()){
        stk.pop_back();
        cout<<'-';
    }
    cout<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T=1;
    cin>>T;
    while(T--)sol();
}