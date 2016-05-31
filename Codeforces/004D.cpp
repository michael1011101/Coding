#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
using namespace std;

/*
    此题类似最长上升子序列
    首先对信封进行从小到大的排列
    然后，判断信封是否可以包含卡片，如果可以，那么判断可以包含之前数量最多的信封队列，并且记录用p记录前一个的坐标
    最后判断最大值，然后输出该队列
*/

const int maxn = 5010;
struct node{
    int w,h;
    int index;          //注意用一个int来维护原来的坐标位置
};
node envelope[maxn];
int n,w,h;
int dp[maxn], pre[maxn];

bool cmp(node a, node b){
    if(a.w == b.w)
        return a.h < b.h;
    return a.w < b.w;
}

void RUN(){
    int i,j;
    sort(envelope+1, envelope+1+n, cmp);
    memset(dp, 0, sizeof(dp));
    for(i=0; i<=n; ++i) pre[i]=-1;

    int num, p;
    for(i=1; i<=n; ++i){
        if(envelope[i].w>w && envelope[i].h>h){
            num=0; p=0;
            for(j=i-1; j>0; --j){
                if(envelope[i].w>envelope[j].w && envelope[i].h>envelope[j].h){
                    if(num < dp[j]){
                        num = dp[j];
                        p = j;
                    }
                }
            }
            dp[i] = num+1;
            pre[i] = p;
        }
    }
    num = -1;
    for(i=1; i<=n; ++i){
        if(num < dp[i]){
            num = dp[i];
            p = i;
        }
    }
    stack<int> st;
    while(pre[p] != -1){
        st.push(envelope[p].index);
        p = pre[p];
    }
    printf("%d\n", num);
    while(!st.empty()){
        printf("%d ", st.top());
        st.pop();
    }
}

void READ(){
    scanf("%d%d%d", &n, &w, &h);
    int i;
    for(i=1; i<=n; ++i){
        scanf("%d%d", &envelope[i].w, &envelope[i].h);
        envelope[i].index = i;
    }
}

int main(){
    READ();
    RUN();
    return 0;
}