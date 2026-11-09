#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=5e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=998244353;
const int INF=1e9;

struct CircularIntervalCover
{
    struct Seg{int l=1,r=0,id=-1;};//区间信息
    int n,ID=-1;
    vector<Seg>seg;
    CircularIntervalCover(int n=0):n(n){}
    //覆盖区间[l,r]，若l>r，则表示覆盖区间[l,n-1]∪[0,r)
    void add_seg(int l,int r,int id){
        if(n<=0||l<0||l>=n||r<0||r>=n)return;
        int len=(l<=r?r-l+1:n-l+r+1);
        if(len>=n){ID=id;return;}
        seg.push_back({l,l+len-1,id});
    }
    //返回最小区间覆盖数和对应下标集合
    pair<int,vector<int>>solve()const{
        if(ID!=-1)return{1,{ID}};//单区间即可覆盖
        vector<Seg>v=seg;
        sort(v.begin(),v.end(),[](const Seg&a,const Seg&b){
            if(a.l!=b.l)return a.l<b.l;
            return a.r>b.r;
        });
        vector<Seg>A;
        int maxR=-1;
        for(auto &x:v){
            if(x.r<=maxR)continue;//去掉l更大的同时r更小的无效区间
            A.push_back(x);
            maxR=x.r;
        }
        int m=A.size();
        int sz=2*m;
        vector<Seg>B(sz);
        for(int i=0;i<m;i++){//复制到+n处
            B[i]=A[i];
            B[i+m]={A[i].l+n,A[i].r+n,A[i].id};
        }
        vector<int>nxt(sz);
        for(int i=0;i<sz;i++){
            int p=upper_bound(B.begin(),B.end(),B[i].r+1,[](int val,const Seg&s){
                return val<s.l;
            })-B.begin()-1;//从区间i开始连续延伸到区间p
            nxt[i]=(p>i?p:i);
        }
        const int INF=1e9;
        int best=INF;
        vector<int>ans;
        for(int i=0;i<m;i++){
            int temL=B[i].l+n-1;
            int p=i;
            vector<int>cur={B[i].id};
            while(B[p].r<temL){
                int q=nxt[p];
                if(q==p){cur.clear();break;}
                p=q;
                cur.push_back(B[p].id);
            }
            if(!cur.empty()&&(int)cur.size()<best){best=cur.size();ans=cur;}
        }
        if(best==INF)return{-1,{}};
        return {best,ans};
    }
};

struct CircularIntervalCover_double
{
    struct Seg{int l=1,r=0,id=-1;};//区间信息
    int n,ID=-1;
    vector<Seg>seg;
    CircularIntervalCover_double(int n=0):n(n){}
    //覆盖区间[l,r]，若l>r，则表示覆盖区间[l,n-1]∪[0,r)
    void add_seg(int l,int r,int id){
        if(n<=0||l<0||l>=n||r<0||r>=n)return;
        int len=(l<=r?r-l+1:n-l+r+1);
        if(len>=n){ID=id;return;}
        seg.push_back({l,l+len-1,id});

    }
    //返回最小区间覆盖数和对应下标集合
    pair<int,vector<int>>solve()const{
        if(ID!=-1)return{1,{ID}};//单区间即可覆盖
        vector<Seg>v=seg;
        sort(v.begin(),v.end(),[](const Seg&a,const Seg&b){
            if(a.l!=b.l)return a.l<b.l;
            return a.r>b.r;
        });
        vector<Seg>A;
        int maxR=-1;
        for(auto &x:v){
            if(x.r<=maxR)continue;//去掉l更大的同时r更小的无效区间
            A.push_back(x);
            maxR=x.r;
        }
        int m=A.size();
        int sz=2*m;
        vector<Seg>B(sz);
        for(int i=0;i<m;i++){//复制到+n处
            B[i]=A[i];
            B[i+m]={A[i].l+n,A[i].r+n,A[i].id};
        }
        vector<int>nxt(sz);
        for(int i=0;i<sz;i++){
            int p=upper_bound(B.begin(),B.end(),B[i].r+1,[](int val,const Seg&s){
                return val<s.l;
            })-B.begin()-1;
            nxt[i]=(p>i?p:i);
        }
        int LOG=1;
        while((1LL<<LOG)<=sz)LOG++;
        vector<vector<int>>up(LOG,vector<int>(sz));
        for(int i=0;i<sz;i++)up[0][i]=nxt[i];
        for(int k=1;k<LOG;k++){
            for(int i=0;i<sz;i++){
                up[k][i]=up[k-1][up[k-1][i]];
            }
        }
        const int INF=1e9;
        int best=INF,first=-1;
        for(int i=0;i<m;i++){
            int L=B[i].l+n-1;
            if(B[i].r>=L){best=1;first=i;break;}
            if(up[0][i]==i)continue;
            int p=i,add=0;
            for(int k=LOG-1;k>=0;k--){
                int q=up[k][p];
                if(B[q].r<L){p=q;add+=(1LL<<k);}
            }
            int q=up[0][p];
            if(q==p||B[q].r<L)continue;
            add++;
            if(1+add<best){best=1+add,first=i;}
        }
        if(first==-1)return{-1,{}};
        vector<int>ans;
        int p=first,L=B[p].l+n-1;
        ans.push_back(B[p].id);
        while(B[p].r<L){
            int q=up[0][p];
            if(q==p)return{-1,{}};
            p=q;
            ans.push_back(B[p].id);
        }
        return{ans.size(),ans};
    }
};


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
}