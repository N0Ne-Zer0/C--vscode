## 快读快写
```cpp
namespace FastIO{
    static char ibuf[1<<20],*ip1=ibuf,*ip2=ibuf;
    inline char gc(){
        if(ip1==ip2){
            ip2=(ip1=ibuf)+fread(ibuf,1,sizeof(ibuf),stdin);
            if(ip1==ip2)return EOF;
        }
        return *ip1++;
    }
    static char obuf[1<<20],*op=obuf;
    inline void flush(){fwrite(obuf,1,op-obuf,stdout);op=obuf;}
    inline void pc(char c){
        if(op==obuf+sizeof(obuf))flush();
        *op++=c;
    }
    template<typename T>
    inline bool read(T &x){
        x=0;
        char c=gc();
        bool neg=false;
        while(!isdigit(c)){
            if(c=='-')neg=true;
            else if(c==EOF)return false;
            c=gc();
        }
        x=0;
        while(isdigit(c)){
            x=(x<<3)+(x<<1)+c-48;
            c=gc();
        }
        if(neg)x=-x;
        return true;
    }
    template<typename T>
    inline void write(T x){
        if(x<0){pc('-');x=-x;}
        if(x>9)write(x/10);
        pc(x%10+48);
    }
    inline void write(const string &s){for(char c:s)pc(c);}
    inline void write(const char *s){while(*s)pc(*s++);}

    template<typename T>
    inline void writeln(T x){write(x);pc('\n');}//换行输出
    inline void writeln(const string &s){write(s);pc('\n');}//字符串数字换行输出
    inline void flushOut(){flush();}//刷新缓冲区
}
using FastIO::read;
using FastIO::write;
using FastIO::writeln;
using FastIO::flushOut;
```

## 快读快写（简易版）
```cpp
inline bool read(int &x){
    x=0;
    bool neg=0;
    int c=getchar();
    while(!isdigit(c)){
        if(c=='-')neg=true;
        else if(c==EOF)return false;
        c=getchar();
    }
    while(isdigit(c)){
        x=(x<<3)+(x<<1)+c-48;
        c=getchar();
    }
    if(neg)x=-x;
    return true;
}

inline void write(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
}
```

## 对拍数据生成
```cpp
// 使用当前时间作为随机数种子
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());

// 生成 [l, r] 范围内的随机整数
int random(int l,int r){
    return uniform_int_distribution<int>(l,r)(rnd);
}
```

## 对拍
```cmd
@echo off
set /a cnt=0

:loop
set /a cnt+=1
echo ===============================
echo Running Test %cnt% ...

data.exe > in.txt
std.exe < in.txt > std.out
test.exe < in.txt > test.out
fc std.out test.out > nul

if errorlevel 1 goto error

echo Accepted!
echo ===============================
goto loop

:error
echo ===============================
echo Wrong Answer on Test %cnt%!
echo 发现错误数据！请打开该目录下的 in.txt 查看输入。
pause
```

## 对拍SPJ（判断器源码）
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // 1. 打开对应的文件
    ifstream fin("in.txt");       // 读取输入数据
    ifstream ftest("test.out");   // 读取你的待测程序的输出
    
    // ifstream fstd("std.out");  
    // 💡 提示：如果 SPJ 校验时需要参考标准程序的答案（例如最短路的长度），
    // 可以再打开 std.out 读取标准答案。如果不需要参考，则不用打开。

    if (!fin || !ftest) {
        cout << "Error: Cannot open files!" << endl;
        return 1; // 文件打不开也视为错误
    }
    int n;
    fin >> n;
    int ans;
    ftest >> ans;
    //SPJ 校验逻辑（这里以“输出的数必须严格大于输入的数”为例）
    bool is_correct = false;
    if (ans > n) {
        is_correct = true; 
    }

    //返回校验结果给 .bat 脚本
    if (is_correct) {
        return 0; // 返回 0 代表正确 (Accepted)
    } else {
        return 1; // 返回非 0 代表错误 (Wrong Answer)
    }
}
```

## 对拍SPJ（批处理脚本）
```cmd
@echo off
set /a cnt=0

:loop
set /a cnt+=1
echo ===============================
echo Running Test %cnt% ...

data.exe > in.txt
test.exe < in.txt > test.out
spj.exe

if errorlevel 1 goto error

echo Accepted!
echo ===============================
goto loop

:error
echo ===============================
echo Wrong Answer on Test %cnt%!
echo 发现错误数据！请检查 in.txt 和 test.out。
pause
```

## 并查集
```cpp
struct DSU{
    vector<int> fa, sz;
    int cnt;
    DSU(int n):fa(n+1),sz(n+1,1),cnt(n){
        iota(fa.begin(),fa.end(),0);//numeric头文件
    }
    int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}//路径压缩查找
    bool merge(int a,int b){
        a=find(a);
        b=find(b);
        if(a==b)return false;
        if(sz[a]<sz[b])swap(a,b);//按大小合并
        fa[b]=a;
        sz[a]+=sz[b];
        cnt--;
        return true;
    }
    bool same(int a,int b){return find(a)==find(b);}
    int size(int x){return sz[find(x)];}//返回组大小
    int groups()const{return cnt;}//返回组数
};
```

## 树状数组
```cpp
typedef int T;
struct FenwickTree{
    int n,bit;
    vector<T>BIT;
    FenwickTree(int _n):BIT(_n+1),n(_n){
        bit=1;
        while((bit<<1)<=n)bit<<=1;
    }

    inline int lb(int x){return -x&x;}

    inline void add(int x,const T &v){
        for(int i=x;i<=n;i+=lb(i)){
            BIT[i]=BIT[i]+v;
        }
    }

    inline T sum(int x){
        T res=0;
        for(int i=x;i>0;i-=lb(i)){
            res=res+BIT[i];
        }
        return res;
    }

    inline T rangeSum(int l,int r){
        if(l>r)return 0;
        return sum(r)-sum(l-1);
    }

    inline T select(const T& k){//返回最小的x，使得sum(x)>=k，或返回n+1
        int idx=0;
        T cur{};
        for(int i=bit;i;i>>=1){
            int nxt=idx+i;
            if(nxt>n||cur+BIT[nxt]>=k)continue;
            idx=nxt;
            cur+=BIT[idx];
        }
        return idx+1;
    }
};

struct BITRange{
    int n;
    vector<T>BIT1,BIT2;

    BITRange(int _n):BIT1(_n+1),BIT2(_n+1),n(_n){}

    inline int lb(int x){return -x&x;}

    inline void add(vector<T>&BIT,int x,const T &v){//单点加
        for(int i=x;i<=n;i+=lb(i)){
            BIT[i]=BIT[i]+v;
        }
    }

    inline void rangeAdd(int l,int r,T val){//区间加
        if (l>r)return;
        add(BIT1,l,val);
        add(BIT1,r+1,-val);
        add(BIT2,l,val*(l-1));
        add(BIT2,r+1,-val*r);
    }

    inline T preSum(int x){//前缀和
        T res=0;
        if(x<=0)return 0;
        T s1=0,s2=0;
        for(T i=x;i>0;i-=lb(i)){
            s1+=BIT1[i];
            s2+=BIT2[i];
        }
        res=s1*x-s2;
        return res;
    }

    inline T rangeSum(T l,T r){//区间和 [l, r]
        if(l>r)return 0;
        return preSum(r)-preSum(l - 1);
    }
};
```

## 线段树
```cpp
struct SegTree{
    #define mid ((l+r)>>1)
    #define ls (p<<1)
    #define rs (p<<1|1)
    int n;
    struct Info{int sum,mx,mn;};//信息
    struct Tag{int add=0,mul=1;};//标记
    vector<Info>tr;
    vector<Tag>lazy;

    SegTree(int n,const vector<int>&a):n(n),tr(n*4+5),lazy(n*4+5){
        build(1,1,n,a);
    }

    inline Info merge(const Info& x,const Info& y){//合并信息
        auto&[s1,m1,n1]=x;
        auto&[s2,m2,n2]=y;
        return {s1+s2,max(m1,m2),min(n1,n2)};
    }

    inline void apply(int p,int l,int r,const Tag& t){//应用懒标记于p
        auto[add,mul]=t;
        auto&[s,m,n]=tr[p];
        s=s*mul+add*(r-l+1);
        m=m*mul+add;
        n=n*mul+add;
        lazy[p].add=lazy[p].add*mul+add;
        lazy[p].mul*=mul;
    }

    inline void push(int p,int l,int r){//向下传递懒标记
        if(lazy[p].add==0&&lazy[p].mul==1)return;
        apply(ls,l,mid,lazy[p]);
        apply(rs,mid+1,r,lazy[p]);
        lazy[p]=Tag();
    }

    inline void pull(int p){tr[p]=merge(tr[ls],tr[rs]);}//从子节点更新自身节点

    void build(int p,int l,int r,const vector<int>& a){
        if(l==r){
            tr[p]={a[l],a[l],a[l]};
            return;
        }
        build(ls,l,mid,a);
        build(rs,mid+1,r,a);
        pull(p);
    }

    void update(int p,int l,int r,int ql,int qr,const Tag&t){//区间[ql,qr]+tag(*mul)
        if(ql<=l&&r<=qr){
            apply(p,l,r,t);
            return;
        }
        push(p,l,r);
        if(ql<=mid)update(ls,l,mid,ql,qr,t);
        if(qr>mid)update(rs,mid+1,r,ql,qr,t);
        pull(p);
    }

    Info query(int p,int l,int r,int ql,int qr){//查询[ql,qr]
        if(ql<=l&&r<=qr)return tr[p];
        push(p,l,r);
        if(qr<=mid)return query(ls,l,mid,ql,qr);
        if(ql>mid)return query(rs,mid+1,r,ql,qr);
        Info left=query(ls,l,mid,ql,qr);
        Info right=query(rs,mid+1,r,ql,qr);
        return merge(left,right);
    }

    void rangeAdd(int l,int r,int v){update(1,1,n,l,r,{v,1});}
    void rangeMul(int l,int r,int v){update(1,1,n,l,r,{0,v});}

    int querySum(int l,int r){return query(1,1,n,l,r).sum;}
    int queryMax(int l,int r){return query(1,1,n,l,r).mx;}
    int queryMin(int l,int r){return query(1,1,n,l,r).mn;}
};
```

## 主席树
```cpp
struct PresidentTree{
    int tot=0;
    vector<int>ls,rs,cnt;

    PresidentTree(int n):ls(n*25),rs(n*25),cnt(n*25){}

    int update(int old,int l,int r,int pos,int delta){//从old节点处添加新节点p并返回
        int p=++tot;
        ls[p]=ls[old];
        rs[p]=rs[old];
        cnt[p]=cnt[old]+delta;
        if(l!=r){
            int mid=(l+r)>>1;
            if(pos<=mid)ls[p]=update(ls[old],l,mid,pos,delta);
            else rs[p]=update(rs[old],mid+1,r,pos,delta);
        }
        return p;
    }

    int queryCnt(int v1,int v2,int l,int r,int ql,int qr){//查询v2-v1版本中[ql,qr]总数量
        if(ql>r||qr<l)return 0;
        if(ql<=l&&r<=qr)return cnt[v2]-cnt[v1];
        int mid=(l+r)>>1;
        int left=queryCnt(ls[v1],ls[v2],l,mid,ql,qr);
        int right=queryCnt(rs[v1],rs[v2],mid+1,r,ql,qr);
        return left+right;
    }

    int kth(int v1,int v2,int l,int r,int k){//查询v2-v1版本中第k大
        if(l==r)return l;
        int mid=(l+r)>>1;
        int left=cnt[ls[v2]]-cnt[ls[v1]];
        if(k<=left)return kth(ls[v1],ls[v2],l,mid,k);
        return kth(rs[v1],rs[v2],mid+1,r,k-left);
    }
};
```

## ST表RMQ
```cpp
typedef int T;
struct RMQ{
    vector<int>lg;
    vector<vector<T>>ST;
    int N;

    RMQ(int n,vector<T>&a):N(n){
        lg.assign(n+1,0);
        ST.assign(21,vector<T>(n+1));
        for(int i=1;i<=n;i++)ST[0][i]=a[i];
        for(int i=2;i<=N;i++)lg[i]=lg[i/2]+1;
        build();
    }

    inline T merge(T a,T b){
        return max(a,b);
    }

    void build(){
        for(int i=1;i<20;i++){
            int len=1<<i;
            for(int j=1;j+len-1<=N;j++){
                ST[i][j]=merge(ST[i-1][j],ST[i-1][j+(1<<(i-1))]);
            }
        }
    }

    inline T search(int l,int r){
        int len=r-l+1;
        int t=lg[len];
        return merge(ST[t][l],ST[t][r-(1<<t)+1]);
    }
};
```

## 莫队
```cpp
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
```

## KMP
```cpp
vector<int> prefixFunction(const string& p){//返回nxt数组
    int m=p.size();
    vector<int>pi(m);
    for(int i=1;i<m;i++){
        int j=pi[i-1];
        while(j>0&&p[i]!=p[j])j=pi[j-1];
        if(p[i]==p[j])j++;
        pi[i]=j;
    }
    return pi;
}
vector<int> kmpAll(const string&s,const string&p){//返回完全匹配的字符串起始位置数组
    vector<int>pi=prefixFunction(p);
    vector<int>res;
    int j=0;
    for(int i=0;i<(int)s.size();i++){
        while(j>0&&s[i]!=p[j])j=pi[j-1];
        if(s[i]==p[j])j++;
        if(j==(int)p.size()){
            res.push_back(i-(int)p.size()+1);
            j=pi[j-1];   // 关键：匹配完继续找下一处
        }
    }
    return res;
}
```

## 线性筛
```cpp
struct LinearSieve{
    vector<int>primes,minp,phi,mu;//质数表，最小质因子，欧拉函数，莫比乌斯函数
    vector<bool>comp;

    LinearSieve(int n):minp(n+1),phi(n+1),mu(n+1),comp(n+1,0){
        phi[1]=1;
        mu[1]=1;

        for(int i=2;i<=n;i++){
            if(!comp[i]){
                primes.push_back(i);
                minp[i]=i;
                phi[i]=i-1;
                mu[i]=-1;
            }
            for(int p:primes){
                if(1LL*i*p>n)break;
                comp[i*p]=true;
                minp[i*p]=p;
                if(i%p==0){
                    phi[i*p]=phi[i]*p;
                    mu[i*p]=0;
                    break;
                }
                else{
                    phi[i*p]=phi[i]*(p-1);
                    mu[i*p]=-mu[i];
                }
            }
        }
    }
    //判断质数
    bool isPrime(int x)const{return x>=2&&!comp[x];}

    vector<pair<int,int>>factorize(int x)const{
        vector<pair<int,int>>res;
        while(x>1){
            int p=minp[x],c=0;
            while (x%p==0){
                x/=p;
                c++;
            }
            res.push_back({p,c});
        }
        return res;//质因数成对分解后的数组
    }
};
```

## 数学基础（快速幂/组合数/逆元）
```cpp
inline int qp(int x,int y){//快速幂
    if(y==0||x==1)return 1;
    if(x==0)return 0;
    int res=1;
    while(y){
        if(y&1)res=res*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return res;
}

vector<int>fac(maxn,0),invfac(maxn,0);

inline void init(){
    fac[0]=1;
    invfac[0]=1;
    for(int i=1;i<maxn;i++)fac[i]=fac[i-1]*i%mod;
    invfac[maxn-1]=qp(fac[maxn-1],mod-2);
    for(int i=maxn-2;i;i--)invfac[i]=invfac[i+1]*(i+1)%mod;
}

inline int C(int x,int y){//x里面选y个
    if(y<0||y>x)return 0;
    return fac[x]*invfac[x-y]%mod*invfac[y]%mod;
}

inline int inv(int x){//x的逆元
    return qp(x,mod-2);
}
```

## 线性基
```cpp
const int MAXL=100;
struct LinearBasis{
    vector<int>val;
    bitset<MAXL>b[MAXL];
 
    LinearBasis(){
        val.assign(MAXL,0);
        for(auto x:b)x.reset();
    }
 
    void insert(bitset<MAXL>x,int v){//插入基
        for(int i=MAXL-1;i>=0;i--){
            if(!x[i])continue;
            if(b[i].none()){
                b[i]=x;
                val[i]=v;
                return;
            }
            x^=b[i];
            v^=val[i];
        }
    }
 
    int query(bitset<MAXL>x){//查询是否可以由基异或表示
        int res=0;
        for(int i=MAXL-1;i>=0;i--){
            if(!x[i])continue;
            if(b[i].none())return -1;
            x^=b[i];
            res^=val[i];
        }
        return res;
    }
};
```

## 最近公共祖先（倍增）
```cpp
vector<vector<int>>edge(maxn),f(maxn,vector<int>(21));
vector<int>h(maxn);

void dfs(int x,int fa){
    f[x][0]=fa;
    h[x]=h[fa]+1;
    for(int i=1;i<21;i++){
        f[x][i]=f[f[x][i-1]][i-1];
    }
    for(auto v:edge[x]){
        if(v==fa)continue;
        dfs(v,x);
    }
}

int LCA(int a,int b){
    if(h[a]>h[b])swap(a,b);
    int gap=h[b]-h[a];
    int w=0;
    while(gap){
        if(gap&1)b=f[b][w];
        gap>>=1;
        w++;
    }
    if(a==b)return a;
    for(int i=20;i>=0;i--){
        if(f[a][i]==f[b][i])continue;
        a=f[a][i];
        b=f[b][i];
    }
    return f[a][0];
}
```

## 最近公共祖先（DFN序+ST）
```cpp
vector<vector<int>>edge(maxn),ST(maxn,vector<int>(21));
vector<int>dfn,h(maxn),ft(maxn),lg(maxn),f(maxn);

void dfs(int x,int fa){
    h[x]=h[fa]+1;
    f[x]=fa;
    ft[x]=dfn.size();
    dfn.push_back(x);
    for(auto v:edge[x]){
        if(v==fa)continue;
        dfs(v,x);
    }
}

int MIN(int a,int b){
    if(h[f[a]]<h[f[b]])return a;
    else return b;
}

void build_ST(){
    for(int i=0;i<dfn.size();i++)ST[i][0]=dfn[i];
    lg[1]=0;
    for(int i=2;i<=dfn.size();i++)lg[i]=lg[i/2]+1;
    for(int i=1;i<21;i++){
        int len=1<<i;
        for(int j=0;j+len<=dfn.size();j++){
            ST[j][i]=MIN(ST[j][i-1],ST[j+(1<<(i-1))][i-1]);
        }
    }
}

int LCA(int a,int b){
    if(a==b)return a;
    int l=ft[a],r=ft[b];
    if(l>r)swap(l,r);
    l++;
    int k=lg[r-l+1];
    int res=MIN(ST[l][k],ST[r-(1<<k)+1][k]);
    return f[res];
}
```

## 最短路Dijkstra（堆优化）
```cpp
struct Edge
{
    int v,w;
};
int n,m,s;
vector<int>dist;
vector<vector<Edge>>edge;

void Dijkstra(){
    priority_queue<pair<int,int>>q;
    dist.assign(n+1,INF);
    q.push({0,s});
    dist[s]=0;
    while(!q.empty()){
        auto [d,u]=q.top();
        q.pop();
        d=-d;
        if(d>dist[u])continue;
        for(auto [v,w]:edge[u]){
            if(d+w<dist[v]){
                dist[v]=d+w;
                q.push({-dist[v],v});
            }
        }
    }
}
```

## 最短路Dijkstra（朴素）
```cpp
struct Edge{
    int v,w;
};
int n,m,s;
vector<int>dist;
vector<vector<Edge>>edge;

void Dijkstra(){
    dist.assign(n+1,INF);
    dist[s]=0;
    vector<bool>vis(n+1,0);
    for(int i=1;i<=n;i++){
        int u=-1,d=INF;
        for(int j=1;j<=n;j++){
            if(vis[j]||dist[j]>=d)continue;
            u=j;
            d=dist[j];
        }
        if(u==-1)break;
        vis[u]=1;
        for(auto [v,w]:edge[u]){
            dist[v]=min(dist[v],dist[u]+w);
        }
    }
}
```

## 最短路SPFA
```cpp
struct Edge{
    int v,w;
};
int n,m,s;
vector<int>dist;
vector<vector<Edge>>edge;

bool SPFA(){
    dist.assign(n+1,INF);
    dist[s]=0;
    queue<int>q;
    vector<int>vis(n+1,0),cnt(n+1,0);
    q.push(s);
    vis[s]=1;
    while (!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=0;
        if(dist[u]==INF)continue;
        for(auto [v,w]:edge[u]){
            if(dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                cnt[v]++;
                if(cnt[v]>=n)return false;
                if(!vis[v]){
                    q.push(v);
                    vis[v]=1;
                }
            }
        }
    }
    return true;
}
```

## 最短路Floyd
```cpp
int n,m;
vector<vector<int>>dist;

void Floyd(){
    for(int k=1;k<=n;k++){
        for(int u=1;u<=n;u++){
            for(int v=1;v<=n;v++){
                if(u==v)dist[u][v]=0;
                if(dist[u][v]>dist[u][k]+dist[k][v]){
                    dist[u][v]=dist[u][k]+dist[k][v];
                    dist[v][u]=dist[v][k]+dist[k][u];
                }
            }
        }
    }
}
```

## 全源最短路Johnson
```cpp
struct Edge{
    int v,w;
};
int n,m;
vector<int>h;
vector<vector<Edge>>edge;
vector<vector<int>>dist;

bool SPFA(int s){
    h.assign(n+1,INF);
    h[s]=0;
    queue<int>q;
    vector<int>vis(n+1,0),cnt(n+1,0);
    q.push(s);
    vis[s]=1;
    while (!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(auto [v,w]:edge[u]){
            if(h[u]+w<h[v]){
                h[v]=h[u]+w;
                if(!vis[v]){
                    q.push(v);
                    vis[v]=1;
                    cnt[v]++;
                    if(cnt[v]>=n)return true;
                }
            }
        }
    }
    return false;
}

void Dijkstra(int s){
    priority_queue<pair<int,int>>q;
    q.push({0,s});
    dist[s][s]=0;
    while(!q.empty()){
        auto[d,u]=q.top();
        q.pop();
        d=-d;
        if(d>dist[s][u])continue;
        for(auto [v,w]:edge[u]){
            if(dist[s][v]>d+w){
                dist[s][v]=d+w;
                q.push({-dist[s][v],v});
            }
        }
    }
}

void Johnson(){
    for(int i=1;i<=n;i++){
        edge[0].push_back({i,0});
    }
    if(SPFA(0)){
        cout<<-1;
        return;
    }
    dist.assign(n+1,vector<int>(n+1,INF));
    for(int u=1;u<=n;u++){
        for(auto &[v,w]:edge[u]){
            w=w+h[u]-h[v];      //dist[v]<=dist[u]+w边权转化
        }
    }
    for(int i=1;i<=n;i++)Dijkstra(i);
    for(int i=1;i<=n;i++){
        int res=0;
        for(int j=1;j<=n;j++){
            if(dist[i][j]!=INF)dist[i][j]=dist[i][j]-h[i]+h[j];
            res+=j*dist[i][j];
        }
        cout<<res<<'\n';
    }
}
```

## 最小生成树Kruskal
```cpp
struct Edge{
    int u,v,w;
    bool operator<(const Edge&other)const{
        return w<other.w;
    }
};
int n,m;
vector<Edge>edge;
vector<int>F;

int Find(int x){
    if(F[x]==x)return x;
    return F[x]=Find(F[x]);
}

void Unite(int x,int f){
    F[Find(x)]=Find(f);
}

void Kruskal(){
    int cnt=1,res=0;
    iota(begin(F),end(F),0);
    sort(begin(edge),end(edge));
    for(auto &[u,v,w]:edge){
        if(Find(u)==Find(v))continue;
        Unite(u,v);
        cnt++;
        res+=w;
    }
    if(cnt<n){
        cout<<"orz";
        return;
    }
    cout<<res;
}
```

## 最小生成树Prim
```cpp
struct Edge{
    int v,w;
};
int n,m;
vector<vector<Edge>>edge;

void Prim(){
    priority_queue<pair<int,int>>q;
    vector<bool>vis(n+1,0);
    int cnt=0,res=0;
    q.push({0,1});
    while(!q.empty()){
        auto [d,u]=q.top();
        q.pop();
        d=-d;
        if(vis[u])continue;
        vis[u]=1;
        res+=d;
        cnt++;
        for(auto [v,w]:edge[u]){
            if(vis[v])continue;
            q.push({-w,v});
        }
    }
    if(cnt<n){
        cout<<"orz";
    }
    else cout<<res;
}
```

## 强连通分量SCC
```cpp
struct SCC{
    int n,timer,sccCnt;
    vector<vector<int>>g,dag;
    vector<int>dfn,low,stk,inStk,belong;
    vector<int>indeg,outdeg;
    SCC(int n):n(n),g(n+1),dfn(n+1),low(n+1),inStk(n+1),belong(n+1,-1){}
    
    void addEdge(int u,int v){g[u].push_back(v);}//有向图
    void dfs(int u){
        dfn[u]=low[u]=++timer;
        stk.push_back(u);
        inStk[u]=1;
        for(auto v:g[u]){
            if(!dfn[v]){
                dfs(v);
                low[u]=min(low[u],low[v]);
            }
            else if(inStk[v]){
                low[u]=min(low[u],dfn[v]);
            }
        }
        if(low[u]==dfn[u]){
            while(1){
                int x=stk.back();
                stk.pop_back();
                inStk[x]=0;
                belong[x]=sccCnt;
                if(x==u)break;
            }
            sccCnt++;
        }
    }
    int run(){//返回scc数量，scc标号为[0,sccCnt)
        timer=sccCnt=0;
        for(int i=1;i<=n;i++)if(!dfn[i])dfs(i);
        return sccCnt;
    }
    void buildDAG(){//这一部分下标都是[0,sccCnt)
        dag.assign(sccCnt,{});
        indeg.assign(sccCnt,0);
        outdeg.assign(sccCnt,0);
        for(int u=1;u<=n;u++){
            for(int v:g[u]){
                int a=belong[u],b=belong[v];
                if(a!=b){
                    dag[a].push_back(b);
                    indeg[b]++;
                    outdeg[a]++;
                }
            }
        }
    }
};
```

## 边双连通分量EDCC
```cpp
struct EDCC{
    struct Edge{int to,id;};
    int n,timer,dccCnt,edgeCnt;
    vector<vector<Edge>>g;
    vector<pair<int,int>>edges;
    vector<int>dfn,low,belong,bridge;
    vector<vector<int>>tree;
    EDCC(int n):n(n),g(n+1),dfn(n+1),low(n+1),belong(n+1,-1){}

    void addEdge(int u,int v){//无向图
        g[u].push_back({v,edgeCnt});
        g[v].push_back({u,edgeCnt});
        edges.push_back({u,v});
        edgeCnt++;
    }

    void dfs(int u,int peid){
        dfn[u]=low[u]=++timer;
        for(auto &e:g[u]){
            int v=e.to,id=e.id;
            if(id==peid)continue;//跳过反向边/父边
            if(!dfn[v]){
                dfs(v,id);
                low[u]=min(low[u],low[v]);
                if(low[v]>dfn[u])bridge[id]=1;
            }
            else{
                low[u]=min(low[u],dfn[v]);
            }
        }
    }

    void flood(int u,int c){
        belong[u]=c;
        for(auto &e:g[u]){
            if(!bridge[e.id]&&belong[e.to]==-1)flood(e.to,c);
        }
    }

    int run(){
        bridge.assign(edgeCnt,0);
        for(int i=1;i<=n;i++)if(!dfn[i])dfs(i,-1);
        dccCnt=0;
        for(int i=1;i<=n;i++)if(belong[i]==-1)flood(i,dccCnt++);
        return dccCnt;
    }

    void buildTree(){
        tree.assign(dccCnt,{});
        for(int id=0;id<edgeCnt;id++){
            if(!bridge[id])continue;
            int a=belong[edges[id].first];
            int b=belong[edges[id].second];
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
    }
};
```

## 最大流Dinic
```cpp
struct DinicMaxFlow{
    struct Edge{
        int to,cap,rev;
    };
    int N,S,T;
    const int INF=2e18;
    vector<vector<Edge>>e;
    vector<int>cur,level;

    DinicMaxFlow(int n,int s,int t):N(n),S(s),T(t){
        e.assign(n+1,{});
        cur.assign(n+1,0);
        level.assign(n+1,0);
    }

    void add_edge(int u,int v,int cap){
        e[u].push_back({v,cap,(int)e[v].size()});
        e[v].push_back({u,0,(int)e[u].size()-1});
    }

    bool BFS(){
        fill(begin(level),end(level),0);    //分层图
        fill(begin(cur),end(cur),0);        //重置当前弧
        queue<int>q;
        level[S]=1;
        q.push(S);
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(auto [v,c,r]:e[u])
            {
                if(level[v]||c==0)continue;
                level[v]=level[u]+1;
                q.push(v);
            }
        }
        return level[T];
    }

    int DFS(int u,int f){
        if(u==T||f==0)return f;
        int ret=0;                                  //多路增广
        for(int &i=cur[u];i<(int)e[u].size();i++){  //&i=cur[u],当前弧优化
            auto &[v,c,r]=e[u][i];
            if(c==0||level[v]!=level[u]+1)continue;
            int tf=DFS(v,min(f-ret,c));
            if(tf==0)continue;
            c-=tf;
            e[v][r].cap+=tf;
            ret+=tf;
            if(f==ret)break;
        }
        return ret;
    }

    int MaxFlow(){
        int res=0;
        while(BFS())res+=DFS(S,INF);
        return res;
    }
};
```

## 最小费用最大流MCMF
```cpp
struct MCMF{
    struct Edge{
        int to,cap,cost,rev;
    };
    
    int N,S,T,MC,MF;
    const int INF=2e18;
    vector<vector<Edge>>e;
    vector<int>cur,dist,vis;

    MCMF(int n,int s,int t):N(n),S(s),T(t),MC(0),MF(0){
        e.assign(n+1,vector<Edge>());
        cur.assign(n+1,0);
        dist.assign(n+1,0);
        vis.assign(n+1,0);
    }

    void add_edge(int u,int v,int cap,int cost){
        e[u].push_back({v,cap,cost,(int)e[v].size()});
        e[v].push_back({u,0,-cost,(int)e[u].size()-1});
    }

    bool SPFA(){
        fill(begin(dist),end(dist),INF);
        fill(begin(vis),end(vis),0);
        fill(begin(cur),end(cur),0);        //重置当前弧
        queue<int>q;
        dist[S]=0;
        vis[S]=1;
        q.push(S);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            vis[u]=0;
            if(dist[u]==INF)continue;
            for(auto [v,c,m,r]:e[u]){
                if(c&&dist[u]+m<dist[v]){
                    dist[v]=dist[u]+m;
                    if(!vis[v]){
                        vis[v]=1;
                        q.push(v);
                    }
                }
            }
        }
        return dist[T]!=INF;
    }

    int DFS(int u,int f){
        if(u==T||f==0)return f;
        vis[u]=1;               //防止出现0费用环
        int ret=0;
        for(int &i=cur[u];i<(int)e[u].size();i++){
            auto &[v,c,m,r]=e[u][i];
            if(vis[v]||c==0||dist[v]!=dist[u]+m)continue;
            int tf=DFS(v,min(f-ret,c));
            if(tf==0)continue;
            c-=tf;
            e[v][r].cap+=tf;
            ret+=tf;
            MC+=tf*m;
            if(f==ret)break;
        }
        vis[u]=0;
        return ret;
    }

    void mcmf(){
        while(SPFA())MF+=DFS(S,INF);
    }
};
```

## 计算几何
```cpp
const long double eps=1e-10;
const long double PI=acos(-1.0);

typedef double T;
int sgn(T x){
    if(fabs(x)<eps)return 0;
    return x>0?1:-1;
}
struct PT{
    T x,y;
    PT(){}
    PT(T _x,T _y):x(_x),y(_y){}

    PT operator+(const PT& b)const{return PT(x+b.x,y+b.y);}
    PT operator-(const PT& b)const{return PT(x-b.x,y-b.y);}
    PT operator*(const T& n)const{return PT(x*n,y*n);}
    PT operator/(const T& n)const{return PT(x/n,y/n);}
    bool operator==(const PT& b)const{return sgn(x-b.x)==0&&sgn(y-b.y)==0;}
    bool operator!=(const PT& b)const{return !(*this==b);}
    bool operator<(const PT& b)const{return (sgn(x-b.x)==0?(sgn(y-b.y)<0):(sgn(x-b.x)<0));}
};
ostream& operator<<(ostream& os,PT a){return os<<'('<<a.x<<','<<a.y<<')';}

struct Line{
    PT s,t;
    Line(){}
    Line(PT _s,PT _t):s(_s),t(_t){}
};

T dot(PT a,PT b){return a.x*b.x+a.y*b.y;}       //点积
T cross(PT a,PT b){return a.x*b.y-a.y*b.x;}     //叉积
T vabs(PT a){return sqrt(dot(a,a));}            //模长
T dist(PT a,PT b){return vabs(a-b);}            //两点距离

PT rot(PT a,T rad){                              //逆时针旋转rad角
    return PT(a.x*cos(rad)-a.y*sin(rad),a.x*sin(rad)+a.y*cos(rad));
}

PT normal(PT a){                                 //逆时针的单位法向量
    if(vabs(a)<eps)return PT(0,0);
    return PT(-a.y,a.x)/vabs(a);
}

T angle(PT a,PT b){                              //向量夹角
    return abs(atan2(cross(a,b),dot(a,b)));
}

T orientedAngle(PT A,PT B,PT C){                 //定向角(逆时针)
    T ang=atan2(cross(B-A,C-A),dot(B-A,C-A));
    return ang+(ang<0)*2*PI;
}

T orient(PT A,PT B,PT C){                        //ABC的有向面积,逆时针为正(+)
    return cross(B-A,C-A)/2.0;
}

bool is_inAngle(PT A,PT B,PT C,PT p){            //判断p点是否在射线AB和AC之间(含边界)
    T s=sgn(orient(A,B,C));
    if(s<0)swap(B,C);
    else if(s==0)
    {
        if(sgn(dot(B-A,C-A))>0)                 //特判ABC共线，同向则p也同向才满足
        {
            return sgn(cross(B-A,p-A))==0&&sgn(dot(B-A,p-A))>=0;
        }
        else return sgn(cross(B-A,p-A))>=0;     //若反向则全满足
    }
    return sgn(orient(A,B,p))>=0&&sgn(orient(A,C,p))<=0;
}

bool is_onLine(PT p,Line l){                 //点p是否在直线ab上
    auto [s,t]=l;
    return sgn(cross(p-s,p-t))==0;
}
bool is_lineInter(Line l1,Line l2){          //直线l1和l2是否相交
    auto [s1,t1]=l1;
    auto [s2,t2]=l2;
    if(sgn(cross(t1-s1,t2-s2))==0)
    {
        if(is_onLine(s1,l2))return 1;
        return 0;
    }
    return 1;
}

bool is_onSeg(PT p,Line l){                  //点p是否在线段ab上(含端点)
    auto [s,t]=l;
    return sgn(cross(p-s,p-t))==0&&sgn(dot(p-s,p-t))<=0;
}
bool is_onTwoSide(PT A,PT B,Line l){         //点AB是否在直线l两侧(不包含点在直线上)
    auto [s,t]=l;
    return sgn(cross(A-s,t-s))*sgn(cross(B-s,t-s))<0;
}
bool is_segInter(Line l1,Line l2){           //线段l1和l2是否相交(含端点)
    auto [s1,t1]=l1;
    auto [s2,t2]=l2;
    if(is_onSeg(s1,l2)||is_onSeg(t1,l2)||is_onSeg(s2,l1)||is_onSeg(t2,l1)){
        return 1;
    }
    return is_onTwoSide(s1,t1,l2)&&is_onTwoSide(s2,t2,l1);
}

bool polar_cmp(PT a,PT b){                   //极角排序(以原点为基准)
    int f1=(a.y>0||a.y==0&&a.x>0)?0:1;
    int f2=(b.y>0||b.y==0&&b.x>0)?0:1;
    if(f1!=f2)return f1<f2;
    int s=sgn(cross(a,b));
    if(s!=0)return s>0;
    return dot(a,a)<dot(b,b);//这里用平方判长度
}

bool is_onRight(PT p,Line l){
    auto [s,t]=l;
    return sgn(cross(t-s,p-s))>=0;
}
vector<PT>getConvex(vector<PT>p){      //返回逆时针严格凸包，已去重
    sort(p.begin(),p.end());
    p.erase(unique(p.begin(),p.end()),p.end());
    if(p.size()<=2)return p;
    vector<PT>h;
    for(int t=0;t<2;t++){
        size_t sz=h.size();
        for(PT q:p){
            while(h.size()-sz>=2&&sgn(cross(h.back()-h[h.size()-2],q-h.back()))<=0)h.pop_back();
            h.push_back(q);
        }
        h.pop_back();
        reverse(p.begin(),p.end());
    }
    return h;
}

T RotateJam(vector<PT>&h){
    //h为凸包
    int n=h.size();
    if(n==1)return 0;//只有2点的情况
    if(n==2)return dist(h[0],h[1]);
    T ans=0;//初始化
    int j=1;
    for(int i=0;i<n;i++){
        PT a=h[i],b=h[(i+1)%n];
        while(sgn(cross(b-a,h[(j+1)%n]-a)-cross(b-a,h[j]-a))>0){
            j=(j+1)%n;
        }
        //处理答案
        ans=max(ans,dist(a,h[j]));
        ans=max(ans,dist(b,h[j]));
    }
    return ans;
}
```