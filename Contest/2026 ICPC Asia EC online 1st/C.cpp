#include<bits/stdc++.h>
using namespace std;
#define int long long

void sol(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>g(n+1);
    vector<int>indeg(n+1,0),res(n+1,-1);
    for(int i=1;i<=m;i++){
        int l,r;
        cin>>l>>r;
        int lst,x;
        cin>>lst;
        for(int j=l+1;j<=r;j++){
            cin>>x;
            g[lst].push_back(x);
            indeg[x]++;
            lst=x;
        }
    }
    priority_queue<int>q;
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(indeg[i]==0){
            q.push(-i);
        }
    }
    while(!q.empty()){
        int u=-q.top();
        q.pop();
        res[u]=++cnt;
        for(auto v:g[u]){
            indeg[v]--;
            if(indeg[v]==0){
                q.push(-v);
            }
        }
    }
    if(cnt!=n){
        cout<<-1<<'\n';
        return;
    }
    for(int i=1;i<=n;i++)cout<<res[i]<<' ';
    cout<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T=1;
    cin>>T;
    while(T--)sol();
}