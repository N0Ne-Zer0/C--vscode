#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=5e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=998244353;
const int INF=1e9;

struct BinaryTrie{
    struct Node{
        int ch[2];
        int cnt;//经过次数
        Node(){ch[0]=ch[1]=0;cnt=0;}
    };
    vector<Node>tr;
    int B;//二进制最高位
    BinaryTrie(int maxBit=31){tr.push_back({});B=maxBit;}
    void insert(int x){
        int p=0;
        for(int i=B;i>=0;i--){
            int b=(x>>i)&1;
            if(!tr[p].ch[b]){
                tr[p].ch[b]=(int)tr.size();
                tr.push_back({});
            }
            p=tr[p].ch[b];
            tr[p].cnt++;
        }
    }
    //返回与x异或结果最大值
    int maxXor(int x)const{
        int p=0,res=0;
        for(int i=B;i>=0;i--){
            int b=(x>>i)&1;
            int want=b^1;
            if(tr[p].ch[want]){
                res|=(1LL<<i);
                p=tr[p].ch[want];
            }
            else{
                p=tr[p].ch[b];
            }
        }
        return res;
    }
    //返回与x异或结果最小值
    int minXor(int x)const{
        int p=0,res=0;
        for(int i=B;i>=0;i--){
            int b=(x>>i)&1;
            if(tr[p].ch[b]){
                p=tr[p].ch[b];
            }
            else{
                res|=(1LL<<i);
                p=tr[p].ch[b^1];
            }
        }
        return res;
    }
};


signed main(){
    
}