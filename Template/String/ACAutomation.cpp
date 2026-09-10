#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=5e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=998244353;
const int INF=1e9;

struct ACAutomation{
    struct Node{
        int nxt[26];//小写字母，可用映射扩展
        int fail;
        vector<int>id;//已该节点结尾的所有模式串id
        Node(){
            memset(nxt,0,sizeof(nxt));
            fail=0;
        }
    };
    vector<Node>tr;
    vector<int>END;//模式串id的结尾节点
    vector<int>order;//bfs序
    vector<int>cnt;//节点访问次数
    vector<int>ans;//模式串出现次数
    ACAutomation(){tr.push_back({});}
    //插入模式串，返回分配的模式串id
    int insert(const string&s){
        int p=0;
        for(char ch:s){
            int c=ch-'a';
            if(!tr[p].nxt[c]){
                tr[p].nxt[c]=(int)tr.size();
                tr.push_back({});
            }
            p=tr[p].nxt[c];
        }
        int id=END.size();
        END.push_back(p);
        tr[p].id.push_back(id);
        return id;
    }
    //BFS构建失配指针
    void build(){
        queue<int>q;//不要忘记build！！不要重复build！！
        order.clear();
        for(int c=0;c<26;c++){//根节点的子节点入队
            if(tr[0].nxt[c]){
                q.push(tr[0].nxt[c]);
                order.push_back(tr[0].nxt[c]);
            }
        }
        while(!q.empty()){
            int u=q.front();q.pop();
            for(int c=0;c<26;c++){
                int v=tr[u].nxt[c];
                if(v){
                    tr[v].fail=tr[tr[u].fail].nxt[c];
                    q.push(v);
                    order.push_back(v);
                }
                else{
                    tr[u].nxt[c]=tr[tr[u].fail].nxt[c];
                }
            }
        }
    }
    //查询s中所有模式串分别出现的次数，记录在ans中
    void query(const string&s){
        cnt.assign(tr.size(),0);
        int p=0;
        for(char ch:s){
            int c=ch-'a';
            p=tr[p].nxt[c];
            cnt[p]++;
        }
        for(int i=(int)order.size()-1;i>=0;i--){
            int u=order[i];
            cnt[tr[u].fail]+=cnt[u];
        }
        ans.assign(END.size(),0);
        for(int id=0;id<(int)END.size();id++){
            ans[id]=cnt[END[id]];
        }
    }
};


signed main(){
    int n;
    cin>>n;
    ACAutomation AC;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        AC.insert(s);
    }
    string str;
    cin>>str;
    AC.build();
    AC.query(str);
    for(auto x:AC.ans)cout<<x<<'\n';
}