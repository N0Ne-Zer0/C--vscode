#include<iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

struct DSU {
    vector<int> fa, sz;
    int cnt;

    DSU(int n):fa(n+1),sz(n+1,1),cnt(n)
    {
        iota(fa.begin(),fa.end(),0);//numeric头文件
    }
    int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}//路径压缩查找
    bool merge(int a,int b)
    {
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


void sol()
{
    
}

signed main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int T;
    T = 1;
    cin>>T;
    while (T--)sol();
    system("pause");
}