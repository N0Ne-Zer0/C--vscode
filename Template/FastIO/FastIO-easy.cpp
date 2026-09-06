#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long

const int maxn=3e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=998244353;
const int INF=1e9;

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

void sol(){
    int a;
    read(a);
    write(a);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    T=1;
    read(T);
    while (T--)sol();
}