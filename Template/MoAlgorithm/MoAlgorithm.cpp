// #include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
#define endl '\n'
#define int long long

const int maxn=1e5+5;
const int mod=1e9+7;

struct Q{
    int l,r,id;
};
vector<Q>q;
vector<int>ans(maxn);
int n,B;

bool cmp(const Q &x,const Q &y){
    int bx=x.l/B,by=y.l/B;
    if(bx!=by)return bx<by;
    return (bx&1)?(x.r>y.r):(x.r<y.r);
}
void add(int pos,int &cur){}
void del(int pos,int &cur){}
void Mo(){
    B=max(1ll,(int)sqrt(n));
    sort(q.begin(),q.end(),cmp);
    int curL=1,curR=0,cur=0;
    for(auto [l,r,id]:q){
        while(curL>l)add(--curL,cur);
        while(curR<r)add(++curR,cur);
        while(curL<l)del(curL++,cur);
        while(curR>r)del(curR--,cur);
        ans[id]=cur;
    }
}

void sol(){
    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T=1;
    // cin>>T;
    while(T--){
        sol();
    }
}