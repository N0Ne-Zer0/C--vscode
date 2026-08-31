#include<iostream>
#include<cstdio>
#include<cctype>
#include<string>
using namespace std;
#define int long long

const int maxn=3e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=998244353;
const int INF=1e9;

namespace FastIO
{
    static char ibuf[1<<20],*ip1=ibuf,*ip2=ibuf;
    inline char gc()
    {
        if(ip1==ip2)
        {
            ip2=(ip1=ibuf)+fread(ibuf,1,sizeof(ibuf),stdin);
            if(ip1==ip2)return EOF;
        }
        return *ip1++;
    }
    static char obuf[1<<20],*op=obuf;
    inline void flush(){fwrite(obuf,1,op-obuf,stdout);op=obuf;}
    inline void pc(char c)
    {
        if(op==obuf+sizeof(obuf))flush();
        *op++=c;
    }
    template<typename T>
    inline bool read(T &x)
    {
        x=0;
        char c=gc();
        bool neg=false;
        while(!isdigit(c))
        {
            if(c=='-')neg=true;
            else if(c==EOF)return false;
            c=gc();
        }
        x=0;
        while(isdigit(c))
        {
            x=(x<<3)+(x<<1)+c-48;
            c=gc();
        }
        if(neg)x=-x;
        return true;
    }
    template<typename T>
    inline void write(T x)
    {
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

void sol()
{

}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    T = 1;
    read(T);
    while (T--)sol();
    flushOut();
}