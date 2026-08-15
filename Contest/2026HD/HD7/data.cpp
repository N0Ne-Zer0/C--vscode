#include <bits/stdc++.h>
using namespace std;
#define int long long

// 使用当前时间作为随机数种子
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());

// 生成 [l, r] 范围内的随机整数
int random(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rnd);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // 这里以生成一个数组为例
    int n=random(2,100);
    int w=random(0,1000);
    cout<<n<<' '<<w<<'\n';
    for(int i=1;i<n;i++)
    {
        int x=random(0,1000);
        if(x%3==0)cout<<'&';
        else if(x%3==1)cout<<'^';
        else cout<<'|';
    }
    cout<<'\n';
    // system("pause");
}