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