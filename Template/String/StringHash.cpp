#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=5e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=998244353;
const int INF=1e9;

struct StringHash{//字符串哈希+滑动窗口可替代KMP
    using u64=unsigned long long;//自然溢出等价取模2^64
    const u64 base=131;//基  或用13331
    vector<u64>h,pw;
    StringHash(const string&s):h(s.size()+1),pw(s.size()+1){
        pw[0]=1;
        for(int i=1;i<=(int)s.size();i++){
            pw[i]=pw[i-1]*base;//可以优化为全局pw
            h[i]=h[i-1]*base+(u64)s[i-1];
        }
    }
    inline u64 getHash(int l,int r)const{return h[r]-h[l-1]*pw[r-l+1];}
    static bool equal(const StringHash&A,int l1,int r1,
                      const StringHash&B,int l2,int r2){
        if(r1-l1!=r2-l2)return 0;
        return A.getHash(l1,r1)==B.getHash(l2,r2);
    }
};

signed main(){
    
}