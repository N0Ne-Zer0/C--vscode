#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=3e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=998244353;
const int INF=1e9;

vector<int> getNXT(const string& p){//返回nxt数组
    int m=p.size();
    vector<int>nxt(m);
    for(int i=1;i<m;i++){
        int j=nxt[i-1];
        while(j>0&&p[i]!=p[j])j=nxt[j-1];
        if(p[i]==p[j])j++;
        nxt[i]=j;
    }
    return nxt;
}
vector<int> KMP(const string&s,const string&p){//返回完全匹配的字符串起始位置数组
    vector<int>nxt=getNXT(p);
    vector<int>res;
    int j=0;
    for(int i=0;i<(int)s.size();i++){
        while(j>0&&s[i]!=p[j])j=nxt[j-1];
        if(s[i]==p[j])j++;
        if(j==(int)p.size()){
            res.push_back(i-(int)p.size()+1);
            j=nxt[j-1];   // 关键：匹配完继续找下一处
        }
    }
    return res;
}

void sol(){
    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    T = 1;
    cin>>T;
    while (T--)sol();
}