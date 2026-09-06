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

void sol(){
    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    T = 1;
    cin>>T;
    while (T--)sol();
    // system("pause");
}