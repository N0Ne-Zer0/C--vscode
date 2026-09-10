#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=5e5+5;
const int MAX=0x7fffffffffffffff;
const int mod=998244353;
const int INF=1e9;

vector<int> getZ(const string&s){
    int n=s.size();
    vector<int>z(n);
    for(int i=1,l=0,r=0;i<n;i++){
        if(i<=r)z[i]=min(r-i+1,z[i-l]);
        while(i+z[i]<n&&s[z[i]]==s[i+z[i]])z[i]++;
        if(i+z[i]-1>r)l=i,r=i+z[i]-1;
    }
    return z;
}

vector<int> zMatch(const string&t,const string&p){
    string s=p+'#'+t;
    vector<int>z=getZ(s);
    vector<int>res;
    int m=p.size();
    for(int i=m+1;i<(int)s.size();i++){
        if(z[i]==m)res.push_back(i-m-1);
    }
    return res;
}


signed main(){
    
}