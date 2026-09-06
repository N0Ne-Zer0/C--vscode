#include<queue>
#include<vector>
using namespace std;

vector<int>slidingWindow(const vector<int>&a,int k){//窗口长度为k
    int n=a.size();
    vector<int>res;
    res.reserve(n-k+1);
    deque<int>dq;
    for(int i=0;i<n;i++){
        //>=为最小值，若要最大值则改为<=
        while(!dq.empty()&&a[dq.back()]>=a[i])dq.pop_back();
        dq.push_back(i);//存入的是下标
        if(dq.front()<=i-k)dq.pop_front();
        if(i>=k-1)res.push_back(a[dq.front()]);//记录窗口的最小值
    }
    return res;
}

signed main(){

}