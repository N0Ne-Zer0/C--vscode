#include<bits/stdc++.h>
using namespace std;
#define int long long

struct Trie{
    struct Node{
        int nxt[26]={0};
        int cnt=0,dep=0;
        Node(){}
        Node(int parentDep){dep=parentDep+1;}
    };
    vector<Node>tr;
    int ans=0;
    vector<int>g;
    Trie(){tr.push_back({});g.push_back(0);}
    void insert(const string&s){
        ans+=g.size();
        g.push_back(0);
        int p=0;
        for(char ch:s){
            int c=ch-'a';
            if(!tr[p].nxt[c]){
                tr[p].nxt[c]=tr.size();
                tr.push_back(Node(tr[p].dep));
            }
            p=tr[p].nxt[c];
            tr[p].cnt++;
            if(g[tr[p].cnt]<tr[p].dep){
                ans-=g[tr[p].cnt]^tr[p].cnt;
                g[tr[p].cnt]=tr[p].dep;
                ans+=g[tr[p].cnt]^tr[p].cnt;
            }
        }
    }
};

void sol(){
    int n;
    cin>>n;
    Trie trie;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        trie.insert(s);
        cout<<trie.ans<<'\n';
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T=1;
    // cin>>T;
    while(T--)sol();
}