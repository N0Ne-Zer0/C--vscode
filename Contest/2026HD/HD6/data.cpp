#include <bits/stdc++.h>
using namespace std;
#define int long long

// 使用当前时间作为随机数种子
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());

// 生成 [l, r] 范围内的随机整数
long long random(long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rnd);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // 这里以生成一个数组为例
    int x=random(0,15);
    int y=random(0,15);
    cout<<x<<' '<<y<<'\n';
}