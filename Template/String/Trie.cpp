#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=5e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=998244353;
const int INF=1e9;

struct Trie{
    struct Node{
        int nxt[26];//小写字母，可用映射来表示大小写+数字
        int cnt;//节点经过次数
        int end;//以该节点结尾的字符串数
        Node(){
            memset(nxt,0,sizeof(nxt));
            cnt=end=0;
        }
    };
    vector<Node>tr;
    Trie(){tr.push_back({});}
    void insert(const string&s){
        int p=0;
        for(char ch:s){
            int c=ch-'a';
            if(!tr[p].nxt[c]){
                tr[p].nxt[c]=(int)tr.size();
                tr.push_back({});
            }
            p=tr[p].nxt[c];
            tr[p].cnt++;
        }
        tr[p].end++;
    }
    //返回字符串s出现次数
    int count(const string&s)const{
        int p=0;
        for(char ch:s){
            int c=ch-'a';
            if(!tr[p].nxt[c])return 0;
            p=tr[p].nxt[c];
        }
        return tr[p].end;
    }
    //查询前缀s的字符串数量
    int countPrefix(const string&s)const{
        int p=0;
        for(auto ch:s){
            int c=ch-'a';
            if(!tr[p].nxt[c])return 0;
            p=tr[p].nxt[c];
        }
        return tr[p].cnt;
    }
    //删除一个s
    void erase(const string&s){
        if(!count(s))return;//保证s存在
        int p=0;
        for(auto ch:s){
            int c=ch-'a';
            p=tr[p].nxt[c];
            tr[p].cnt--;
        }
        tr[p].end--;
    }
};


signed main(){
    
}